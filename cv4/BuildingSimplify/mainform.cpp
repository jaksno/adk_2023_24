#include "mainform.h"
#include "ui_mainform.h"
#include "algorithms.h"

MainForm::MainForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainForm)
{
    ui->setupUi(this);
}

MainForm::~MainForm()
{
    delete ui;
}


void MainForm::on_actionOpen_triggered()
{

}

void MainForm::on_actionMin_Area_Rectangle_triggered()
{
    //Simplify building using MAER

    //Get data
    QPolygonF b = ui -> Canvas -> getBuilding();

    //Simplify
    Algorithms a;
    QPolygonF bs = a.simplifyAreaEnclosingRect(b);

    //Set data
    ui->Canvas->setSimplifiedBuilding(bs);

    //Repaint
    repaint();
}

void MainForm::on_actionWall_Average_triggered()
{
     //Simplify building using WA
}
