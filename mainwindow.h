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
#include <QQuickItem>
#include <QQuickWidget>
#include <QStandardItemModel>
namespace Ui {
class MainWindow;
}

void moveToCenter(QMainWindow *w);

class MainWindow : public QMainWindow
{
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
    //edit at 8.28.2023 QMainWindow *w, QQuickWidget *q

public slots:
    void connectInAngleToMainwindow(double value);
    void connectInAngleDistanceToMainwindow(double value);
    void connectOutAngleDistanceToMainwindow(double value);
    void connectWaveLengthToMainwindow(double value);
    void connectBeamRadiusToMainwindow(double value);
    void connectPixelSpaceXToMainwindow(double value);
    void connectPixelSpaceYToMainwindow(double value);
    void connectHorizontalOffsetToMainwindow(double value);
    void connectVertitalOffsetToMainwindow(double value);
    void connectPlottingScaleToMainwindow(double value);
    void connectOpticalScreenXToMainwindow(double value);
    void connectOpticalScreenYToMainwindow(double value);

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
