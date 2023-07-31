#ifndef BACKEND_H
#define BACKEND_H
#include "diffraction.h"
#include <QObject>
#include <QImage>
#include <chrono>
#include <QMap>

extern QMap<QString, double> unitMap;

class BackEnd : public QObject, public Diffraction
{
    Q_OBJECT
public:
    BackEnd();
    QImage createImage(int width, int height, int *dataArray);

private:
    QImage image;
    bool hasInitOpenCL = false;
public slots:
    void startCPUdiff();
    void startGPUdiff();
signals:
    void workDone(QImage *image);
};

#endif // BACKEND_H
