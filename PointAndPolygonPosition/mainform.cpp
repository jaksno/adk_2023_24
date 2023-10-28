#include "mainform.h"
#include "ui_mainform.h"
#include "algorithms.h"
#include "data.h"
#include <QFileDialog>
#include <iostream>


using namespace std;

MainForm::MainForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainForm)
{
    ui->setupUi(this);
}

MainForm::~MainForm()
{
    delete ui;
}


void MainForm::on_pushButton_3_clicked()
{
    //Clear content
    ui->Canvas->clear();
    ui->label_2->clear();

    //Repaint
    repaint();
}


void MainForm::on_pushButton_2_clicked()
{
    //Run analysis

    //Get data
    QPoint q = ui->Canvas->getQ();
    QPolygon pol = ui->Canvas->getPol();
    vector<QPolygon> polygons_data = ui->Canvas->getPolData();

    //Which method will be used
    int index =  ui->comboBox->currentIndex();

    //Run analysis
    Algorithms a;
    int pols_to_highlight = a.processAll(polygons_data, q, index);

    //Set result in label
    if (pols_to_highlight == 1 && index == 0)
        ui->label_2->setText(" Winding number\n Point is INSIDE");
    if (pols_to_highlight == 0 && index == 0)
        ui->label_2->setText(" Winding number\n Point is OUTSIDE");
    if (pols_to_highlight == 1 && index == 1)
        ui->label_2->setText(" Ray - Crossing\n Point is INSIDE");
    if (pols_to_highlight == 0 && index == 1)
        ui->label_2->setText(" Ray - Crossing\n Point is OUTSIDE");
}

void MainForm::on_pushButton_data_clicked()
{
    // IMPORTS POLYGON/S DATA

    // create Data object
    Data read_data;
    // open file dialog
    QString data_filepath(QFileDialog::getOpenFileName(this, tr("Import data"), "../", tr("TXT Files (*.txt)")));
    // read data
    vector<QPolygon> polygons = read_data.readPolygonsFromFile(data_filepath);
    // draw polygons
    ui->Canvas->drawPolygons(polygons);

}

