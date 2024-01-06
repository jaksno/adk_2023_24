#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include <vector>
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
    double scale, x_t, y_t;
    int x_d, y_d;

public:
    explicit Draw(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void clear(){points.clear();}
    std::vector <QPointF3D> getPoints(){return points;}
    std::vector<Edge> getDT(){return dt;}
    void setDT(std::vector<Edge> &dt_){dt = dt_;}
    void setContourLines(const std::vector<Edge> &contour_lines_){contour_lines = contour_lines_;}
    void setTriangles(std::vector<Triangle> &triangles_){triangles = triangles_;}
    void setAnalysis(bool analysis_){analysis=analysis_;}
    void clearAll(){points.clear(); dt.clear(); contour_lines.clear(); triangles.clear();}
    void clearRes(){dt.clear(); contour_lines.clear(); triangles.clear();}
    void clearContour(){contour_lines.clear();}
    void drawPoints(std::vector<QPointF3D> &points3d);
    void setCSVPoints(std::vector<QPointF3D> &csv){points.insert(points.end(), csv.begin(), csv.end());}
    void setScale(double &scale_){scale = scale_;}
    void setTrans(double &x_t_, double &y_t_){x_t = x_t_; y_t = y_t_;}
    void setOffsets(int &x_d_, int &y_d_){x_d = x_d_; y_d = y_d_;}
    double getScale(){return scale;}
    double getTransX(){return x_t;}
    double getTransY(){return y_t;}
    int getDeltaX(){return x_d;}
    int getDeltaY(){return y_d;}


signals:

public slots:
};

#endif // DRAW_H
