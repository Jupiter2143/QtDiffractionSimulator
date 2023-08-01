#include "mygraphicsview.h"

MyGraphicsView::MyGraphicsView(QWidget* parent)
    : QGraphicsView(parent)
{

    setRenderHint(QPainter::Antialiasing);
    setDragMode(QGraphicsView::ScrollHandDrag);
    setMouseTracking(true);
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    setOptimizationFlag(QGraphicsView::DontAdjustForAntialiasing, true);
    scene = new QGraphicsScene(this);

    QPixmap pixmap("diffraction.png");
    scene->addPixmap(pixmap);

    setScene(scene);
}

void MyGraphicsView::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        // 记录鼠标按下的位置
        lastPos = event->pos();
    }
    QGraphicsView::mousePressEvent(event);
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton) {
        // 计算鼠标移动的距离
        QPoint delta = event->pos() - lastPos;
        lastPos = event->pos();

        // 将场景移动对应的距离
        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - delta.x());
        verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());
    } else {
        QPointF scenePos = mapToScene(event->pos()); // 将鼠标坐标转换为场景坐标
        QString message = QString("x: %1, y: %2").arg(scenePos.x()).arg(scenePos.y()); // 将场景坐标转换为字符串
        emit status(message);
    }
    QGraphicsView::mouseMoveEvent(event);
}

void MyGraphicsView::wheelEvent(QWheelEvent* event)
{
    if (event->modifiers() == Qt::ControlModifier) {
        double scaleFactor = 1.15;
        if (event->angleDelta().y() > 0) {
            // 放大
            scale(scaleFactor, scaleFactor);
        } else {
            // 缩小
            scale(1.0 / scaleFactor, 1.0 / scaleFactor);
        }
        event->accept();
    } else {
        QGraphicsView::wheelEvent(event);
    }
}
