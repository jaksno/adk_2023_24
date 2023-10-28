#include "algorithms.h"

#include <cmath>

Algorithms::Algorithms()
{

}

int Algorithms::getPointAndLinePosition(QPoint &a, QPoint &p1, QPoint &p2)
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


double Algorithms::get2LinesAngle(QPoint &p1, QPoint &p2, QPoint &p3, QPoint &p4)
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

int Algorithms::getPointAndPolygonPositionWinding(QPoint &q,QPolygon &pol)
{
    //Analyze point and polygon position (winding number algorithm)
    double omega_sum = 0;
    double eps = 1.0e-10;

    //Size of polygon
    int n = pol.size();

    //Process all vertices
    for (int i = 0; i < n ; i++)
    {
        //Compute omega
        double omega = get2LinesAngle(q, pol[i], q, pol[(i+1)%n]);

        //Analyze point and line position
        int pos = getPointAndLinePosition(q,pol[i],pol[(i+1)%n]);

        //Point in the left half plane
        if (pos == 1)
            omega_sum = omega_sum + omega;

        //Point in the right half plane
        else
            omega_sum = omega_sum - omega;
    }

    //Point outside
    if (fabs(omega_sum) < eps)
        return 0;

    //Point inside
    return 1;
}


int Algorithms::processAll(std::vector<QPolygon> &polygons, QPoint &point, int &algorithm_index){
    // method processes all polygons
    // returns "id"(order in vector) of polygon, which includes point OR {-1} if such polygon was not found

    int res;
    int id = -1; // id of polygon to be highlited

    for (int i = 0; i < int(polygons.size()); i++){

        if (algorithm_index==0){ // Winding

            res = getPointAndPolygonPositionWinding(point, polygons[i]);

            qDebug()<<res;

            if (res == 1) {
                id = i;
                qDebug()<<id;
                return id;

                // polygon found
            }
        }
        else { // Ray - crossing method

            // do the same here as below

        }
    }
    qDebug()<<id;
    return id;
}


