#include "mainwindow.h"
#include <QApplication>
#include <chrono>
#include <iostream>

int main(int argc, char* argv[])
{
    //    freopen("log.txt", "w", stdout);
    //    freopen("err.txt", "w", stderr);
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}
