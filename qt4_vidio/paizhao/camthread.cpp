#include"camthread.h"
#include<QtGui>


Camthread::Camthread()
{
    cam     = NULL;
    timer   = new QTimer(this);

}

Camthread::~Camthread()
{
    timer->stop();         // 停止读取数据。
    cvReleaseCapture(&cam);//释放内存；
    cvReleaseVideoWriter(&writer);

}
void Camthread::startPlay()
{

    cam = cvCreateCameraCapture(0);//打开摄像头，从摄像头中获取视频
    if(!cam)
    {

        emit sig_err("error");
        //return;
          //QMessageBox::warning(,"Warning","Cameras are not found.");

    }
    else
    {
        timer->start(50);              // 开始计时，超时则发出timeout()信号
        start();
    }
}
void Camthread::run()
{
    // 时间到，读取当前摄像头信息
    double fps=30;
    frame = cvQueryFrame(cam);
    CvSize size=cvGetSize(frame);
    writer=cvCreateVideoWriter("Video from CAMERA.avi",CV_FOURCC('X','V','I','D'),
                                              fps,size,1);
    connect(timer, SIGNAL(timeout()), this, SLOT(readFrame()));

}
void Camthread::readFrame( )
{
    frame = cvQueryFrame(cam);// 从摄像头中抓取并返回每一帧
    QImage image = QImage((const uchar*)frame->imageData, frame->width, frame->height,
                          QImage::Format_RGB888).rgbSwapped();


        //dst=cvCreateImage(size,image->depth,1);


        //image = cvQueryFrame( capture ); //ÏÈ²¶»ñÒ»Ö¡
        //CvVideoWriter* writer = 0; //±£ŽæŸÍŒÓÉÏÕâŸä


        //cvNamedWindow("haha",1);
       // while(frame!=NULL)
      //  {
            //printf("Enteredn");
            cvWriteFrame(writer,frame);
            //cvCvtColor(image,dst,CV_RGB2GRAY);
            //cvShowImage("haha",image);

            //if((cvWaitKey(100))==27)
            //    break;

     //   }
     //
    emit sig_GetOneFrame(image);

}
