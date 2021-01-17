#include <QCoreApplication>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
       Mat  img = imread("C:/Users/Administrator/Pictures/1.jpg");
       if(img.empty())
       {
           fprintf(stderr,"Error: load image failed.");
           return -1;
       }
       namedWindow("image",CV_WINDOW_AUTOSIZE);
       imshow("image",img);
       waitKey();
       return 0;

}
