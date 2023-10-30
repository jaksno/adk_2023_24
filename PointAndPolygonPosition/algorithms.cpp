#include "algorithms.h"

#include <cmath>
#include <iostream>

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
    double pi = M_PI;

    //Size of polygon
    int n = pol.size();

    //Process all vertices
    for (int i = 0; i < n ; i++)
    {
        //Compute omega
        double omega = get2LinesAngle(q, pol[i], q, pol[(i+1)%n]);

        //Analyze point and line position
        int pos = getPointAndLinePosition(q,pol[i],pol[(i+1)%n]);

        // Point on the edge of the polygon
        if (omega > pi-eps & omega < pi+eps) return -1; //  omega = pi

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

int Algorithms::getPointAndPolygonPositionRayCrossing(QPoint &q, QPolygon &pol) //Ray Crossing
{
    // Count of polygons in dataset
    int n = pol.size();

    // Inicialization of k = 0
    int k = 0;

    /* Repeat for points
     * for x coordinates */
    double xii = pol[0].x() - q.x();

    // for y coordinates
    double yii = pol[0].y() - q.y();

    // Process for all points
    for (int i = 1; i <= n; i++)
    {
        // Set a difference of coordinates
        double xi = pol[i%n].x() - q.x();
        double yi = pol[i%n].y() - q.y();

        /* xi = xi
         * xii = x(i-1) */

        // Search a good segment
        if ((yi > 0) && (yii <=0) || (yii >0) && (yi <=0))
        {

            // Search intersection
            double xm = (xi*yii - xii*yi)/(yi - yii);

            // Point is in the right half plane
            if (xm > 0)
                k++;
        }

        // Assign values
        xii = xi;
        yii = yi;
    }

    // Return amount of intersections
    return k%2;
}


int Algorithms::processAll(std::vector<QPolygon> &polygons, QPoint &point, int &algorithm_index){
    // method processes all polygons, returns id if point is inside else -1

    int res;

    for (int i = 0; i < int(polygons.size()); i++){

        if (algorithm_index==0){ // Winding method
            res = getPointAndPolygonPositionWinding(point, polygons[i]);
            if (res == 1) {return i;} // point is inside
            if (res == -1) {return -2;} // point lies on the edge
        }

        if (algorithm_index==1){ // Ray - crossing method
            res = getPointAndPolygonPositionRayCrossing(point, polygons[i]);
            if (res == 1) {return i;} // point is inside
    }
    }
    return -1; // point is outside
}


