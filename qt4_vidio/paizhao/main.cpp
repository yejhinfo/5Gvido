#include <QtGui/QApplication>
#include "camaraget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    camaraGet w;
    w.setWindowTitle("Clinet");
    w.show();
    
    return a.exec();
}
