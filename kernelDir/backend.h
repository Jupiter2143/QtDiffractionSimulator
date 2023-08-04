#ifndef BACKEND_H
#define BACKEND_H
#include "diffraction.h"
#include <QImage>
#include <QMap>
#include <QObject>
#include <chrono>

extern QMap<QString, double> unitMap;

class BackEnd : public QObject, public Diffraction {
    Q_OBJECT
public:
    int mappingWay = 0;
    int threshold = 0;
    bool hasInitOpenCL = false;
    BackEnd();
    void initOpenCL();
    QImage createImage(int width, int height, int* dataArray);

private:
    QImage image;

public slots:
    void startCPUdiff();
    void startGPUdiff();
signals:
    void workDone(QImage* image);
};

#endif // BACKEND_H
