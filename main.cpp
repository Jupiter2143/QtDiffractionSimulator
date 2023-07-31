#include <iostream>
#include <chrono>
#include "mainwindow.h"
#include "dialog.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    //    Dialog d;
    //    d.show();
    return app.exec();
}
