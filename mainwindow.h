#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "backend.h"
#include "dialog.h"
#include "mydelegate.h"
#include "mygraphicsview.h"
#include "viewwindow.h"
#include <QGraphicsScene>
#include <QImage>
#include <QMainWindow>
#include <QQuickItem>
#include <QQuickWidget>
#include <QStandardItemModel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    void initBackEnd();
    void initMenu();
    void initModel();
    void initTableView();
    void initGraphicsView();
    void initQuickWidget();
    void initConnect();
    void collectData();
    ~MainWindow();

private slots:
    void updateUI(QImage* image);
    void updateStatusBar(float x, float y);
    void on_btnAdd_clicked();
    void on_btnDelete_clicked();
    void on_actStart_triggered();
    void on_actClose_triggered();
    void on_actShow_triggered();
    void on_acExport_triggered();
    void on_mapBox_currentIndexChanged(int index);
    void on_horizontalSlider_valueChanged(int value);
    void on_unitBox_currentTextChanged(const QString& arg1);

    void on_actQML_triggered();

    void on_actHelp_triggered();

    void on_actAbout_triggered();

private:
    Ui::MainWindow* ui;
    BackEnd* backEnd;
    QMenu* menu1;
    QThread* thread;
    QStandardItemModel* model;
    QWDoubleSpinDelegate* doubleSpinDelegate;
    QWComboBoxDelegate* comboBoxDelegate;
    std::chrono::time_point<std::chrono::system_clock> timeStart, timeEnd;
    std::chrono::duration<double> elapsed_seconds;
    QQuickItem* root;
    ViewWindow* viewWindow;
    QQuickWidget* quickWidget;
    MyGraphicsView* graphicsView;
    QImage currentImage;
    Dialog* dialog;
};

#endif // MAINWINDOW_H
