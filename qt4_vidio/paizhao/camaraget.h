#ifndef CAMARAGET_H
#define CAMARAGET_H

#include <QWidget>
#include <QImage>
#include <QTimer>     // 设置采集数据的间隔时间
#include<QtNetwork>
#include<QTcpServer>
#include<QTcpSocket>
#include<QtGui>


#include <highgui.h>  //包含opencv库头文件
#include <cv.h>
#include<camthread.h>
using namespace cv;
namespace Ui {
    class camaraGet;
}

class camaraGet : public QWidget
{
    Q_OBJECT

public:
    explicit camaraGet(QWidget *parent = 0);
    ~camaraGet();

private slots:
    void openCamara();      // 打开摄像头
    void readFarme(QImage );       // 读取当前帧信息
    void closeCamara();     // 关闭摄像头。
    void takingPictures();  // 拍照
    //void warn();
    void openvideo();
    void readFarme();
    void readMessage();

    void on_connect_clicked();

private:
    Ui::camaraGet *ui;

    Camthread *camthread;
    QTimer    *timer;
    VideoCapture cap;
    bool video;
    int op;
    QImage    image;

    QTcpSocket* tcpSocket; //创建tcpsocket
    quint16 blockSize;       //存放文件的大小信息
    QString message;

};

#endif // CAMARAGET_H
