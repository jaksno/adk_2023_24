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
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <draw.h>

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QHBoxLayout *horizontalLayout;
    Draw *Canvas;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *pushButton_data;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton_3;

    void setupUi(QWidget *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName("MainForm");
        MainForm->resize(800, 600);
        horizontalLayout = new QHBoxLayout(MainForm);
        horizontalLayout->setObjectName("horizontalLayout");
        Canvas = new Draw(MainForm);
        Canvas->setObjectName("Canvas");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Canvas->sizePolicy().hasHeightForWidth());
        Canvas->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(Canvas);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(MainForm);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        comboBox = new QComboBox(MainForm);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        verticalLayout->addWidget(comboBox);

        pushButton_data = new QPushButton(MainForm);
        pushButton_data->setObjectName("pushButton_data");

        verticalLayout->addWidget(pushButton_data);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_2 = new QPushButton(MainForm);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        label_2 = new QLabel(MainForm);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        pushButton_3 = new QPushButton(MainForm);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(MainForm);

        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QWidget *MainForm)
    {
        MainForm->setWindowTitle(QCoreApplication::translate("MainForm", "Analyze point and polygon position", nullptr));
        label->setText(QCoreApplication::translate("MainForm", "Method", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainForm", "Winding number", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainForm", "Ray crossing", nullptr));

        pushButton_data->setText(QCoreApplication::translate("MainForm", "Import data", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainForm", "Analyze position", nullptr));
        label_2->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("MainForm", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
