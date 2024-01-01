#ifndef DRAW_H
#define DRAW_H

#include <QWidget>

#include "QPointF3D.h"
#include "triangle.h"
#include "edge.h"

class Draw : public QWidget
{
    Q_OBJECT

private:
    bool analysis;
    std::vector <QPointF3D> points;
    std::vector <Edge> dt;
    std::vector <Edge> contour_lines;
    std::vector <Triangle> triangles;

public:
    explicit Draw(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void clear(){points.clear();}
    std::vector <QPointF3D> getPoints(){return points;}
    std::vector<Edge> getDT(){return dt;}
    void setDT(std::vector<Edge> &dt_){dt = dt_;}
    void setContourLines(const std::vector<Edge> &contour_lines_){contour_lines = contour_lines_;}
    void setTriangles(std::vector<Triangle> &triangles_){triangles = triangles_;}
    void setAnalysis(bool analysis_){analysis=analysis_;}


signals:

public slots:
};

#endif // DRAW_H
