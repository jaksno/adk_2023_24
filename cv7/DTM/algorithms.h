#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <QtGui>
#include <vector>

#include "QPointF3D.h"

class Algorithms
{
public:
    Algorithms();

    int getPointAndLinePosition(const QPointF3D &a, const QPointF3D &p1, const QPointF3D &p2);
    double get2LinesAngle(const QPointF3D &p1, const QPointF3D &p2, const QPointF3D &p3, const QPointF3D &p4);
    int getNearestPoint(const QPointF3D &q, const std::vector<QPointF3D> &points);
    int getDelaunayPoint(const QPointF3D &s, const QPointF3D &e, const std::vector<QPointF3D> &points);
    double getDistance2D(const QPointF3D &p1, const QPointF3D &p2);

};

#endif // ALGORITHMS_H
