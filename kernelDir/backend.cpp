#include "backend.h"
#include <QFile>
QMap<QString, double> unitMap {
    { "m", 1.0 },
    { "cm", 0.01 },
    { "mm", 1.0e-3 },
    { "um", 1.0e-6 },
    { "nm", 1.0e-9 }
};
char* buffer = new char[1024 * 64];

static inline QRgb jetColorMap(int grayValue)
{
    int i = std::max(0, std::min(255, grayValue));

    if (i <= 31)
        return qRgb(0, 0, 128 + 4 * i);
    else if (i <= 32)
        return qRgb(0, 0, 255);
    else if (i <= 95)
        return qRgb(0, 4 + 4 * (i - 32), 255);
    else if (i <= 96)
        return qRgb(2, 255, 254);
    else if (i <= 158)
        return qRgb(6 + 4 * (i - 96), 255, 250 - 4 * (i - 96));
    else if (i <= 159)
        return qRgb(254, 255, 1);
    else if (i <= 223)
        return qRgb(255, 252 - 4 * (i - 159), 0);
    else
        return qRgb(252 - 4 * (i - 224), 0, 0);
}

BackEnd::BackEnd()
    : Diffraction()
{
    QFile file(":/kernel/kernelDir/kernel.cl");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw std::exception("Cannot open kernel file");
    } else {
        QByteArray kernelSource = file.readAll();
        memcpy(buffer, kernelSource.data(), kernelSource.size());
        file.close();
    }
}

void BackEnd::initOpenCL()
{
    if (hasInitOpenCL)
        return;
    Diffraction::initOpenCL(buffer);
    hasInitOpenCL = true;
}

QImage BackEnd::createImage(int width, int height, int* dataArray)
{
    QRgb* rgbData = new QRgb[width * height];
    for (int i = 0; i < width * height; ++i) {
        if (mappingWay == 0) { // 使用jet颜色映射
            unsigned char value = dataArray[i];
            rgbData[i] = jetColorMap(value);
        } else if (mappingWay == 1) { // 使用灰度映射
            rgbData[i] = qRgb(dataArray[i], dataArray[i], dataArray[i]);
        } else if (mappingWay == 2) { // 使用黑白映射
            if (dataArray[i] > threshold)
                rgbData[i] = qRgb(255, 255, 255);
            else
                rgbData[i] = qRgb(0, 0, 0);
        }
    }
    QImage image((uchar*)rgbData, width, height, QImage::Format_RGB32);
    return image;
}

void BackEnd::startCPUdiff()
{
    image = createImage(1024, 1024, doNormalDiff());
    emit workDone(&image);
}

void BackEnd::startGPUdiff()
{
    image = createImage(1024, 1024, doOpenCLDiff());
    emit workDone(&image);
}
