/********************************************************************************
** Form generated from reading UI file 'mainform.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
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
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    Draw *Canvas;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAnalysis;
    QMenu *menuView;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName(QString::fromUtf8("MainForm"));
        MainForm->resize(1275, 844);
        actionOpen = new QAction(MainForm);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionExit = new QAction(MainForm);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionCreate_DTM = new QAction(MainForm);
        actionCreate_DTM->setObjectName(QString::fromUtf8("actionCreate_DTM"));
        actionContour_lines = new QAction(MainForm);
        actionContour_lines->setObjectName(QString::fromUtf8("actionContour_lines"));
        actionAnalyze_slope = new QAction(MainForm);
        actionAnalyze_slope->setObjectName(QString::fromUtf8("actionAnalyze_slope"));
        actionAnalyze_aspect = new QAction(MainForm);
        actionAnalyze_aspect->setObjectName(QString::fromUtf8("actionAnalyze_aspect"));
        actionClear_results = new QAction(MainForm);
        actionClear_results->setObjectName(QString::fromUtf8("actionClear_results"));
        actionClear_all = new QAction(MainForm);
        actionClear_all->setObjectName(QString::fromUtf8("actionClear_all"));
        centralwidget = new QWidget(MainForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Canvas = new Draw(centralwidget);
        Canvas->setObjectName(QString::fromUtf8("Canvas"));

        horizontalLayout->addWidget(Canvas);

        MainForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainForm);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1275, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAnalysis = new QMenu(menubar);
        menuAnalysis->setObjectName(QString::fromUtf8("menuAnalysis"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainForm->setMenuBar(menubar);
        statusbar = new QStatusBar(MainForm);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainForm->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuAnalysis->menuAction());
        menubar->addAction(menuView->menuAction());
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
        menuFile->setTitle(QCoreApplication::translate("MainForm", "File", nullptr));
        menuAnalysis->setTitle(QCoreApplication::translate("MainForm", "Analysis", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainForm", "View", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
