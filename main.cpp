#include "mainwindow.h"
#include <QApplication>
#include <QScreen>
#include <chrono>
#include <iostream>

int main(int argc, char* argv[])
{
    freopen("log.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    QApplication app(argc, argv);
    MainWindow w;
    moveToCenter(&w);
    w.show();
    return app.exec();
}
