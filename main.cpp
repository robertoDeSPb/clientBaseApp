#include "mainwindow.h"
#include "clientreg.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    clientReg r;
    r.show();
    w.show();
    return a.exec();
}


