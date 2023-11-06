#include "algorithms.h"
#include "sortpointsbyy.h"
#include "sortpointsbyx.h"
#include <cmath>

Algorithms::Algorithms()
{

}


int Algorithms::getPointAndLinePosition(QPointF &a, QPointF &p1, QPointF &p2)
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


double Algorithms::get2LinesAngle(QPointF &p1, QPointF &p2, QPointF &p3, QPointF &p4)
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


QPolygonF Algorithms::cHull(QPolygonF &b)
{
    //Create Jarvis Scan
    QPolygonF ch;

    //Find pivots
    QPointF qy = *std::min_element(b.begin(), b.end(), sortPointsByY());
    QPointF qx = *std::min_element(b.begin(), b.end(), sortPointsByX());

    //Add point to convex hull
    ch.push_back(qy);

    //Create pjj
    QPointF pjj (qx.x(),qy.y());

    // pj inicialization
    QPointF pj = qy;

    //Repeat
    do
    {
        //Initialization of max angle
        double om_max = 0;
        int i_max = -1;

        //Process all points
        for(int i = 0; i < b.size(); i++){
            //Compute angle
            double om = get2LinesAngle(pj, pjj, pj, b[i]);

            //Compare to max
            if (om > om_max)
            {
                om_max = om;
                i_max = i;
            }
        }

        //Add point to cHull
        ch.push_back(b[i_max]);

        //Assign last 2 points
        pjj = pj;
        pj = b[i_max];

    } while (pj != qy);


    return ch;
}


QPolygonF Algorithms::rotate(QPolygonF &pol, double sigma)
{
    // Rotate polygon by sigma
    QPolygonF pol_rotate;

    //Process all points
    for(QPointF p:pol){

        //Rotate a point
        double Xr = cos(sigma) * p.x() - sin(sigma) * p.y();
        double Yr = sin(sigma) * p.x() + cos(sigma) * p.y();

        // Create new point
        QPointF pr(Xr, Yr);

        // Add point to rotated polygon
        pol_rotate.push_back(pr);
    }

    return pol_rotate;
}


double Algorithms::area(QPolygonF &pol)
{
    //Calculate area - method LH
    int n = pol.size();
    double A = 0;

    //Process all points
    for(int i=0; i<n; i++)
    {
        // Area increment
        A = A + pol[i].x() * (pol[(i+1)%n].y() - pol[(i-1+n)%n].y());
    }

    return fabs(A/2);
}


std::tuple<double, QPolygonF> Algorithms::minMaxBox(QPolygonF &pol)
{
    //Create min-max box and compute its area
    QPointF pxmin = * std::min_element(pol.begin(),pol.end(),sortPointsByX());
    QPointF pxmax = * std::max_element(pol.begin(),pol.end(),sortPointsByX());
    QPointF pymin = * std::min_element(pol.begin(),pol.end(),sortPointsByY());
    QPointF pymax = * std::max_element(pol.begin(),pol.end(),sortPointsByY());

    // Create new vertices
    QPointF v1(pxmin.x(), pymin.y());
    QPointF v2(pxmax.x(), pymin.y());
    QPointF v3(pxmax.x(), pymax.y());
    QPointF v4(pxmin.x(), pymax.y());

    //Create min-max box
    QPolygonF mmb;
    mmb.push_back(v1);
    mmb.push_back(v2);
    mmb.push_back(v3);
    mmb.push_back(v4);

    //Calculate the area of mmb
    double A = area(mmb);

    return {A, mmb};
}


QPolygonF Algorithms::minAreaEnclosingRect(QPolygonF &b){
    // Return minimum area enclosing rectangle of building

    // Create convex hull
    QPolygonF ch = cHull(b);

    // Initialization of min-maxbox
    double min_sigma = 0;
    auto[min_area, min_rect] = minMaxBox(ch);

    // Process all edges
    int n = ch.size();
    for(int i = 0; i < n; i++)
    {
        // Compute sigma
        double dx = ch[(i+1)%n].x() - ch[i].x();
        double dy = ch[(i+1)%n].y() - ch[i].y();

        double sigma = atan2(dy, dx);

        // Rotate by sigma
        QPolygonF ch_r = rotate(ch, - sigma);

        // Compute min-max box
        auto[area, rect] = minMaxBox(ch_r);

        // Actualize minimum
        if(area < min_area)
        {
            min_area = area;
            min_rect = rect;
            min_sigma = sigma;
        }
    }

    // Return rotated min-max box
    return rotate(min_rect, min_sigma);
}




















