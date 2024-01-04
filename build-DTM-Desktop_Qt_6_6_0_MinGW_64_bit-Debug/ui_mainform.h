/********************************************************************************
** Form generated from reading UI file 'mainform.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "draw.h"

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionCreate_DTM;
    QAction *actionContour_lines;
    QAction *actionAnalyze_slope;
    QAction *actionAnalyze_aspect;
    QAction *actionClear_results;
    QAction *actionClear_all;
    QAction *actionSettings;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    Draw *Canvas;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAnalysis;
    QMenu *menuView;
    QMenu *menuOptions;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName("MainForm");
        MainForm->resize(1275, 844);
        actionOpen = new QAction(MainForm);
        actionOpen->setObjectName("actionOpen");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/open_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionExit = new QAction(MainForm);
        actionExit->setObjectName("actionExit");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        actionCreate_DTM = new QAction(MainForm);
        actionCreate_DTM->setObjectName("actionCreate_DTM");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/triangles2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreate_DTM->setIcon(icon2);
        actionContour_lines = new QAction(MainForm);
        actionContour_lines->setObjectName("actionContour_lines");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/icons/contours2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionContour_lines->setIcon(icon3);
        actionAnalyze_slope = new QAction(MainForm);
        actionAnalyze_slope->setObjectName("actionAnalyze_slope");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/icons/slope2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAnalyze_slope->setIcon(icon4);
        actionAnalyze_aspect = new QAction(MainForm);
        actionAnalyze_aspect->setObjectName("actionAnalyze_aspect");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/icons/orientation2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAnalyze_aspect->setIcon(icon5);
        actionClear_results = new QAction(MainForm);
        actionClear_results->setObjectName("actionClear_results");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/icons/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear_results->setIcon(icon6);
        actionClear_all = new QAction(MainForm);
        actionClear_all->setObjectName("actionClear_all");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/icons/clear_er.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear_all->setIcon(icon7);
        actionSettings = new QAction(MainForm);
        actionSettings->setObjectName("actionSettings");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/icons/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon8);
        centralwidget = new QWidget(MainForm);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        Canvas = new Draw(centralwidget);
        Canvas->setObjectName("Canvas");

        horizontalLayout->addWidget(Canvas);

        MainForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainForm);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1275, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuAnalysis = new QMenu(menubar);
        menuAnalysis->setObjectName("menuAnalysis");
        menuView = new QMenu(menubar);
        menuView->setObjectName("menuView");
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName("menuOptions");
        MainForm->setMenuBar(menubar);
        statusbar = new QStatusBar(MainForm);
        statusbar->setObjectName("statusbar");
        MainForm->setStatusBar(statusbar);
        toolBar = new QToolBar(MainForm);
        toolBar->setObjectName("toolBar");
        MainForm->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuAnalysis->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuOptions->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuAnalysis->addAction(actionCreate_DTM);
        menuAnalysis->addSeparator();
        menuAnalysis->addAction(actionContour_lines);
        menuAnalysis->addAction(actionAnalyze_slope);
        menuAnalysis->addAction(actionAnalyze_aspect);
        menuView->addAction(actionClear_results);
        menuView->addAction(actionClear_all);
        menuOptions->addAction(actionSettings);
        toolBar->addAction(actionOpen);
        toolBar->addSeparator();
        toolBar->addAction(actionCreate_DTM);
        toolBar->addSeparator();
        toolBar->addAction(actionContour_lines);
        toolBar->addAction(actionAnalyze_slope);
        toolBar->addAction(actionAnalyze_aspect);
        toolBar->addSeparator();
        toolBar->addAction(actionClear_results);
        toolBar->addAction(actionClear_all);
        toolBar->addSeparator();
        toolBar->addAction(actionSettings);
        toolBar->addSeparator();
        toolBar->addAction(actionExit);

        retranslateUi(MainForm);

        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QMainWindow *MainForm)
    {
        MainForm->setWindowTitle(QCoreApplication::translate("MainForm", "DTM analysis", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainForm", "Open", nullptr));
        actionExit->setText(QCoreApplication::translate("MainForm", "Exit", nullptr));
        actionCreate_DTM->setText(QCoreApplication::translate("MainForm", "Create DTM", nullptr));
        actionContour_lines->setText(QCoreApplication::translate("MainForm", "Contour lines", nullptr));
        actionAnalyze_slope->setText(QCoreApplication::translate("MainForm", "Analyze slope", nullptr));
        actionAnalyze_aspect->setText(QCoreApplication::translate("MainForm", "Analyze aspect", nullptr));
        actionClear_results->setText(QCoreApplication::translate("MainForm", "Clear results", nullptr));
        actionClear_all->setText(QCoreApplication::translate("MainForm", "Clear all", nullptr));
        actionSettings->setText(QCoreApplication::translate("MainForm", "Settings", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainForm", "File", nullptr));
        menuAnalysis->setTitle(QCoreApplication::translate("MainForm", "Analysis", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainForm", "View", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainForm", "Options", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainForm", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
