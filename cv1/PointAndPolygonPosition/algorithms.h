#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <QtGui>

class Algorithms
{
public:
    Algorithms();

    int getPointAndLinePosition(QPoint &a, QPoint &p1, QPoint &p2);
    double get2LinesAngle(QPoint &p1, QPoint &p2, QPoint &p3, QPoint &p4);
    int getPointAndPolygonPositionWinding(QPoint &q,QPolygon &pol);
};

#endif // ALGORITHMS_H
