#-------------------------------------------------
#
# Project created by QtCreator 2016-04-27T11:16:54
#
#-------------------------------------------------

QT       += core gui
QT+=network

TARGET = paizhao
TEMPLATE = app


SOURCES += main.cpp \
    camaraget.cpp \
    camthread.cpp

HEADERS  += \
    camaraget.h \
    camthread.h

FORMS    += \
    camaraGet.ui
INCLUDEPATH+=E:\opencv2.4\opencv\build\include\opencv\
             E:\opencv2.4\opencv\build\include\opencv2\
             E:\opencv2.4\opencv\build\include



LIBS+=E:\cmake_opencv2\lib\libopencv_calib3d2411.dll.a\
        E:\cmake_opencv2\lib\libopencv_contrib2411.dll.a\
        E:\cmake_opencv2\lib\libopencv_core2411.dll.a\
        E:\cmake_opencv2\lib\libopencv_features2d2411.dll.a\
        E:\cmake_opencv2\lib\libopencv_flann2411.dll.a\
        E:\cmake_opencv2\lib\libopencv_gpu2411.dll.a\
        E:\cmake_opencv2\lib\libopencv_highgui2411.dll.a\
        E:\cmake_opencv2\lib\libopencv_imgproc2411.dll.a\
        E:\cmake_opencv2\lib\libopencv_legacy2411.dll.a\
        E:\cmake_opencv2\lib\libopencv_ml2411.dll.a\
        E:\cmake_opencv2\lib\libopencv_objdetect2411.dll.a\
        E:\cmake_opencv2\lib\libopencv_video2411.dll.a
