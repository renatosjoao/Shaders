
/*
* All right is reserved by Renato Stoffalette Joao
*
* renatosjoao@gmail.com
*/


#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QGLFormat>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    MainWindow w;
    w.show();


    return a.exec();
}
