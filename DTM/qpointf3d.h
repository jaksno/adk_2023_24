#ifndef QPOINTF3D_H
#define QPOINTF3D_H

#include <QtGui>

class QPointF3D : public QPointF
{
private:
    double z;

public:
    QPointF3D(double x, double y, double z_):QPointF(x,y){z = z_;}
    QPointF3D():QPointF(0,0){z = 0;}

    double getZ() const {return z;}
    void setZ(double z_){z = z_;}

};

#endif // QPOINTF3D_H
