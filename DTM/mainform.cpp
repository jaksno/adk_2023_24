#include "mainform.h"
#include "ui_mainform.h"
#include "algorithms.h"
#include "draw.h"
#include "csvfile.h"
#include <iostream>
#include <QtGui>
#include <QFileDialog>
#include <QMessageBox>

MainForm::MainForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainForm)
{
    ui->setupUi(this);

    //Initialize values
    zmin = 0;
    zmax = 1000;
    dz = 10;
}

MainForm::~MainForm()
{
    delete ui;
}


void MainForm::on_actionCreate_DTM_triggered()
{
    // Clear result
    ui->Canvas->clearRes();

    //Create Delaunay triangulation
    std::vector <QPointF3D> points = ui->Canvas->getPoints();

    //Create DT
    Algorithms a;
    std:: vector <Edge> dt = a.createDT(points);

    //Set results
    ui->Canvas->setDT(dt);

    repaint();
}


void MainForm::on_actionContour_lines_triggered()
{
    //Create contour lines
    std::vector <Edge> dt = ui ->Canvas->getDT();


    //Do we have a triangulation
    Algorithms a;
    if (dt.size() == 0)
    {
        //Create Delaunay triangulation
        std::vector <QPointF3D> points = ui->Canvas->getPoints();

        //Create DT
        std:: vector <Edge> dt = a.createDT(points);
    }

    //Create contour lines
    std::vector<Edge> contour_lines = a.createContourLines(dt, zmin, zmax, dz);

    //Set results
    ui -> Canvas -> setContourLines(contour_lines);

    repaint();
}

void MainForm::on_actionAnalyze_slope_triggered()
{
    //Clear contour lines
    ui -> Canvas -> clearContour();

    //Analyze slope
    std::vector <Edge> dt = ui ->Canvas->getDT();

    //Set slope
    ui -> Canvas -> setAnalysis(true);

    //Do we have a triangulation
    Algorithms a;
    if (dt.size() == 0)
    {
        //Create Delaunay triangulation
        std::vector <QPointF3D> points = ui->Canvas->getPoints();

        //Create DT
        std:: vector <Edge> dt = a.createDT(points);
    }

    // Analyze DTM
    std::vector <Triangle> triangles = a.analyzeDTMSlope(dt);

    //Set results
    ui -> Canvas -> setTriangles(triangles);

    repaint();
}

void MainForm::on_actionAnalyze_aspect_triggered()
{
    //Clear contour lines
    ui -> Canvas -> clearContour();

    //Analyze aspect
    std::vector <Edge> dt = ui ->Canvas->getDT();

    //Set aspect
    ui -> Canvas -> setAnalysis(false);

    //Do we have a triangulation
    Algorithms a;
    if (dt.size() == 0)
    {
        //Create Delaunay triangulation
        std::vector <QPointF3D> points = ui->Canvas->getPoints();

        //Create DT
        std:: vector <Edge> dt = a.createDT(points);
    }

    // Analyze DTM
    std::vector <Triangle> triangles = a.analyzeDTMAspect(dt);

    //Set results
    ui -> Canvas -> setTriangles(triangles);

    repaint();
}

void MainForm::on_actionSettings_triggered()
{
    //Open setting dialog
   if(s.exec()== QDialog::Accepted)
    {
       //Get values
       zmin = s.getZmin();
       zmax = s.getZmax();
       dz = s.getDz();
   }
}

void MainForm::on_actionExit_triggered()
{
   // Quit app
   QApplication::quit();
}


void MainForm::on_actionClear_all_triggered()
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


void MainForm::on_actionOpen_triggered()
{

   //Create Minmax box coors for our data
   double xmin =  10.e12;
   double xmax = -10.e12;
   double ymin =  10.e12;
   double ymax = -10.e12;

   //Choose data
   QString path(QFileDialog::getOpenFileName(this, tr("Open point cloud"), "../", tr("CSV Files (*.csv)")));

   //Convert to string path
   std::string filename = path.toStdString();

   if (filename.length() > 0)
   {
       // Clear all
       ui->Canvas->clearAll();

       // Read the chosen file
       std::vector<QPointF3D> points = csv::getPointsFromFile(filename, xmin, xmax, ymin, ymax);

       // Get sizes
       int canvas_width = ui->Canvas->size().width();
       int canvas_height = ui->Canvas->size().height();
       double data_width = xmax - xmin;
       double data_height = ymax - ymin;
       double x_ratio = canvas_width/data_width;
       double y_ratio = canvas_height/data_height;

       // Get scale
       double scale;
       if (x_ratio > y_ratio)
           scale = y_ratio;
       else
           scale = x_ratio;

       // Coordinates of datasets and canvas
       int x_left_canvas = ui->Canvas->geometry().x();
       int y_left_canvas = ui->Canvas->geometry().y();
       int x_dataset = ui->Canvas->x();
       int y_dataset = ui->Canvas->y();
       int center_canvas_width = x_left_canvas + (canvas_width/2);
       int center_canvas_height = y_left_canvas + (canvas_height/2);
       int center_dataset_x = x_dataset + (data_width/2);
       int center_dataset_y = y_dataset + (canvas_height/2);
       double x_trans = xmin - x_left_canvas;
       double y_trans = ymin - y_left_canvas;

       // Set
       ui->Canvas->setScale(scale);
       ui->Canvas->setOffsets(x_dataset, y_dataset);
       ui->Canvas->setTrans(x_trans, y_trans);
       ui->Canvas->drawPoints(points);
   }
}

