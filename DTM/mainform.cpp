#include "mainform.h"
#include "ui_mainform.h"
#include "algorithms.h"


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

