#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtWidgets>

class MyGraphicsView : public QGraphicsView {
    Q_OBJECT
public:
    QGraphicsScene* scene;
    MyGraphicsView(QWidget* parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;

signals:
    void status(QString message);

private:
    QPoint lastPos;
};

#endif // MYGRAPHICSVIEW_H
