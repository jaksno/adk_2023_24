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

    //Repaint
    repaint();
}

void MainForm::on_pushButton_clicked()
{
    //Change source: add point q / polygon vertex
    ui->Canvas->setSource();
}

void MainForm::on_pushButton_2_clicked()
{
    //Run analysis

    //Get data
    QPoint q = ui->Canvas->getQ();
    QPolygon pol = ui->Canvas->getPol();

    //Which method will be used
    int index =  ui->comboBox->currentIndex();

    //Run analysis
    Algorithms a;
    int res;

    if (index == 0)
        res = a.getPointAndPolygonPositionWinding(q, pol);


    //Print result
    if (res == 1)
        ui->label_2->setText("Inside");

    else
        ui->label_2->setText("Outside");
}

void MainForm::on_pushButton_data_clicked()
{
    // IMPORTS POLYGON/S SPAGHETTI MODEL DATA

    Data read_data;
    // open file dialog (return QString file-path)
    QString data_filepath(QFileDialog::getOpenFileName(this, tr("Import data"), "../", tr("TXT Files (*.txt)")));
    // read data
    vector<QPolygon> polygons = read_data.readPolygonsFromFile(data_filepath);
    // draw polygons
}

