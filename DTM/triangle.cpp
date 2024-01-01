#include "triangle.h"

Triangle::Triangle(const QPointF3D &v1_, const QPointF3D &v2_, const QPointF3D &v3_, double slope_, double asp_)
{
    v1 = v1_;
    v2 = v2_;
    v3 = v3_;
    slope = slope_;
    asp = asp_;
}
