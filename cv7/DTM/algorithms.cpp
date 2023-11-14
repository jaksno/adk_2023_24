#include "algorithms.h"
#include "sortpointsbyx.h"
#include <cmath>

Algorithms::Algorithms()
{

}


int Algorithms::getPointAndLinePosition(const QPointF3D &a, const QPointF3D &p1, const QPointF3D &p2)
{
    //Analyze point and line position
    double eps = 1.0e-10;

    //Cordinate differencies
    double ux = p2.x() - p1.x();
    double uy = p2.y() - p1.y();
    double vx = a.x() - p1.x();
    double vy = a.y() - p1.y();

    //Test
    double t = ux * vy - vx * uy;

    //Point in the left halfplane
    if(t > eps)
        return 1;

    //Point in the right halfplane
    if(t < -eps)
        return 0;

    //Point on the line
    return -1;
}


double Algorithms::get2LinesAngle(const QPointF3D &p1, const QPointF3D &p2, const QPointF3D &p3, const QPointF3D &p4)
{
    //Compute angle between two lines

    //Cordinate differencies
    double ux = p2.x() - p1.x();
    double uy = p2.y() - p1.y();
    double vx = p4.x() - p3.x();
    double vy = p4.y() - p3.y();

    //Compute dot product
    double dot = ux * vx + uy * vy;

    //Vector norm
    double nu = sqrt(ux*ux + uy*uy);
    double nv = sqrt(vx*vx + vy*vy);

    //Compute angle
    return acos(dot/(nu*nv));
}

int Algorithms::getNearestPoint(const QPointF3D &q, const std::vector<QPointF3D> &points)
{
    //Find nearest point
    int imin = -1;
    double dmin = 1.0e10;

    // Browse all points
    for(int i = 0; i < points.size(); i++)
    {
        // Point q is different from points[i]
        if(q != points[i])
        {
            // Compute distance
            double d = getDistance2D(q, points[i]);
            // Update minimum distance
            if (d < dmin)
            {
                dmin = d;
                imin = i;
            }
        }
    }

    return imin;
}


int Algorithms::getDelaunayPoint(const QPointF3D &s, const QPointF3D &e, const std::vector<QPointF3D> &points)
{
    //Find nearest point
    int imax = -1;
    double omax = 0;

    // Browse all points
    for(int i = 0; i < points.size(); i++)
    {
        // Points s and e are different from points[i]
        if(s != points[i] && e != points[i])
        {
            // Point in the left half-plane
            if (getPointAndLinePosition(points[i], s, e) == 1)
            {
                // Compute angle
                double o = get2LinesAngle(points[i], s, points[i], e);

                //Update maximum
                if (o > omax)
                {
                    omax = o;
                    imax = i;
                }

             }
        }
    }

    return imax;
}



double Algorithms::getDistance2D(const QPointF3D &p1, const QPointF3D &p2){

    //Compute 2D distance
    double dx = p2.x() - p1.x();
    double dy = p2.y() - p1.y();

    return sqrt(dx*dx + dy*dy);

}

















