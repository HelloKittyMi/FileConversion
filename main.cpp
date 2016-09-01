#include "mainwindow.h"
#include <QApplication>
#include <qdebug.h>
#include "Logger.h"
#include "Conversion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    const char * src = "E:/test.pdb";
//    const char * dst = "E:/dfgsdgf.pd2";
//    pdb_to_pd2(src, strlen(src), dst, strlen(dst), 1);
    w.show();
    qDebug()<<"run.........";
    return a.exec();
}
