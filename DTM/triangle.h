#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "qpointf3d.h"

class Triangle
{
private:
    QPointF3D v1, v2, v3;
    double slope, asp;

public:
    Triangle(const QPointF3D &v1_, const QPointF3D &v2_, const QPointF3D &v3_, double slope_, double asp_);
    QPointF3D getV1(){return v1;}
    QPointF3D getV2(){return v2;}
    QPointF3D getV3(){return v3;}
    double getSlope(){return slope;}
    double getAspect(){return asp;}
};

#endif // TRIANGLE_H
