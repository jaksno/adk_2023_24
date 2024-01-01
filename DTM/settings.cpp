#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    //Initialize values
    zmin = 0;
    zmax = 1000;
    dz = 10;

    //Show values in line edits
    ui->lineEdit->setText(QString::number(zmin));
    ui->lineEdit_2->setText(QString::number(zmax));
    ui->lineEdit_3->setText(QString::number(dz));

}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_lineEdit_editingFinished()
{
    //Get zmin
    zmin = ui->lineEdit->text().toDouble();
}

void Settings::on_lineEdit_2_editingFinished()
{
    //Get zmax
    zmax = ui->lineEdit_2->text().toDouble();
}

void Settings::on_lineEdit_3_editingFinished()
{
    //Get interval
    dz = ui->lineEdit_3->text().toDouble();
}
