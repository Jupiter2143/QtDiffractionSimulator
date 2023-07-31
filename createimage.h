#ifndef CREATEIMAGE_H
#define CREATEIMAGE_H
#include <QImage>
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

QImage createImage(int width, int height, int *dataArray)
{
    QRgb *rgbData = new QRgb[width * height];
    for (int i = 0; i < width * height; ++i)
    {
        unsigned char value = dataArray[i];
        rgbData[i] = jetColorMap(value);
    }
    QImage image((uchar *)rgbData, width, height, QImage::Format_RGB32);
    image.save("diffraction.png", "PNG");
    return image;
}

#endif // CREATEIMAGE_H
