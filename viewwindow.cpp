#include "viewwindow.h"
#include "ui_viewwindow.h"

ViewWindow::ViewWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::ViewWindow)
{
    ui->setupUi(this);
    view = ui->graphicsView;
    group = new QGraphicsItemGroup;
    QPen pen(Qt::lightGray, 1, Qt::DotLine);
    for (int i = 0; i < 1024; i += 64) {
        QGraphicsLineItem* line = new QGraphicsLineItem(i, 0, i, 1024);
        line->setPen(pen);
        group->addToGroup(line);
    }
    for (int i = 0; i < 1024; i += 64) {
        QGraphicsLineItem* line = new QGraphicsLineItem(0, i, 1024, i);
        line->setPen(pen);
        group->addToGroup(line);
    }
    group->setPos(0.5, 0.5);
}

ViewWindow::~ViewWindow()
{
    delete ui;
}

void ViewWindow::on_checkBox_clicked(bool checked)
{
    if (checked)
        view->scene->addItem(group);
    else
        view->scene->removeItem(group);
}
