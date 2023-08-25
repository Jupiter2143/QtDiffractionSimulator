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
    pixelImage = new QImage(300, 300, QImage::Format_ARGB32);
    pixelImage->fill(Qt::gray);
    pixmap = QPixmap::fromImage(*pixelImage);
    scene->setBackgroundBrush(pixmap);
}

void RasterWindow::updatePixelImage()
{
    pixmap = QPixmap::fromImage(*pixelImage);
    scene->setBackgroundBrush(pixmap);
}

RasterWindow::~RasterWindow()
{
    delete ui;
}
