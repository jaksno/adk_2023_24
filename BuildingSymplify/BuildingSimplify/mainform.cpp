#include "mainform.h"
#include "ui_mainform.h"
#include "algorithms.h"
#include "wkt.h"

#include <string>
#include <iostream>
#include <QFileDialog>
#include <vector>

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
    wkt csvObject;
    double xmin =  1e20;
    double xmax = -1e20;
    double ymin =  1e20;
    double ymax = -1e20;

    // Choose file and save
    QString file_path(QFileDialog::getOpenFileName(this, tr("Open WKT file"), "../", tr("CSV files (*.csv)")));
    std::string filename = file_path.toStdString();
    std::vector<QPolygonF> polygonVector = csvObject.readFile(filename, xmin, xmax, ymin, ymax);

    // Get size and transform
    double c_height = ui->Canvas->size().height();
    double c_width = ui->Canvas->size().width();
    double x_corner = ui->Canvas->geometry().x();
    double y_corner = ui->Canvas->geometry().y();
    double d_height = ymax - ymin;
    double d_width = xmax - xmin;
    double x_m = d_width/c_width;
    double y_m = d_height/c_height;
    double x_t = xmin - x_corner;
    double y_t = ymin - y_corner;

    // Clear all
    ui->Canvas->clearAll();

    // Draw polygons
    ui->Canvas->drawPolygons(polygonVector, x_t, y_t, x_m, y_m);

}

void MainForm::on_actionMin_Area_Rectangle_triggered()
{
    //Simplify building using MAER

    //Get data
    std::vector<QPolygonF> b = ui -> Canvas -> getBuilding();

    //Simplify
    Algorithms a;
    Algorithms a1;
    std::vector<QPolygonF> bs;
    std::vector<QPolygonF> ch;

    // For each building in b
    for (QPolygonF building : b)
    {
        bs.push_back(a.simplifyAreaEnclosingRect(building));
        ch.push_back(a1.cHull(building));
    }

    //Set data
    ui->Canvas->setSimplifiedBuilding(bs);
    ui->Canvas->setConvexBuilding(ch);

    //Repaint
    repaint();
}

void MainForm::on_actionWall_Average_triggered()
{
    //Simplify building using WA

    //Get data
    std::vector<QPolygonF> b = ui -> Canvas -> getBuilding();

    //Simplify
    Algorithms a;
    Algorithms a1;
    std::vector<QPolygonF> bs;
    std::vector<QPolygonF> ch;

    // For each building in b
    for (QPolygonF building : b)
    {
        bs.push_back(a.simplifyWallAverage(building));
        ch.push_back(a1.cHull(building));
    }

    //Set data
    ui->Canvas->setSimplifiedBuilding(bs);
    ui->Canvas->setConvexBuilding(ch);

    //Repaint
    repaint();
}

void MainForm::on_actionLongest_Edge_triggered()
{
    //Simplify building using Longest Edge

    //Get data
    std::vector<QPolygonF> b = ui -> Canvas -> getBuilding();

    //Simplify
    Algorithms a;
    Algorithms a1;
    std::vector<QPolygonF> bs;
    std::vector<QPolygonF> ch;

    // For each building in b
    for (QPolygonF building : b)
    {
        bs.push_back(a.simplifyLongestEdge(building));
        ch.push_back(a1.cHull(building));
    }

    //Set data
    ui->Canvas->setSimplifiedBuilding(bs);
    ui->Canvas->setConvexBuilding(ch);

    //Repaint
    repaint();
}

void MainForm::on_actionClear_All_triggered()
{
    // Clear all
    ui->Canvas->clearAll();
    repaint();
}


void MainForm::on_actionClear_results_triggered()
{
    // Clear result
    ui->Canvas->clearRes();
    repaint();
}


void MainForm::on_actionExit_triggered()
{
    // Quit app
    QApplication::quit();
}




