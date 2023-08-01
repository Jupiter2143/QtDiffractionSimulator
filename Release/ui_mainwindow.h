/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <mydoublespinbox.h>
#include <mygraphicsview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_2;
    QQuickWidget *quickWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_5;
    QLabel *scaleLabel;
    MyDoubleSpinBox *scaleBox;
    QFrame *frame1;
    QHBoxLayout *horizontalLayout_28;
    QLabel *subpixelsLabel;
    QDoubleSpinBox *subpixelsBox;
    QFrame *frame2;
    QHBoxLayout *horizontalLayout_12;
    QLabel *LambdaLabel;
    MyDoubleSpinBox *LambdaBox;
    QFrame *frame3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *beamShapeLabel;
    QComboBox *beamShapeBox;
    QFrame *frame4;
    QHBoxLayout *horizontalLayout_11;
    QLabel *beamRadiusLabel;
    MyDoubleSpinBox *beamRadiusBox;
    QFrame *frame5;
    QHBoxLayout *horizontalLayout_13;
    QLabel *xSpacingLabel;
    MyDoubleSpinBox *xSpacingBox;
    QFrame *frame6;
    QHBoxLayout *horizontalLayout_14;
    QLabel *ySpacingLabel;
    MyDoubleSpinBox *ySpacingBox;
    QFrame *frame7;
    QHBoxLayout *horizontalLayout_24;
    QLabel *xOffsetLabel;
    MyDoubleSpinBox *xOffsetBox;
    QFrame *frame8;
    QHBoxLayout *horizontalLayout_25;
    QLabel *yOffsetLabel;
    MyDoubleSpinBox *yOffsetBox;
    QFrame *frame9;
    QHBoxLayout *horizontalLayout_34;
    QLabel *xCenterLabel;
    MyDoubleSpinBox *xCenterBox;
    QFrame *frame10;
    QHBoxLayout *horizontalLayout_35;
    QLabel *yCenterLabel;
    MyDoubleSpinBox *yCenterBox;
    QFrame *frame11;
    QHBoxLayout *horizontalLayout_6;
    QLabel *l_0Label;
    MyDoubleSpinBox *l_0Box;
    QFrame *frame12;
    QHBoxLayout *horizontalLayout_7;
    QLabel *L_0Label;
    MyDoubleSpinBox *L_0Box;
    QFrame *frame13;
    QHBoxLayout *horizontalLayout_9;
    QLabel *thetaLabel;
    QDoubleSpinBox *thetaBox;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnStart;
    QPushButton *btnStop;
    QHBoxLayout *horizontalLayout_15;
    QToolBox *toolBox;
    QWidget *page;
    QGridLayout *gridLayout_3;
    QToolButton *btnAdd;
    QToolButton *btnDelete;
    QToolButton *btnShow;
    QSpacerItem *verticalSpacer;
    QWidget *page_2;
    QTableView *tableView;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_8;
    MyGraphicsView *graphicsView;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(951, 689);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setTabsClosable(true);
        tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName("tab");
        horizontalLayout_2 = new QHBoxLayout(tab);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        quickWidget = new QQuickWidget(tab);
        quickWidget->setObjectName("quickWidget");
        quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
        quickWidget->setSource(QUrl(QString::fromUtf8("qrc:/qml/3D.qml")));

        horizontalLayout_2->addWidget(quickWidget);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setObjectName("gridLayout");
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName("groupBox");
        groupBox->setMinimumSize(QSize(0, 300));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        frame = new QFrame(groupBox);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(1);
        horizontalLayout_5 = new QHBoxLayout(frame);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        scaleLabel = new QLabel(frame);
        scaleLabel->setObjectName("scaleLabel");

        horizontalLayout_5->addWidget(scaleLabel);

        scaleBox = new MyDoubleSpinBox(frame);
        scaleBox->setObjectName("scaleBox");
        scaleBox->setMinimumSize(QSize(125, 0));
        scaleBox->setMaximumSize(QSize(125, 16777215));
        scaleBox->setContextMenuPolicy(Qt::CustomContextMenu);
        scaleBox->setDecimals(3);
        scaleBox->setValue(0.200000000000000);

        horizontalLayout_5->addWidget(scaleBox);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);

        frame1 = new QFrame(groupBox);
        frame1->setObjectName("frame1");
        frame1->setFrameShape(QFrame::Box);
        frame1->setFrameShadow(QFrame::Raised);
        horizontalLayout_28 = new QHBoxLayout(frame1);
        horizontalLayout_28->setObjectName("horizontalLayout_28");
        subpixelsLabel = new QLabel(frame1);
        subpixelsLabel->setObjectName("subpixelsLabel");

        horizontalLayout_28->addWidget(subpixelsLabel);

        subpixelsBox = new QDoubleSpinBox(frame1);
        subpixelsBox->setObjectName("subpixelsBox");
        subpixelsBox->setMinimumSize(QSize(125, 0));
        subpixelsBox->setMaximumSize(QSize(125, 16777215));
        subpixelsBox->setDecimals(0);
        subpixelsBox->setValue(2.000000000000000);

        horizontalLayout_28->addWidget(subpixelsBox);


        gridLayout_2->addWidget(frame1, 3, 2, 1, 1);

        frame2 = new QFrame(groupBox);
        frame2->setObjectName("frame2");
        frame2->setFrameShape(QFrame::Box);
        frame2->setFrameShadow(QFrame::Raised);
        horizontalLayout_12 = new QHBoxLayout(frame2);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        LambdaLabel = new QLabel(frame2);
        LambdaLabel->setObjectName("LambdaLabel");

        horizontalLayout_12->addWidget(LambdaLabel);

        LambdaBox = new MyDoubleSpinBox(frame2);
        LambdaBox->setObjectName("LambdaBox");
        LambdaBox->setMinimumSize(QSize(125, 0));
        LambdaBox->setMaximumSize(QSize(125, 16777215));
        LambdaBox->setDecimals(0);
        LambdaBox->setMaximum(1000.000000000000000);
        LambdaBox->setValue(635.000000000000000);

        horizontalLayout_12->addWidget(LambdaBox);


        gridLayout_2->addWidget(frame2, 2, 0, 1, 1);

        frame3 = new QFrame(groupBox);
        frame3->setObjectName("frame3");
        frame3->setFrameShape(QFrame::Box);
        frame3->setFrameShadow(QFrame::Raised);
        horizontalLayout_10 = new QHBoxLayout(frame3);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        beamShapeLabel = new QLabel(frame3);
        beamShapeLabel->setObjectName("beamShapeLabel");

        horizontalLayout_10->addWidget(beamShapeLabel);

        beamShapeBox = new QComboBox(frame3);
        beamShapeBox->addItem(QString());
        beamShapeBox->addItem(QString());
        beamShapeBox->addItem(QString());
        beamShapeBox->setObjectName("beamShapeBox");
        beamShapeBox->setMinimumSize(QSize(125, 0));
        beamShapeBox->setMaximumSize(QSize(125, 16777215));

        horizontalLayout_10->addWidget(beamShapeBox);


        gridLayout_2->addWidget(frame3, 1, 1, 1, 1);

        frame4 = new QFrame(groupBox);
        frame4->setObjectName("frame4");
        frame4->setFrameShape(QFrame::Box);
        frame4->setFrameShadow(QFrame::Raised);
        horizontalLayout_11 = new QHBoxLayout(frame4);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        beamRadiusLabel = new QLabel(frame4);
        beamRadiusLabel->setObjectName("beamRadiusLabel");

        horizontalLayout_11->addWidget(beamRadiusLabel);

        beamRadiusBox = new MyDoubleSpinBox(frame4);
        beamRadiusBox->setObjectName("beamRadiusBox");
        beamRadiusBox->setMinimumSize(QSize(125, 0));
        beamRadiusBox->setMaximumSize(QSize(125, 16777215));
        beamRadiusBox->setDecimals(3);
        beamRadiusBox->setValue(1.000000000000000);

        horizontalLayout_11->addWidget(beamRadiusBox);


        gridLayout_2->addWidget(frame4, 1, 2, 1, 1);

        frame5 = new QFrame(groupBox);
        frame5->setObjectName("frame5");
        frame5->setFrameShape(QFrame::Box);
        frame5->setFrameShadow(QFrame::Raised);
        horizontalLayout_13 = new QHBoxLayout(frame5);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        xSpacingLabel = new QLabel(frame5);
        xSpacingLabel->setObjectName("xSpacingLabel");

        horizontalLayout_13->addWidget(xSpacingLabel);

        xSpacingBox = new MyDoubleSpinBox(frame5);
        xSpacingBox->setObjectName("xSpacingBox");
        xSpacingBox->setMinimumSize(QSize(125, 0));
        xSpacingBox->setMaximumSize(QSize(125, 16777215));
        xSpacingBox->setValue(63.820000000000000);

        horizontalLayout_13->addWidget(xSpacingBox);


        gridLayout_2->addWidget(frame5, 2, 1, 1, 1);

        frame6 = new QFrame(groupBox);
        frame6->setObjectName("frame6");
        frame6->setFrameShape(QFrame::Box);
        frame6->setFrameShadow(QFrame::Raised);
        horizontalLayout_14 = new QHBoxLayout(frame6);
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        ySpacingLabel = new QLabel(frame6);
        ySpacingLabel->setObjectName("ySpacingLabel");

        horizontalLayout_14->addWidget(ySpacingLabel);

        ySpacingBox = new MyDoubleSpinBox(frame6);
        ySpacingBox->setObjectName("ySpacingBox");
        ySpacingBox->setMinimumSize(QSize(125, 0));
        ySpacingBox->setMaximumSize(QSize(125, 16777215));
        ySpacingBox->setValue(63.820000000000000);

        horizontalLayout_14->addWidget(ySpacingBox);


        gridLayout_2->addWidget(frame6, 2, 2, 1, 1);

        frame7 = new QFrame(groupBox);
        frame7->setObjectName("frame7");
        frame7->setFrameShape(QFrame::Box);
        frame7->setFrameShadow(QFrame::Raised);
        horizontalLayout_24 = new QHBoxLayout(frame7);
        horizontalLayout_24->setObjectName("horizontalLayout_24");
        xOffsetLabel = new QLabel(frame7);
        xOffsetLabel->setObjectName("xOffsetLabel");

        horizontalLayout_24->addWidget(xOffsetLabel);

        xOffsetBox = new MyDoubleSpinBox(frame7);
        xOffsetBox->setObjectName("xOffsetBox");
        xOffsetBox->setMinimumSize(QSize(125, 0));
        xOffsetBox->setMaximumSize(QSize(125, 16777215));

        horizontalLayout_24->addWidget(xOffsetBox);


        gridLayout_2->addWidget(frame7, 3, 0, 1, 1);

        frame8 = new QFrame(groupBox);
        frame8->setObjectName("frame8");
        frame8->setFrameShape(QFrame::Box);
        frame8->setFrameShadow(QFrame::Raised);
        horizontalLayout_25 = new QHBoxLayout(frame8);
        horizontalLayout_25->setObjectName("horizontalLayout_25");
        yOffsetLabel = new QLabel(frame8);
        yOffsetLabel->setObjectName("yOffsetLabel");

        horizontalLayout_25->addWidget(yOffsetLabel);

        yOffsetBox = new MyDoubleSpinBox(frame8);
        yOffsetBox->setObjectName("yOffsetBox");
        yOffsetBox->setMinimumSize(QSize(125, 0));
        yOffsetBox->setMaximumSize(QSize(125, 16777215));

        horizontalLayout_25->addWidget(yOffsetBox);


        gridLayout_2->addWidget(frame8, 3, 1, 1, 1);

        frame9 = new QFrame(groupBox);
        frame9->setObjectName("frame9");
        frame9->setFrameShape(QFrame::Box);
        frame9->setFrameShadow(QFrame::Raised);
        horizontalLayout_34 = new QHBoxLayout(frame9);
        horizontalLayout_34->setObjectName("horizontalLayout_34");
        xCenterLabel = new QLabel(frame9);
        xCenterLabel->setObjectName("xCenterLabel");

        horizontalLayout_34->addWidget(xCenterLabel);

        xCenterBox = new MyDoubleSpinBox(frame9);
        xCenterBox->setObjectName("xCenterBox");
        xCenterBox->setMinimumSize(QSize(125, 0));
        xCenterBox->setMaximumSize(QSize(125, 16777215));
        xCenterBox->setDecimals(3);
        xCenterBox->setMinimum(-9999.000000000000000);
        xCenterBox->setMaximum(9999.000000000000000);
        xCenterBox->setValue(0.000000000000000);

        horizontalLayout_34->addWidget(xCenterBox);


        gridLayout_2->addWidget(frame9, 4, 0, 1, 1);

        frame10 = new QFrame(groupBox);
        frame10->setObjectName("frame10");
        frame10->setFrameShape(QFrame::Box);
        frame10->setFrameShadow(QFrame::Raised);
        horizontalLayout_35 = new QHBoxLayout(frame10);
        horizontalLayout_35->setObjectName("horizontalLayout_35");
        yCenterLabel = new QLabel(frame10);
        yCenterLabel->setObjectName("yCenterLabel");

        horizontalLayout_35->addWidget(yCenterLabel);

        yCenterBox = new MyDoubleSpinBox(frame10);
        yCenterBox->setObjectName("yCenterBox");
        yCenterBox->setMinimumSize(QSize(125, 0));
        yCenterBox->setMaximumSize(QSize(125, 16777215));
        yCenterBox->setDecimals(3);
        yCenterBox->setMinimum(-9999.000000000000000);
        yCenterBox->setMaximum(9999.000000000000000);
        yCenterBox->setValue(0.000000000000000);

        horizontalLayout_35->addWidget(yCenterBox);


        gridLayout_2->addWidget(frame10, 4, 1, 1, 1);

        frame11 = new QFrame(groupBox);
        frame11->setObjectName("frame11");
        frame11->setFrameShape(QFrame::Box);
        frame11->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame11);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        l_0Label = new QLabel(frame11);
        l_0Label->setObjectName("l_0Label");

        horizontalLayout_6->addWidget(l_0Label);

        l_0Box = new MyDoubleSpinBox(frame11);
        l_0Box->setObjectName("l_0Box");
        l_0Box->setMinimumSize(QSize(125, 0));
        l_0Box->setMaximumSize(QSize(125, 16777215));
        l_0Box->setDecimals(3);
        l_0Box->setValue(0.500000000000000);

        horizontalLayout_6->addWidget(l_0Box);


        gridLayout_2->addWidget(frame11, 0, 1, 1, 1);

        frame12 = new QFrame(groupBox);
        frame12->setObjectName("frame12");
        frame12->setFrameShape(QFrame::Box);
        frame12->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame12);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        L_0Label = new QLabel(frame12);
        L_0Label->setObjectName("L_0Label");

        horizontalLayout_7->addWidget(L_0Label);

        L_0Box = new MyDoubleSpinBox(frame12);
        L_0Box->setObjectName("L_0Box");
        L_0Box->setMinimumSize(QSize(125, 0));
        L_0Box->setMaximumSize(QSize(125, 16777215));
        L_0Box->setDecimals(3);
        L_0Box->setValue(0.870000000000000);

        horizontalLayout_7->addWidget(L_0Box);


        gridLayout_2->addWidget(frame12, 0, 2, 1, 1);

        frame13 = new QFrame(groupBox);
        frame13->setObjectName("frame13");
        frame13->setFrameShape(QFrame::Box);
        frame13->setFrameShadow(QFrame::Raised);
        horizontalLayout_9 = new QHBoxLayout(frame13);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        thetaLabel = new QLabel(frame13);
        thetaLabel->setObjectName("thetaLabel");

        horizontalLayout_9->addWidget(thetaLabel);

        thetaBox = new QDoubleSpinBox(frame13);
        thetaBox->setObjectName("thetaBox");
        thetaBox->setMinimumSize(QSize(125, 0));
        thetaBox->setMaximumSize(QSize(125, 16777215));
        thetaBox->setContextMenuPolicy(Qt::DefaultContextMenu);
        thetaBox->setDecimals(3);
        thetaBox->setValue(58.590000000000003);

        horizontalLayout_9->addWidget(thetaBox);


        gridLayout_2->addWidget(frame13, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(tab_2);
        plainTextEdit->setObjectName("plainTextEdit");

        gridLayout->addWidget(plainTextEdit, 0, 1, 2, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        btnStart = new QPushButton(tab_2);
        btnStart->setObjectName("btnStart");

        horizontalLayout_4->addWidget(btnStart);

        btnStop = new QPushButton(tab_2);
        btnStop->setObjectName("btnStop");

        horizontalLayout_4->addWidget(btnStop);


        gridLayout->addLayout(horizontalLayout_4, 2, 1, 1, 1);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        toolBox = new QToolBox(tab_2);
        toolBox->setObjectName("toolBox");
        toolBox->setFrameShape(QFrame::Box);
        toolBox->setFrameShadow(QFrame::Raised);
        toolBox->setLineWidth(2);
        page = new QWidget();
        page->setObjectName("page");
        page->setGeometry(QRect(0, 0, 98, 121));
        gridLayout_3 = new QGridLayout(page);
        gridLayout_3->setObjectName("gridLayout_3");
        btnAdd = new QToolButton(page);
        btnAdd->setObjectName("btnAdd");

        gridLayout_3->addWidget(btnAdd, 0, 0, 1, 1);

        btnDelete = new QToolButton(page);
        btnDelete->setObjectName("btnDelete");

        gridLayout_3->addWidget(btnDelete, 1, 0, 1, 1);

        btnShow = new QToolButton(page);
        btnShow->setObjectName("btnShow");

        gridLayout_3->addWidget(btnShow, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 3, 0, 1, 1);

        toolBox->addItem(page, QString::fromUtf8("Page 1"));
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        page_2->setGeometry(QRect(0, 0, 98, 28));
        toolBox->addItem(page_2, QString::fromUtf8("Page 2"));

        horizontalLayout_15->addWidget(toolBox);

        tableView = new QTableView(tab_2);
        tableView->setObjectName("tableView");
        tableView->setMinimumSize(QSize(600, 0));

        horizontalLayout_15->addWidget(tableView);


        gridLayout->addLayout(horizontalLayout_15, 1, 0, 2, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        horizontalLayout_8 = new QHBoxLayout(tab_3);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        graphicsView = new MyGraphicsView(tab_3);
        graphicsView->setObjectName("graphicsView");

        horizontalLayout_8->addWidget(graphicsView);

        tabWidget->addTab(tab_3, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 951, 24));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName("menu_4");
        menu_5 = new QMenu(menubar);
        menu_5->setObjectName("menu_5");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menubar->addAction(menu_5->menuAction());

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        beamShapeBox->setCurrentIndex(0);
        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        scaleLabel->setText(QCoreApplication::translate("MainWindow", "\346\257\224\344\276\213\345\260\272", nullptr));
        scaleBox->setSuffix(QCoreApplication::translate("MainWindow", " mm", nullptr));
        subpixelsLabel->setText(QCoreApplication::translate("MainWindow", "\345\255\220\345\203\217\347\264\240\344\270\252\346\225\260", nullptr));
        LambdaLabel->setText(QCoreApplication::translate("MainWindow", "\346\263\242\351\225\277", nullptr));
        LambdaBox->setSuffix(QCoreApplication::translate("MainWindow", " nm", nullptr));
        beamShapeLabel->setText(QCoreApplication::translate("MainWindow", "\345\205\211\346\272\220\347\261\273\345\236\213", nullptr));
        beamShapeBox->setItemText(0, QCoreApplication::translate("MainWindow", "circle", nullptr));
        beamShapeBox->setItemText(1, QCoreApplication::translate("MainWindow", "rectangle", nullptr));
        beamShapeBox->setItemText(2, QCoreApplication::translate("MainWindow", "point", nullptr));

        beamRadiusLabel->setText(QCoreApplication::translate("MainWindow", "\345\205\211\346\235\237\345\215\212\345\276\204", nullptr));
        beamRadiusBox->setSuffix(QCoreApplication::translate("MainWindow", " mm", nullptr));
        xSpacingLabel->setText(QCoreApplication::translate("MainWindow", "\345\203\217\347\264\240\351\227\264\350\267\235x", nullptr));
        xSpacingBox->setPrefix(QString());
        xSpacingBox->setSuffix(QCoreApplication::translate("MainWindow", " um", nullptr));
        ySpacingLabel->setText(QCoreApplication::translate("MainWindow", "\345\203\217\347\264\240\351\227\264\350\267\235y", nullptr));
        ySpacingBox->setSuffix(QCoreApplication::translate("MainWindow", " um", nullptr));
        xOffsetLabel->setText(QCoreApplication::translate("MainWindow", "\346\260\264\345\271\263\345\201\217\347\247\273", nullptr));
        xOffsetBox->setSuffix(QCoreApplication::translate("MainWindow", " um", nullptr));
        yOffsetLabel->setText(QCoreApplication::translate("MainWindow", "\345\236\202\347\233\264\345\201\217\347\247\273", nullptr));
        yOffsetBox->setSuffix(QCoreApplication::translate("MainWindow", " um", nullptr));
        xCenterLabel->setText(QCoreApplication::translate("MainWindow", "\345\205\211\345\261\217\344\270\255\345\277\203x", nullptr));
        xCenterBox->setSuffix(QCoreApplication::translate("MainWindow", " m", nullptr));
        yCenterLabel->setText(QCoreApplication::translate("MainWindow", "\345\205\211\345\261\217\344\270\255\345\277\203y", nullptr));
        yCenterBox->setPrefix(QString());
        yCenterBox->setSuffix(QCoreApplication::translate("MainWindow", " m", nullptr));
        l_0Label->setText(QCoreApplication::translate("MainWindow", "\345\205\245\345\260\204\350\267\235\347\246\273", nullptr));
        l_0Box->setSuffix(QCoreApplication::translate("MainWindow", " m", nullptr));
        L_0Label->setText(QCoreApplication::translate("MainWindow", "\345\207\272\345\260\204\350\267\235\347\246\273", nullptr));
        L_0Box->setPrefix(QString());
        L_0Box->setSuffix(QCoreApplication::translate("MainWindow", " m", nullptr));
        thetaLabel->setText(QCoreApplication::translate("MainWindow", "\345\205\245\345\260\204\350\247\222", nullptr));
        thetaBox->setSuffix(QCoreApplication::translate("MainWindow", " \302\260", nullptr));
        btnStart->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        btnStop->setText(QCoreApplication::translate("MainWindow", "stop", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\350\241\214", nullptr));
        btnDelete->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\241\214", nullptr));
        btnShow->setText(QCoreApplication::translate("MainWindow", "\351\242\204\350\247\210", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainWindow", "Page 1", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainWindow", "Page 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Tab 3", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\350\247\206\345\233\276", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\346\236\204\345\273\272", nullptr));
        menu_5->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
