#ifndef SORTPOINTSBYX_H
#define SORTPOINTSBYX_H

#include <QtGui>

class sortPointsByX
{
public:
    sortPointsByX();
    bool  operator()(QPointF &p1, QPointF &p2) {return p1.x() < p2.x();}
};

#endif // SORTPOINTSBYX_H
