#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "classDir/mydelegate.h"
#include "classDir/mygraphicsview.h"
#include "kernelDir/backend.h"
#include "windowDir/dialog.h"
#include "windowDir/rasterwindow.h"
#include "windowDir/viewwindow.h"
#include <QGraphicsScene>
#include <QImage>
#include <QMainWindow>
#include <QQmlContext>
#include <QQuickItem>
#include <QQuickWidget>
#include <QStandardItemModel>
namespace Ui {
class MainWindow;
}

void moveToCenter(QMainWindow* w);

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    void initBackEnd();
    void initStatusBar();
    void initMenu();
    void initModel();
    void initTableView();
    void initGraphicsView();
    void initRasterWindow();
    void initQuickWidget();
    void initUI();
    void initConnect();
    void collectData();

    ~MainWindow();

private slots:
    void updateUI(QImage* image, int* dataArray);
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
    void on_actRestart_triggered();
    void on_actExit_triggered();
    void on_actRaster_triggered();

public slots:
    void on_qmlValueChanged(double theta, double in_l0, double out_L0, double lambda, double beamRadius, double xSpacing, double ySpacing, double xOffset, double yOffset, double scale, double xCenter, double yCenter);
    void on_cppValueChanged();

private:
    Ui::MainWindow* ui;
    BackEnd* backEnd;
    QLabel* label_1;
    QLabel* label_2;
    QLabel* label_3;
    QLabel* label_4;
    QMenu* menu1;
    QThread* thread;
    QStandardItemModel* model;
    QWDoubleSpinDelegate* doubleSpinDelegate;
    QWComboBoxDelegate* comboBoxDelegate;
    std::chrono::time_point<std::chrono::system_clock> timeStart, timeEnd;
    std::chrono::duration<double> elapsed_seconds;
    QQuickItem* root;
    ViewWindow* viewWindow;
    RasterWindow* rasterWindow;
    QQuickWidget* quickWidget;
    //    MyGraphicsView* graphicsView;
    QImage currentImage;
    int* currentDataArray = nullptr;
    Dialog* dialog;
};

#endif // MAINWINDOW_H
