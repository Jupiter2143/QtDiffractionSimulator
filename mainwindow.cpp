#include "mainwindow.h"

#include "mygraphicsview.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->scaleLabel->setToolTip("每个像素代表的实际物理长度");
    initBackEnd();
    initMenu();
    initModel();
    initTableView();
    initConnect();
}

void MainWindow::initBackEnd()
{
    thread = new QThread();
    backEnd = new BackEnd();
    backEnd->moveToThread(thread);
}

void MainWindow::initMenu()
{
    menu1 = new QMenu(this);
    QAction* actChangeSuffix = new QAction("后缀名", this);
    QAction* action1 = new QAction("导入", this);
    QAction* action2 = new QAction("导出", this);
    menu1->addAction(actChangeSuffix);
    menu1->addAction(action1);
    menu1->addAction(action2);
}

void MainWindow::initModel()
{
    model = new QStandardItemModel();
    model->setColumnCount(7);
    model->setHeaderData(0, Qt::Horizontal, "形状");
    model->setHeaderData(1, Qt::Horizontal, "长度(um)");
    model->setHeaderData(2, Qt::Horizontal, "宽度(um)");
    model->setHeaderData(3, Qt::Horizontal, "半径(um)");
    model->setHeaderData(4, Qt::Horizontal, "x偏移(um)");
    model->setHeaderData(5, Qt::Horizontal, "y偏移(um)");
    model->setHeaderData(6, Qt::Horizontal, "反射率");
}

void MainWindow::initTableView()
{
    doubleSpinDelegate = new QWDoubleSpinDelegate();
    comboBoxDelegate = new QWComboBoxDelegate();
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setItemDelegateForColumn(0, comboBoxDelegate);
    for (int i = 1; i < 7; ++i) {
        ui->tableView->setItemDelegateForColumn(i, doubleSpinDelegate);
    }
    on_btnAdd_clicked();
    on_btnAdd_clicked();
}

void MainWindow::initConnect()
{
    connect(backEnd, &BackEnd::workDone, this, &MainWindow::updateUI);
    connect(ui->graphicsView, &MyGraphicsView::status, this,
        &MainWindow::updateStatusBar);
}

void MainWindow::collectData()
{
    Diffraction::load->scale = ui->scaleBox->value() / 1000.0f;
    Diffraction::load->l0 = ui->l_0Box->value();
    Diffraction::load->L0 = ui->L_0Box->value();
    Diffraction::load->xCenter = ui->xCenterBox->value();
    Diffraction::load->yCenter = ui->yCenterBox->value();
    Diffraction::load->theta = ui->thetaBox->value() / 180.0f * M_PI;
    Diffraction::load->beamShape = ui->beamShapeBox->currentIndex();
    Diffraction::load->beamRadius = ui->beamRadiusBox->value() * unitMap.value("mm");
    Diffraction::load->beamLambda = ui->LambdaBox->value() * unitMap.value("nm");
    Diffraction::load->xSpacing = ui->xSpacingBox->value() * unitMap.value("um");
    Diffraction::load->ySpacing = ui->ySpacingBox->value() * unitMap.value("um");
    Diffraction::load->xOffset = ui->xOffsetBox->value() * unitMap.value("um");
    Diffraction::load->yOffset = ui->yOffsetBox->value() * unitMap.value("um");
    Diffraction::load->subpixelsCount = (int)ui->subpixelsBox->value();
    for (int i = 0; i < Diffraction::load->subpixelsCount; i++) {
        Diffraction::load->subpixels[i].shape = model->index(i, 0).data(Qt::UserRole).toInt();
        Diffraction::load->subpixels[i].length = model->index(i, 1).data(Qt::EditRole).toFloat() * unitMap.value("um");
        Diffraction::load->subpixels[i].width = model->index(i, 2).data(Qt::EditRole).toFloat() * unitMap.value("um");
        Diffraction::load->subpixels[i].rho = model->index(i, 3).data(Qt::EditRole).toFloat() * unitMap.value("um");
        Diffraction::load->subpixels[i].xRelative = model->index(i, 4).data(Qt::EditRole).toFloat() * unitMap.value("um");
        Diffraction::load->subpixels[i].yRelative = model->index(i, 5).data(Qt::EditRole).toFloat() * unitMap.value("um");
        Diffraction::load->subpixels[i].reflectance = model->index(i, 6).data(Qt::EditRole).toFloat();
    }
    Diffraction::load->j_limit = Diffraction::load->beamRadius / Diffraction::load->ySpacing;
    Diffraction::load->r_square = Diffraction::load->beamRadius * Diffraction::load->beamRadius;
    Diffraction::load->y_spacing_square = Diffraction::load->ySpacing * Diffraction::load->ySpacing;
    Diffraction::load->sin_theta = sin(Diffraction::load->theta);
    Diffraction::load->cos_theta = cos(Diffraction::load->theta);
    Diffraction::load->wave_number = 2 * M_PI / Diffraction::load->beamLambda;
}

MainWindow::~MainWindow()
{
    if (thread->isRunning()) {
        thread->quit();
        thread->wait();
    }
    delete ui;
    delete backEnd;
    delete thread;
}

void MainWindow::on_btnStart_clicked()
{
    ui->btnStart->setEnabled(false);
    timeStart = std::chrono::system_clock::now();
    collectData();
    thread->start();
    QMetaObject::invokeMethod(backEnd, "startGPUdiff");
    //    QMetaObject::invokeMethod(backEnd, "startCPUdiff");
}

void MainWindow::updateUI(QImage* image)
{
    timeEnd = std::chrono::system_clock::now();
    elapsed_seconds = timeEnd - timeStart;
    printf("elapsed time: %f\n", elapsed_seconds.count());
    ui->plainTextEdit->appendPlainText(
        QString("Cost: %1 s").arg(elapsed_seconds.count()));
    ui->graphicsView->scene->clear();
    ui->graphicsView->scene->addPixmap(QPixmap::fromImage(*image));
    ui->btnStart->setEnabled(true);
}

void MainWindow::on_btnStop_clicked()
{
    if (thread->isRunning()) {
        thread->terminate();
        thread->wait();
        delete thread;
        thread = new QThread();
    }
    ui->btnStart->setEnabled(true);
}

void MainWindow::updateStatusBar(QString message)
{
    ui->statusbar->showMessage(message);
}

void MainWindow::on_btnAdd_clicked()
{
    model->insertRow(model->rowCount());
    QList<QStandardItem*> items;
    for (int i = 0; i < 7; ++i) {
        QStandardItem* item = new QStandardItem();
        items.append(item);
    }
    items.at(0)->setData(QVariant("rectangle"), Qt::DisplayRole); // shape
    items.at(0)->setData(QVariant(1), Qt::UserRole); // shape
    items.at(1)->setData(QVariant(3.191), Qt::DisplayRole); // length
    items.at(2)->setData(QVariant(3.191), Qt::DisplayRole); // width
    items.at(3)->setData(QVariant(15.955), Qt::DisplayRole); // rho
    items.at(4)->setData(QVariant(-15.955), Qt::DisplayRole); // xRelative
    items.at(5)->setData(QVariant(0), Qt::DisplayRole); // yRelative
    items.at(6)->setData(QVariant(1), Qt::DisplayRole); // reflectance
    for (int i = 0; i < items.size(); ++i) {
        model->setItem(model->rowCount() - 1, i, items.at(i));
    }
}

void MainWindow::on_btnShow_clicked()
{
    int row = ui->tableView->currentIndex().row();
    int col = ui->tableView->currentIndex().column();
    QString info = model->index(row, col).data().toString();
    ui->plainTextEdit->appendPlainText("info=" + info + QString::number(unitMap.value("um")));
    //    int currentIndex = model->index(1, 1).data(Qt::UserRole).toInt();
    //    ui->plainTextEdit->appendPlainText("currentIndex="+QString::number(currentIndex));
}

void MainWindow::on_btnDelete_clicked()
{
    int row = ui->tableView->currentIndex().row();
    model->removeRow(row);
}
