#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include "settings.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainForm; }
QT_END_NAMESPACE

class MainForm : public QMainWindow
{
    Q_OBJECT

private:
    double zmin, zmax, dz;
    Settings s;

public:
    MainForm(QWidget *parent = nullptr);
    ~MainForm();

private slots:
    void on_actionCreate_DTM_triggered();

    void on_actionContour_lines_triggered();

    void on_actionAnalyze_slope_triggered();

    void on_actionAnalyze_aspect_triggered();

    void on_actionSettings_triggered();

    void on_actionExit_triggered();

    void on_actionClear_all_triggered();

    void on_actionClear_results_triggered();

private:
    Ui::MainForm *ui;
};
#endif // MAINFORM_H
