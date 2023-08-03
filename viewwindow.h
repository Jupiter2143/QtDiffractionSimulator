#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include "mygraphicsview.h"
#include <QMainWindow>

namespace Ui {
class ViewWindow;
}

class ViewWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit ViewWindow(QWidget* parent = nullptr);
    MyGraphicsView* view;
    QGraphicsItemGroup* group;
    ~ViewWindow();

private slots:
    void on_checkBox_clicked(bool checked);

private:
    Ui::ViewWindow* ui;
};

#endif // VIEWWINDOW_H
