#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "backend.h"
#include "qwcomboboxdelegate.h"
#include "qwdoublespindelegate.h"
#include <QGraphicsScene>
#include <QMainWindow>
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
    void initConnect();
    void collectData();
    ~MainWindow();

private slots:
    void on_btnStart_clicked();
    void updateUI(QImage* image);
    void on_btnStop_clicked();
    void updateStatusBar(QString message);
    void on_btnAdd_clicked();
    void on_btnShow_clicked();
    void on_btnDelete_clicked();

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
};

#endif // MAINWINDOW_H
