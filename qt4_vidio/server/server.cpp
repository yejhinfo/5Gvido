#include "server.h"
#include "ui_server.h"
/*
1.创建tcpServer ，tcpServer = new QTcpServer(this);使之监听本机的某个端口，tcpServer->listen(QHostAddress("192.168.1.100"),6666)
2,关联信号newConnection和槽函数sendMessage， connect(tcpServer,SIGNAL(newConnection()),this,SLOT(sendMessage()));其中信号newConnection在有客户端的连接请求（即客户端执行tcpSocket->connectToHost）时发射
3.实现槽函数sendMessage，在里面从tcpServer取得已经建立但挂起的QTcpSocket连接
QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
用clientConnection 传输数据给客户
 QByteArray block;
 clientConnection->write(block);
*/
Server::Server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    ui->image_label->setScaledContents(true);
    tcpServer = new QTcpServer(this);
    if(!tcpServer->listen(QHostAddress::Any,8080))
    {
        QMessageBox::critical(this,tr("Fortune Server"),tr("Unable to start the server:%l.").arg(tcpServer->errorString()));
        close();
        return;
    }

    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(sendFortune()));
}
Server::~Server()
{
    delete ui;
}
void Server::sendFortune()
{
    basize=0;

    tcpServerConnection = tcpServer->nextPendingConnection();
    QByteArray message;
    QDataStream out(&message,QIODevice::WriteOnly);
    //out.setVersion(QDataStream::Qt_4_6);
    out<<(quint16) 0;
    out<<tr("OK");//当有连接时则发送一个OK信号给客户端，通知其发送数据

    out.device()->seek(0); //定位到第一个16位， 是写入的数据的大小
    out<<(quint16)(message.size()-sizeof(quint16));


    //connect(tcpServerConnection,SIGNAL(disconnected()),
    //        tcpServerConnection,SLOT(deleteLater()));
    tcpServerConnection->write(message); //写入发送的数据

    connect(tcpServerConnection,SIGNAL(readyRead()),
            this,SLOT(ReadMyData()));//当有数据到来时，读取图像数据
    connect(tcpServerConnection,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(DisplayError(QAbstractSocket::SocketError)));

}
/*
QByteArray Server::GetPicData(QString fromPic)
{
    QImage img(fromPic);
    QByteArray block;
    QBuffer buf(&block);
    img.save(&buf,"JPEG");//按照JPG解码保存数据
    QByteArray cc = qCompress(block,1);
    QByteArray hh;
    hh=cc.toBase64();//base64数据
    return hh;
}*/
void Server::DisplayError(QAbstractSocket::SocketError socketError)
{
    tcpServerConnection->close();
}
void Server::ReadMyData()
{
    QByteArray message;//存放从服务器接收到的字符串
    QDataStream in(tcpServerConnection);
    in.setVersion(QDataStream::Qt_4_6);
    if (basize==0)
    {
        //判断接收的数据是否有两字节（文件大小信息）
        //如果有则保存到basize变量中，没有则返回，继续接收数据
        if (tcpServerConnection->bytesAvailable()<(int)sizeof(quint64))
        {
            return;
        }
        in>>basize;
    }
    //如果没有得到全部数据，则返回继续接收数据
    if (tcpServerConnection->bytesAvailable()<basize)
    {
        return;
    }
    in>>message;//将接收到的数据存放到变量中
    ShowImage(message);
}

void Server::ShowImage(QByteArray ba)
{
    QString ss=QString::fromLatin1(ba.data(),ba.size());
    QByteArray rc;
    rc=QByteArray::fromBase64(ss.toLatin1());
    QByteArray rdc=qUncompress(rc);
    QImage img;
    img.loadFromData(rdc);
    ui->image_label->setPixmap(QPixmap::fromImage(img));
    ui->image_label->resize(img.size());
    update();
}
