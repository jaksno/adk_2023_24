#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <QtGui>
#include <vector>
#include <list>
#include "QPointF3D.h"
#include "edge.h"
#include "triangle.h"

class Algorithms
{
public:
    Algorithms();

    int getPointAndLinePosition(const QPointF3D &a, const QPointF3D &p1, const QPointF3D &p2);
    double get2LinesAngle(const QPointF3D &p1, const QPointF3D &p2, const QPointF3D &p3, const QPointF3D &p4);
    int getNearestPoint(const QPointF3D &q, const std::vector<QPointF3D> &points);
    int getDelaunayPoint(const QPointF3D &s, const QPointF3D &e, const std::vector<QPointF3D> &points);
    double getDistance2D(const QPointF3D &p1, const QPointF3D &p2);
    std::vector<Edge> createDT(std::vector <QPointF3D> &points);
    void updateAEL(Edge &edge, std::list<Edge> &ael);
    QPointF3D contourPoint(const QPointF3D &p1, const QPointF3D &p2, double z);
    std::vector<Edge> createContourLines(const std::vector<Edge> &dt, double z_min, double z_max, double dz);
    std::vector<Triangle> analyzeDTMSlope(const std::vector<Edge> &dt);
    std::vector<Triangle> analyzeDTMAspect(const std::vector<Edge> &dt);
    double computeSlope(const QPointF3D &v1, const QPointF3D &v2, const QPointF3D &v3);
    double computeAspect(const QPointF3D &v1, const QPointF3D &v2, const QPointF3D &v3);

};

#endif // ALGORITHMS_H
