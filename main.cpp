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
    // 设置英文字体
    QFont englishFont("Consolas", 10);
    app.setFont(englishFont);

    // 设置中文字体
    QFont chineseFont("微软雅黑", 10);
    app.setFont(chineseFont, "QWidget"); // 设置中文字体仅对 QWidget 生效

    MainWindow w;
    moveToCenter(&w);
    w.show();
    return app.exec();
}
