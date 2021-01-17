#include "camaraget.h"
#include "ui_camaraGet.h"

camaraGet::camaraGet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::camaraGet)
{
    ui->setupUi(this);
    op=0;
    ui->label->setScaledContents(true);
    ui->label_2->setScaledContents(true);
    video=0;
    timer=new QTimer();
    camthread=new Camthread();
    tcpSocket=new QTcpSocket();
    /*信号和槽*/
    //message=QString("OK");
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(camthread,SIGNAL(sig_GetOneFrame(QImage)),this,SLOT(readFarme(QImage )));
    //connect(timer, SIGNAL(timeout()), this, SLOT(readFarme()));  // 时间到，读取当前摄像头信息
    connect(ui->open, SIGNAL(clicked()), this, SLOT(openCamara()));
    connect(ui->pic, SIGNAL(clicked()), this, SLOT(takingPictures()));
    connect(ui->closeCam, SIGNAL(clicked()), this, SLOT(closeCamara()));
  //  connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,
  //          SLOT(displayError(QAbstractSocket::SocketError)));

}


void camaraGet::openCamara()
{

    if(op==1)
    {
        return ;
    }
    connect(camthread,SIGNAL(sig_err(QString)),this,SLOT( openvideo()));
    camthread->startPlay();
    op=1;
}

void camaraGet::openvideo()
{
    op=0;
    QMessageBox::warning(this,"Warning","Cameras are not found.");
    //connect(ui->open, SIGNAL(clicked()), this, SLOT(openvideo()));
    QString filename = QFileDialog::getOpenFileName(this,tr("action"),
                       "./",
                        "Image file(*.AVI *.MP4)",0) ;
    if (!filename.isEmpty())
    {
        cap.open(filename.toLatin1().data());
     }
    if(!cap.isOpened()){
        QMessageBox::information(this,tr("提示"),tr("视频没有打开"));
        video=0;
    }
    else
       video=1;

    timer->start(50);
    connect(timer, SIGNAL(timeout()), this, SLOT(readFarme()));
    connect(ui->open, SIGNAL(clicked()), this, SLOT(openCamara()));
    connect(ui->pic, SIGNAL(clicked()), this, SLOT(takingPictures()));
    connect(ui->closeCam, SIGNAL(clicked()), this, SLOT(closeCamara()));
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
}

void camaraGet::readMessage()
{
     qDebug()<<4;
     qDebug() << message;
    QDataStream in(tcpSocket);
     //in.setVersion(QDataStream::Qt_4_6);
     if (blockSize == 0) {
            //判断接收的数据是否大于两字节，也就是文件的大小信息所占的空间
            //如果是则保存到blockSize变量中，否则直接返回，继续接收数据
            if(tcpSocket->bytesAvailable() < (int)sizeof(quint16)) return;  //bytesAvailable()返回字节数
            in >> blockSize;
        }
     if(tcpSocket->bytesAvailable() < blockSize) return;
        // 将接收到的数据存放到变量中
         in >> message;
         // 显示接收到的数据*/
        // qDebug() << message;

}

void camaraGet::readFarme()
{
    blockSize=0;//数据大小初始化为0
    tcpSocket->abort();//取消已有链接
    //连接到某个ip的某个端口，ip+port
    //tcpSocket->connectToHost(QHostAddress::Any,8888);
   // tcpSocket->connectToHost("103.46.128.45",22783);
    if(video)
    {
        qDebug()<<"baofang shipin !";
        Mat frame;
        //cap>>frame;
        if(cap.read(frame))
       {
            cvtColor(frame,frame,CV_BGR2RGB);
            QImage image1((unsigned const char*)frame.data,
                     frame.cols,frame.rows,QImage::Format_RGB888);
            if(message=="OK")
            {
                QByteArray ba; //用于暂存要发送的数据
                QDataStream out(&ba,QIODevice::WriteOnly); //使用数据流写入数据
            //out.setVersion(QDataStream::Qt_4_6);
                //设置数据流的版本，客户端和服务器端使用的版本要相同
                QByteArray byte;
                QBuffer buf(&byte);
                image1.save(&buf,"JPEG");
                QByteArray ss=qCompress(byte,1);
                QByteArray vv=ss.toBase64();
                out<<(quint64)0;
                out<<vv;
                out.device()->seek(0);
                out<<(quint64)(ba.size()-sizeof(quint64));
            //发送数据
                tcpSocket->write(ba);
            }
            else ;
           // tcpSocket->disconnectFromHost();
            if(op==1)
            ui->label->setPixmap(QPixmap::fromImage(image1));  // 将图片显示到label上
        }
        else
        {
            timer->stop();
            op=0;
        }
    }
}
void camaraGet::readFarme(QImage img)
{
    blockSize=0;//数据大小初始化为0
    tcpSocket->abort();//取消已有链接
    //连接到某个ip的某个端口，
   // tcpSocket->connectToHost(QHostAddress("103.46.128.45"),22783);
    tcpSocket->connectToHost(QHostAddress("192.168.0.112"),8080);
    image=img;
    //qDebug()<<"tcp";
    if(message=="OK")
    {
        QByteArray ba; //用于暂存要发送的数据
        QDataStream out(&ba,QIODevice::WriteOnly); //使用数据流写入数据
    //out.setVersion(QDataStream::Qt_4_6);
        //设置数据流的版本，客户端和服务器端使用的版本要相同
        QByteArray byte;
        QBuffer buf(&byte);
        image.save(&buf,"JPEG");
        QByteArray ss=qCompress(byte,1);
        QByteArray vv=ss.toBase64();
        out<<(quint64)0;
        out<<vv;
        out.device()->seek(0);
        out<<(quint64)(ba.size()-sizeof(quint64));
    //发送数据
        tcpSocket->write(ba);
    }
    else ;
    if(op==1)
    {
        ui->label->setPixmap(QPixmap::fromImage(image));  // 将图片显示到label上
    }
}
void camaraGet::takingPictures()
{
    //frame = cvQueryFrame(cam);// 从摄像头中抓取并返回每一帧
    // 将抓取到的帧，转换为QImage格式。QImage::Format_RGB888不同的摄像头用不同的格式。
    //QImage image((const uchar*)frame->imageData, frame->width, frame->height, QImage::Format_RGB888);
    //QImage image = QImage((const uchar*)frame->imageData, frame->width, frame->height, QImage::Format_RGB888).rgbSwapped();
    // frame=cvLoadImage((filename.toLatin1()).data());
    //ui->CameraLabel->setPixmap(QPixmap::fromImage(image));
    op=0;
    QString filename = QFileDialog::getSaveFileName(this,tr("action"),
                       "./",
                        "Image file(*.bmp *.jpg)",0) ;
    if (!filename.isEmpty())
            if(!image.save(filename))
              QMessageBox::information(this,
                          tr("Warnning"),
                          tr("Failed to save the image!"));
    op=1;
    ui->label_2->setPixmap(QPixmap::fromImage(image));  // 将图片显示到label上

}

void camaraGet::closeCamara()
{
    ui->label_2->clear();
    //this->close();
}

camaraGet::~camaraGet()
{
    delete ui;
}


void camaraGet::on_connect_clicked()
{
    //获取服务器ip端口
    QString ip = ui->lineEditip->text();
    qint16 port = ui->lineEditPort->text().toInt();

    tcpSocket->connectToHost(QHostAddress(ip),port);
}
