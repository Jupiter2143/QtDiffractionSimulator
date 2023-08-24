#include "rasterwindow.h"
#include "ui_rasterwindow.h"
#include <QBrush>
#include <QGraphicsEllipseItem>
#include <QImage>
#include <QPixmap>

RasterWindow::RasterWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::RasterWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(0, 0, 1024, 768);
    drawPixel();
    QPixmap pixmap = QPixmap::fromImage(*pixelImage);
    scene->setBackgroundBrush(pixmap);
}

void RasterWindow::drawPixel()
{
    pixelImage = new QImage(300, 300, QImage::Format_ARGB32);
    pixelImage->fill(Qt::transparent);
    QPainter painter(pixelImage);
    painter.setRenderHint(QPainter::Antialiasing);
    int radius = 100;
    QPoint center(150, 150);
    painter.setBrush(Qt::blue);
    painter.setPen(Qt::black);
    painter.drawEllipse(center, radius, radius);
}

RasterWindow::~RasterWindow()
{
    delete ui;
}
