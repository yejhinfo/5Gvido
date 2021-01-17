#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include<QTcpSocket>
#include<QTcpServer>
#include<QString>
#include<QtNetwork>
#include<QMessageBox>
#include<QImage>

namespace Ui {
class Server;
}

class Server : public QWidget
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = 0);
    ~Server();

    QTcpServer *tcpServer;
    QTcpSocket *tcpServerConnection;
    QStringList *fortunes;
    QImage *img;
    quint64 basize;

public slots:
    void sendFortune();

   // QByteArray GetPicData(QString fromPic);
    void DisplayError(QAbstractSocket::SocketError socketError);
    void ReadMyData();

    void ShowImage(QByteArray ba);


private:
    Ui::Server *ui;
};

#endif // SERVER_H
