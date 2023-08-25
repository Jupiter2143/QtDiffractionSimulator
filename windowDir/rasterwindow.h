#ifndef RASTERWINDOW_H
#define RASTERWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>

namespace Ui {
class RasterWindow;
}

class RasterWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit RasterWindow(QWidget* parent = nullptr);
    void updatePixelImage();
    ~RasterWindow();
    QImage* pixelImage;

private:
    Ui::RasterWindow* ui;
    QGraphicsScene* scene;
    QPixmap pixmap;
};

#endif // RASTERWINDOW_H
