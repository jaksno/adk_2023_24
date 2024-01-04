#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <QtGui>
#include <tuple>

class Algorithms
{
public:
    Algorithms();

    int getPointAndLinePosition(QPointF &a, QPointF &p1, QPointF &p2);
    double get2LinesAngle(QPointF &p1, QPointF &p2, QPointF &p3, QPointF &p4);
    QPolygonF cHull(QPolygonF &b);
    QPolygonF rotate(QPolygonF &pol, double sigma);
    double area(QPolygonF &pol);
    std::tuple<double, QPolygonF> minMaxBox(QPolygonF &pol);
    QPolygonF minAreaEnclosingRect(QPolygonF &b);
    QPolygonF resRect(QPolygonF &rect, QPolygonF &b);
    QPolygonF simplifyAreaEnclosingRect(QPolygonF &b);
    QPolygonF simplifyWallAverage(QPolygonF &b);
    QPolygonF simplifyLongestEdge(QPolygonF &b);


};

#endif // ALGORITHMS_H
