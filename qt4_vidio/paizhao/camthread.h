#ifndef CAMTHREAD_H
#define CAMTHREAD_H

#include<QThread>
#include <QTimer>     // 设置采集数据的间隔时间
#include <highgui.h>  //包含opencv库头文件
#include <cv.h>
#include <QImage>

class Camthread:public QThread
{
    Q_OBJECT
public:
    explicit Camthread();
    ~Camthread();

    void startPlay();

  signals:
      void sig_GetOneFrame(QImage); //每获取到一帧图像 就发送此信号
      void sig_err(QString); //每获取到一帧图像 就发送此信号

  private:
      void run();
    CvVideoWriter* writer;
      QTimer    *timer;
      CvCapture *cam;// 视频获取结构， 用来作为视频获取函数的一个参数
      IplImage  *frame;//申请IplImage类型指针，就是申请内存空间来存放每一帧图像
private slots:
      void readFrame( );       // 读取当前帧信息

};

#endif // CAMTHREAD_H
