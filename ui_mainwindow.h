/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Apr 3 13:57:12 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    GLWidget *widget;
    QFrame *frame;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QListWidget *listWidget_2;
    QLabel *label_3;
    QListWidget *listWidget_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QLabel *label_67;
    QLabel *label_68;
    QLabel *label_69;
    QCheckBox *checkBox;
    QWidget *Cor;
    QListWidget *listWidget;
    QLabel *label_4;
    QWidget *Camera;
    QDoubleSpinBox *doubleSpinBox_5;
    QDoubleSpinBox *doubleSpinBox_8;
    QDoubleSpinBox *doubleSpinBox_9;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_7;
    QDoubleSpinBox *doubleSpinBox_6;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_6;
    QWidget *Ortho;
    QDoubleSpinBox *doubleSpinBox_19;
    QDoubleSpinBox *doubleSpinBox_20;
    QDoubleSpinBox *doubleSpinBox_21;
    QDoubleSpinBox *doubleSpinBox_22;
    QDoubleSpinBox *doubleSpinBox_23;
    QDoubleSpinBox *doubleSpinBox_24;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QWidget *Perspectiva;
    QDoubleSpinBox *doubleSpinBox_16;
    QDoubleSpinBox *doubleSpinBox_17;
    QDoubleSpinBox *doubleSpinBox_18;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QWidget *Frustum;
    QDoubleSpinBox *doubleSpinBox_10;
    QDoubleSpinBox *doubleSpinBox_11;
    QDoubleSpinBox *doubleSpinBox_12;
    QDoubleSpinBox *doubleSpinBox_13;
    QDoubleSpinBox *doubleSpinBox_14;
    QDoubleSpinBox *doubleSpinBox_15;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QSpinBox *spinBox;
    QLabel *label_24;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 768);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMouseTracking(true);
        MainWindow->setTabShape(QTabWidget::Rounded);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget = new GLWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMouseTracking(true);
        widget->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_2->addWidget(widget);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(200, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        comboBox = new QComboBox(frame);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 50, 121, 26));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 650, 41, 32));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(90, 10, 51, 32));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 90, 81, 16));
        listWidget_2 = new QListWidget(frame);
        new QListWidgetItem(listWidget_2);
        new QListWidgetItem(listWidget_2);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(20, 270, 91, 61));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 250, 81, 16));
        listWidget_3 = new QListWidget(frame);
        new QListWidgetItem(listWidget_3);
        new QListWidgetItem(listWidget_3);
        new QListWidgetItem(listWidget_3);
        listWidget_3->setObjectName(QString::fromUtf8("listWidget_3"));
        listWidget_3->setEnabled(false);
        listWidget_3->setGeometry(QRect(110, 120, 71, 81));
        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 350, 181, 291));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalSlider = new QSlider(tab);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 40, 160, 26));
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(tab);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(10, 80, 160, 26));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_3 = new QSlider(tab);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(10, 120, 160, 26));
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        label_67 = new QLabel(tab);
        label_67->setObjectName(QString::fromUtf8("label_67"));
        label_67->setGeometry(QRect(0, 40, 60, 16));
        label_68 = new QLabel(tab);
        label_68->setObjectName(QString::fromUtf8("label_68"));
        label_68->setGeometry(QRect(0, 80, 60, 16));
        label_69 = new QLabel(tab);
        label_69->setObjectName(QString::fromUtf8("label_69"));
        label_69->setGeometry(QRect(0, 120, 60, 16));
        checkBox = new QCheckBox(tab);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(10, 10, 91, 21));
        tabWidget->addTab(tab, QString());
        Cor = new QWidget();
        Cor->setObjectName(QString::fromUtf8("Cor"));
        QFont font;
        font.setItalic(true);
        Cor->setFont(font);
        listWidget = new QListWidget(Cor);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(30, 50, 111, 151));
        label_4 = new QLabel(Cor);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 20, 121, 16));
        tabWidget->addTab(Cor, QString());
        Camera = new QWidget();
        Camera->setObjectName(QString::fromUtf8("Camera"));
        doubleSpinBox_5 = new QDoubleSpinBox(Camera);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));
        doubleSpinBox_5->setGeometry(QRect(20, 40, 46, 24));
        doubleSpinBox_5->setMinimum(-5);
        doubleSpinBox_5->setMaximum(5);
        doubleSpinBox_5->setSingleStep(0.5);
        doubleSpinBox_8 = new QDoubleSpinBox(Camera);
        doubleSpinBox_8->setObjectName(QString::fromUtf8("doubleSpinBox_8"));
        doubleSpinBox_8->setGeometry(QRect(70, 180, 46, 24));
        doubleSpinBox_8->setMinimum(-1);
        doubleSpinBox_8->setMaximum(1);
        doubleSpinBox_8->setSingleStep(2);
        doubleSpinBox_8->setValue(1);
        doubleSpinBox_9 = new QDoubleSpinBox(Camera);
        doubleSpinBox_9->setObjectName(QString::fromUtf8("doubleSpinBox_9"));
        doubleSpinBox_9->setGeometry(QRect(120, 180, 46, 24));
        doubleSpinBox_9->setMinimum(-10);
        doubleSpinBox_9->setMaximum(10);
        doubleSpinBox_9->setSingleStep(0.5);
        doubleSpinBox_3 = new QDoubleSpinBox(Camera);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setGeometry(QRect(20, 110, 46, 24));
        doubleSpinBox_3->setMinimum(-10);
        doubleSpinBox_3->setMaximum(10);
        doubleSpinBox_3->setSingleStep(0.5);
        doubleSpinBox_2 = new QDoubleSpinBox(Camera);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(120, 110, 46, 24));
        doubleSpinBox_2->setMinimum(-10);
        doubleSpinBox_2->setMaximum(10);
        doubleSpinBox_2->setSingleStep(0.5);
        doubleSpinBox_2->setValue(-1);
        doubleSpinBox_7 = new QDoubleSpinBox(Camera);
        doubleSpinBox_7->setObjectName(QString::fromUtf8("doubleSpinBox_7"));
        doubleSpinBox_7->setGeometry(QRect(120, 40, 46, 24));
        doubleSpinBox_7->setMinimum(-5);
        doubleSpinBox_7->setMaximum(5);
        doubleSpinBox_7->setSingleStep(0.5);
        doubleSpinBox_7->setValue(0);
        doubleSpinBox_6 = new QDoubleSpinBox(Camera);
        doubleSpinBox_6->setObjectName(QString::fromUtf8("doubleSpinBox_6"));
        doubleSpinBox_6->setGeometry(QRect(70, 40, 46, 24));
        doubleSpinBox_6->setMinimum(-5);
        doubleSpinBox_6->setMaximum(5);
        doubleSpinBox_6->setSingleStep(0.5);
        doubleSpinBox = new QDoubleSpinBox(Camera);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(70, 110, 46, 24));
        doubleSpinBox->setMinimum(-10);
        doubleSpinBox->setMaximum(10);
        doubleSpinBox->setSingleStep(0.5);
        doubleSpinBox_4 = new QDoubleSpinBox(Camera);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        doubleSpinBox_4->setGeometry(QRect(20, 180, 46, 24));
        doubleSpinBox_4->setMinimum(-10);
        doubleSpinBox_4->setMaximum(10);
        doubleSpinBox_4->setSingleStep(0.5);
        label_5 = new QLabel(Camera);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 160, 41, 16));
        label_2 = new QLabel(Camera);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 41, 16));
        label_6 = new QLabel(Camera);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 90, 51, 16));
        tabWidget->addTab(Camera, QString());
        Ortho = new QWidget();
        Ortho->setObjectName(QString::fromUtf8("Ortho"));
        doubleSpinBox_19 = new QDoubleSpinBox(Ortho);
        doubleSpinBox_19->setObjectName(QString::fromUtf8("doubleSpinBox_19"));
        doubleSpinBox_19->setGeometry(QRect(20, 40, 62, 24));
        doubleSpinBox_19->setMinimum(-5);
        doubleSpinBox_19->setMaximum(10);
        doubleSpinBox_19->setSingleStep(0.5);
        doubleSpinBox_19->setValue(-2);
        doubleSpinBox_20 = new QDoubleSpinBox(Ortho);
        doubleSpinBox_20->setObjectName(QString::fromUtf8("doubleSpinBox_20"));
        doubleSpinBox_20->setGeometry(QRect(100, 40, 62, 24));
        doubleSpinBox_20->setMinimum(-5);
        doubleSpinBox_20->setMaximum(10);
        doubleSpinBox_20->setSingleStep(0.5);
        doubleSpinBox_20->setValue(2);
        doubleSpinBox_21 = new QDoubleSpinBox(Ortho);
        doubleSpinBox_21->setObjectName(QString::fromUtf8("doubleSpinBox_21"));
        doubleSpinBox_21->setGeometry(QRect(20, 120, 62, 24));
        doubleSpinBox_21->setMinimum(-5);
        doubleSpinBox_21->setMaximum(10);
        doubleSpinBox_21->setSingleStep(0.5);
        doubleSpinBox_21->setValue(-2);
        doubleSpinBox_22 = new QDoubleSpinBox(Ortho);
        doubleSpinBox_22->setObjectName(QString::fromUtf8("doubleSpinBox_22"));
        doubleSpinBox_22->setGeometry(QRect(100, 120, 62, 24));
        doubleSpinBox_22->setMinimum(-5);
        doubleSpinBox_22->setMaximum(10);
        doubleSpinBox_22->setSingleStep(0.5);
        doubleSpinBox_22->setValue(2);
        doubleSpinBox_23 = new QDoubleSpinBox(Ortho);
        doubleSpinBox_23->setObjectName(QString::fromUtf8("doubleSpinBox_23"));
        doubleSpinBox_23->setGeometry(QRect(20, 190, 62, 24));
        doubleSpinBox_23->setMinimum(-10);
        doubleSpinBox_23->setMaximum(10);
        doubleSpinBox_23->setSingleStep(0.5);
        doubleSpinBox_23->setValue(0);
        doubleSpinBox_24 = new QDoubleSpinBox(Ortho);
        doubleSpinBox_24->setObjectName(QString::fromUtf8("doubleSpinBox_24"));
        doubleSpinBox_24->setGeometry(QRect(100, 190, 62, 24));
        doubleSpinBox_24->setMinimum(-10);
        doubleSpinBox_24->setMaximum(10);
        doubleSpinBox_24->setSingleStep(0.5);
        doubleSpinBox_24->setValue(0);
        label_7 = new QLabel(Ortho);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 20, 60, 16));
        label_8 = new QLabel(Ortho);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(90, 20, 60, 16));
        label_9 = new QLabel(Ortho);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 100, 60, 16));
        label_10 = new QLabel(Ortho);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(100, 100, 60, 16));
        label_11 = new QLabel(Ortho);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 170, 71, 16));
        label_12 = new QLabel(Ortho);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(100, 170, 60, 16));
        tabWidget->addTab(Ortho, QString());
        Perspectiva = new QWidget();
        Perspectiva->setObjectName(QString::fromUtf8("Perspectiva"));
        doubleSpinBox_16 = new QDoubleSpinBox(Perspectiva);
        doubleSpinBox_16->setObjectName(QString::fromUtf8("doubleSpinBox_16"));
        doubleSpinBox_16->setGeometry(QRect(90, 30, 62, 24));
        doubleSpinBox_16->setValue(45);
        doubleSpinBox_17 = new QDoubleSpinBox(Perspectiva);
        doubleSpinBox_17->setObjectName(QString::fromUtf8("doubleSpinBox_17"));
        doubleSpinBox_17->setGeometry(QRect(90, 160, 62, 24));
        doubleSpinBox_17->setMinimum(-10);
        doubleSpinBox_17->setMaximum(10);
        doubleSpinBox_17->setSingleStep(0.5);
        doubleSpinBox_17->setValue(-2);
        doubleSpinBox_18 = new QDoubleSpinBox(Perspectiva);
        doubleSpinBox_18->setObjectName(QString::fromUtf8("doubleSpinBox_18"));
        doubleSpinBox_18->setGeometry(QRect(90, 210, 62, 24));
        doubleSpinBox_18->setMinimum(-10);
        doubleSpinBox_18->setMaximum(10);
        doubleSpinBox_18->setSingleStep(0.5);
        doubleSpinBox_18->setValue(10);
        label_13 = new QLabel(Perspectiva);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 30, 101, 16));
        label_14 = new QLabel(Perspectiva);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(20, 140, 81, 16));
        label_15 = new QLabel(Perspectiva);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(20, 200, 81, 16));
        label_16 = new QLabel(Perspectiva);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 70, 161, 31));
        label_17 = new QLabel(Perspectiva);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(90, 90, 161, 31));
        tabWidget->addTab(Perspectiva, QString());
        Frustum = new QWidget();
        Frustum->setObjectName(QString::fromUtf8("Frustum"));
        doubleSpinBox_10 = new QDoubleSpinBox(Frustum);
        doubleSpinBox_10->setObjectName(QString::fromUtf8("doubleSpinBox_10"));
        doubleSpinBox_10->setGeometry(QRect(10, 50, 62, 24));
        doubleSpinBox_10->setMinimum(-10);
        doubleSpinBox_10->setMaximum(10);
        doubleSpinBox_10->setSingleStep(0.5);
        doubleSpinBox_10->setValue(-1);
        doubleSpinBox_11 = new QDoubleSpinBox(Frustum);
        doubleSpinBox_11->setObjectName(QString::fromUtf8("doubleSpinBox_11"));
        doubleSpinBox_11->setGeometry(QRect(100, 50, 62, 24));
        doubleSpinBox_11->setMinimum(-10);
        doubleSpinBox_11->setMaximum(10);
        doubleSpinBox_11->setSingleStep(0.5);
        doubleSpinBox_11->setValue(1);
        doubleSpinBox_12 = new QDoubleSpinBox(Frustum);
        doubleSpinBox_12->setObjectName(QString::fromUtf8("doubleSpinBox_12"));
        doubleSpinBox_12->setGeometry(QRect(10, 120, 62, 24));
        doubleSpinBox_12->setMinimum(-10);
        doubleSpinBox_12->setMaximum(10);
        doubleSpinBox_12->setSingleStep(0.5);
        doubleSpinBox_12->setValue(-1);
        doubleSpinBox_13 = new QDoubleSpinBox(Frustum);
        doubleSpinBox_13->setObjectName(QString::fromUtf8("doubleSpinBox_13"));
        doubleSpinBox_13->setGeometry(QRect(100, 120, 62, 24));
        doubleSpinBox_13->setMinimum(-10);
        doubleSpinBox_13->setMaximum(10);
        doubleSpinBox_13->setSingleStep(0.5);
        doubleSpinBox_13->setValue(1);
        doubleSpinBox_14 = new QDoubleSpinBox(Frustum);
        doubleSpinBox_14->setObjectName(QString::fromUtf8("doubleSpinBox_14"));
        doubleSpinBox_14->setGeometry(QRect(10, 190, 62, 24));
        doubleSpinBox_14->setMinimum(-10);
        doubleSpinBox_14->setMaximum(10);
        doubleSpinBox_14->setSingleStep(0.5);
        doubleSpinBox_14->setValue(-1);
        doubleSpinBox_15 = new QDoubleSpinBox(Frustum);
        doubleSpinBox_15->setObjectName(QString::fromUtf8("doubleSpinBox_15"));
        doubleSpinBox_15->setGeometry(QRect(100, 190, 62, 24));
        doubleSpinBox_15->setMinimum(-10);
        doubleSpinBox_15->setMaximum(10);
        doubleSpinBox_15->setSingleStep(0.5);
        doubleSpinBox_15->setValue(1);
        label_18 = new QLabel(Frustum);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 30, 60, 16));
        label_19 = new QLabel(Frustum);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(100, 30, 60, 16));
        label_20 = new QLabel(Frustum);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 100, 60, 16));
        label_21 = new QLabel(Frustum);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(100, 100, 60, 16));
        label_22 = new QLabel(Frustum);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 170, 71, 16));
        label_23 = new QLabel(Frustum);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(100, 170, 60, 16));
        tabWidget->addTab(Frustum, QString());
        spinBox = new QSpinBox(frame);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(30, 170, 46, 24));
        spinBox->setMaximum(5);
        label_24 = new QLabel(frame);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(30, 150, 60, 16));

        horizontalLayout_2->addWidget(frame);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);

        retranslateUi(MainWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(close()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), MainWindow, SLOT(show_help()));
        QObject::connect(doubleSpinBox_5, SIGNAL(valueChanged(double)), widget, SLOT(setEyeX(double)));
        QObject::connect(doubleSpinBox_6, SIGNAL(valueChanged(double)), widget, SLOT(setEyeY(double)));
        QObject::connect(doubleSpinBox_7, SIGNAL(valueChanged(double)), widget, SLOT(setEyeZ(double)));
        QObject::connect(doubleSpinBox_3, SIGNAL(valueChanged(double)), widget, SLOT(setLookAtX(double)));
        QObject::connect(doubleSpinBox, SIGNAL(valueChanged(double)), widget, SLOT(setLookAtY(double)));
        QObject::connect(doubleSpinBox_2, SIGNAL(valueChanged(double)), widget, SLOT(setLookAtZ(double)));
        QObject::connect(doubleSpinBox_4, SIGNAL(valueChanged(double)), widget, SLOT(setUpX(double)));
        QObject::connect(doubleSpinBox_8, SIGNAL(valueChanged(double)), widget, SLOT(setUpY(double)));
        QObject::connect(doubleSpinBox_9, SIGNAL(valueChanged(double)), widget, SLOT(setUpZ(double)));
        QObject::connect(menuBar, SIGNAL(triggered(QAction*)), widget, SLOT(loadsphere()));
        QObject::connect(listWidget, SIGNAL(currentRowChanged(int)), widget, SLOT(mudaCorFundo(int)));
        QObject::connect(listWidget_2, SIGNAL(currentRowChanged(int)), widget, SLOT(set_projection(int)));
        QObject::connect(comboBox, SIGNAL(currentIndexChanged(int)), widget, SLOT(set_example(int)));
        QObject::connect(doubleSpinBox_19, SIGNAL(valueChanged(double)), widget, SLOT(setLeft(double)));
        QObject::connect(doubleSpinBox_20, SIGNAL(valueChanged(double)), widget, SLOT(setRight(double)));
        QObject::connect(doubleSpinBox_22, SIGNAL(valueChanged(double)), widget, SLOT(setTop(double)));
        QObject::connect(doubleSpinBox_21, SIGNAL(valueChanged(double)), widget, SLOT(setBottom(double)));
        QObject::connect(doubleSpinBox_23, SIGNAL(valueChanged(double)), widget, SLOT(setNearOrtho(double)));
        QObject::connect(doubleSpinBox_24, SIGNAL(valueChanged(double)), widget, SLOT(setFarOrtho(double)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), widget, SLOT(set_shine(int)));

        listWidget_2->setCurrentRow(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Wireframe", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Wireframe", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Flat", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Flat", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Phong", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Gourand", 0, QApplication::UnicodeUTF8)
        );
        pushButton->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Ilumina\303\247ao", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listWidget_2->isSortingEnabled();
        listWidget_2->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_2->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "Ortogonal", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listWidget_2->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "Perspectiva", 0, QApplication::UnicodeUTF8));
        listWidget_2->setSortingEnabled(__sortingEnabled);

        label_3->setText(QApplication::translate("MainWindow", "Proje\303\247ao", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled1 = listWidget_3->isSortingEnabled();
        listWidget_3->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem2 = listWidget_3->item(0);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "Flat", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem3 = listWidget_3->item(1);
        ___qlistwidgetitem3->setText(QApplication::translate("MainWindow", "Phong", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem4 = listWidget_3->item(2);
        ___qlistwidgetitem4->setText(QApplication::translate("MainWindow", "Gourand", 0, QApplication::UnicodeUTF8));
        listWidget_3->setSortingEnabled(__sortingEnabled1);

        label_67->setText(QApplication::translate("MainWindow", "R", 0, QApplication::UnicodeUTF8));
        label_68->setText(QApplication::translate("MainWindow", "G", 0, QApplication::UnicodeUTF8));
        label_69->setText(QApplication::translate("MainWindow", "B", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindow", "Ambiente", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Page", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled2 = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(0);
        ___qlistwidgetitem5->setText(QApplication::translate("MainWindow", "Amarelo", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem6 = listWidget->item(1);
        ___qlistwidgetitem6->setText(QApplication::translate("MainWindow", "Azul", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem7 = listWidget->item(2);
        ___qlistwidgetitem7->setText(QApplication::translate("MainWindow", "Branco", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem8 = listWidget->item(3);
        ___qlistwidgetitem8->setText(QApplication::translate("MainWindow", "Cinza", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem9 = listWidget->item(4);
        ___qlistwidgetitem9->setText(QApplication::translate("MainWindow", "Preto", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem10 = listWidget->item(5);
        ___qlistwidgetitem10->setText(QApplication::translate("MainWindow", "Verde", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem11 = listWidget->item(6);
        ___qlistwidgetitem11->setText(QApplication::translate("MainWindow", "Vermelho", 0, QApplication::UnicodeUTF8));
        listWidget->setSortingEnabled(__sortingEnabled2);

        label_4->setText(QApplication::translate("MainWindow", "Cor de Fundo", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Cor), QApplication::translate("MainWindow", "Cor", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        Camera->setToolTip(QApplication::translate("MainWindow", "Perspectiva", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("MainWindow", "Up", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Eye", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "LookAt", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Camera), QApplication::translate("MainWindow", "Camera", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Left", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Right", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Bottom", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Top", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "NearPlane", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "FarPlane", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Ortho), QApplication::translate("MainWindow", "Ortho", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Angle (fovy)", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "NearPlane", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "FarPlane", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "Aspect-predefined", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "parameter", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Perspectiva), QApplication::translate("MainWindow", "Perspectiva", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "Left", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "Right", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "Bottom", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "Top", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "NearPlane", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "FarPlane", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Frustum), QApplication::translate("MainWindow", "Frustum", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "Shine", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
