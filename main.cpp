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

    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry(); // 考虑任务栏的可用区域
    int taskbarHeight = screenGeometry.height() - screen->geometry().height();
    int screenWidth = screenGeometry.width();
    int screenHeight = screenGeometry.height();

    int windowWidth = w.width();
    int windowHeight = w.height();

    // 计算窗口的位置
    int x = (screenWidth - windowWidth) / 2;
    int y = (screenHeight - windowHeight + taskbarHeight) / 2;
    w.move(x, y);
    w.show();
    return app.exec();
}
