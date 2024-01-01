#include "algorithms.h"
#include "sortpointsbyx.h"
#include <cmath>
#include <list>

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

    //Browse all points
    for(int i = 0; i < points.size(); i++)
    {
        //Point q is different from points[i]
        if(q != points[i])
        {
            //Compute distance
            double d = getDistance2D(q, points[i]);

            //Update minimum distance
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

    //Browse all points
    for(int i = 0; i < points.size(); i++)
    {
        //Points s and e are different from points[i]
        if(s != points[i] && e != points[i])
        {
            //Point in the left half-plane
            if (getPointAndLinePosition(points[i], s, e) == 1)
            {
                //Compute angle
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

std::vector <Edge> Algorithms::createDT(std::vector <QPointF3D> &points)
{
    //Create Delaunay Triangulation
    std::vector<Edge> dt;
    std::list<Edge> ael;

    //Find pivot
    QPointF3D p1 = *std::min_element(points.begin(), points.end(), sortPointsByX());

    //Search for nearest point to pivot
    int index = getNearestPoint(p1, points);
    QPointF3D p2 = points[index];

    //Create Edge and opposite edge
    Edge e(p1, p2);
    Edge eo(p2, p1);

    //Add edges to AEL
    ael.push_back(e);
    ael.push_back(eo);

    //Until AEL is empty
    while (!ael.empty())
    {
        //Get last edge
        Edge e1 = ael.back();

        //Remove edge
        ael.pop_back();

        //Switch orientation
        Edge e1o = e1.changeOrientation();

        //Find Delaunay point
        index = getDelaunayPoint(e1o.getS(), e1o.getE(), points);

        //Delaunay point exists
        if (index > -1){
            // Create remaining edges
            Edge e2(e1o.getE(), points[index]);
            Edge e3(points[index], e1o.getS());

            //Add triangle to dt
            dt.push_back(e1o);
            dt.push_back(e2);
            dt.push_back(e3);

            //Update AEL
            updateAEL(e2, ael);
            updateAEL(e3, ael);
        }
    }

    return dt;
}


void Algorithms::updateAEL(Edge &edge, std::list<Edge> &ael)
{
    //Update active edges list

    //Change orientation
    Edge edgeo = edge.changeOrientation();

    //Find edge in AEL
    auto res = std::find(ael.begin(), ael.end(), edgeo);

    //Edge not in AEL
    if (res == ael.end())
        ael.push_back(edge);

    //Edge in AEL
    else
        ael.erase(res);
}


QPointF3D Algorithms::contourPoint(const QPointF3D &p1, const QPointF3D &p2, double z)
{
    // Compute contour point
    double x_b = (p2.x()-p1.x())/(p2.getZ()-p1.getZ())*(z-p1.getZ())+p1.x();
    double y_b = (p2.y()-p1.y())/(p2.getZ()-p1.getZ())*(z-p1.getZ())+p1.y();

    return QPointF3D(x_b,y_b,z);
}

std::vector<Edge> Algorithms::createContourLines(const std::vector<Edge> &dt, double z_min, double z_max, double dz)
{
    // Create contour lines
    std::vector<Edge> contour_lines;

    // Process all triangles of DT
    for (int i = 0; i < dt.size(); i+=3)
    {
        // Triangle vertices
        QPointF3D p1 = dt[i].getS();
        QPointF3D p2 = dt[i+1].getS();
        QPointF3D p3 = dt[i+2].getS();

        //Check all horizontal planes
        for (double z = z_min; z <= z_max; z += dz)
        {
            // Calculate dz
            double dz1 = z - p1.getZ();
            double dz2 = z - p2.getZ();
            double dz3 = z - p3.getZ();

            // Triangle is coplanar
            if ((dz1 == 0) && (dz2 == 0) && (dz3 == 0))
                continue;

            // Edge p1, p2 is colinear
            else if ((dz1 == 0) && (dz2 == 0))
                contour_lines.push_back(dt[i]);

            // Edge p2, p3 is colinear
            else if ((dz2 == 0) && (dz3 == 0))
                contour_lines.push_back(dt[i+1]);

            // Edge p3, p1 is colinear
            else if ((dz3 == 0) && (dz1 == 0))
                contour_lines.push_back(dt[i+2]);

            // Edges p1, p2 and p2, p3
            else if ((dz1*dz2 < 0) && (dz2*dz3 <= 0) || (dz1*dz2 <= 0) && (dz2*dz3 < 0))
            {
                // Compute intersections
                QPointF3D a = contourPoint(p1, p2, z);
                QPointF3D b = contourPoint(p2, p3, z);

                // Create edge
                Edge e(a, b);
                contour_lines.push_back(e);
            }

            // Edges p2, p3 and p3, p1
            else if ((dz2*dz3 < 0) && (dz3*dz1 <= 0) || (dz2*dz3 <= 0) && (dz3*dz1 < 0))
            {
                // Compute intersections
                QPointF3D a = contourPoint(p2, p3, z);
                QPointF3D b = contourPoint(p3, p1, z);

                // Create edge
                Edge e(a, b);
                contour_lines.push_back(e);
            }

            // Edges p3, p1 and p1, p2
            else if ((dz3*dz1 < 0) && (dz1*dz2 <= 0) || (dz3*dz1 <= 0) && (dz1*dz2 < 0))
            {
                // Compute intersections
                QPointF3D a = contourPoint(p3, p1, z);
                QPointF3D b = contourPoint(p1, p2, z);

                // Create edge
                Edge e(a, b);
                contour_lines.push_back(e);
            }
        }
    }

    return contour_lines;
}

std::vector<Triangle> Algorithms::analyzeDTMSlope(const std::vector<Edge> &dt)
{
    //Analyze slope
    std::vector <Triangle> triangles;

    for (int i = 0; i < dt.size(); i+=3)
    {
        // Triangle vertices
        QPointF3D v1 = dt[i].getS();
        QPointF3D v2 = dt[i+1].getS();
        QPointF3D v3 = dt[i+2].getS();

        //Compute slope
        double slope = computeSlope(v1, v2, v3);

        //Create triangle
        Triangle t(v1, v2, v3, slope, 0);

        //Add triagle to the list
        triangles.push_back(t);
    }

     return triangles;
}

std::vector<Triangle> Algorithms::analyzeDTMAspect(const std::vector<Edge> &dt)
{
    //Analyze slope
    std::vector <Triangle> triangles;

    for (int i = 0; i < dt.size(); i+=3)
    {
        // Triangle vertices
        QPointF3D v1 = dt[i].getS();
        QPointF3D v2 = dt[i+1].getS();
        QPointF3D v3 = dt[i+2].getS();

        //Compute slope
        double aspect = computeAspect(v1, v2, v3);

        //Create triangle
        Triangle t(v1, v2, v3, 0, aspect);

        //Add triagle to the list
        triangles.push_back(t);
    }

     return triangles;
}

double Algorithms::computeSlope(const QPointF3D &v1, const QPointF3D &v2, const QPointF3D &v3)
{
    // Compute slope of the triangle

    double ux = v2.x() - v1.x();
    double uy = v2.y() - v1.y();
    double uz = v2.getZ() - v1.getZ();

    double vx = v3.x() - v1.x();
    double vy = v3.y() - v1.y();
    double vz = v3.getZ() - v1.getZ();

    // Compute cross product
    double nx = uy * vz - uz * vy;
    double ny = -(ux * vz - uz * vx);
    double nz = ux * vy - uy * vx;

    //Angle slope
    return acos(nz / (sqrt(nx*nx + ny*ny + nz*nz)));

}


double Algorithms::computeAspect(const QPointF3D &v1, const QPointF3D &v2, const QPointF3D &v3)
{
    // Compute aspect of the triangle

    double ux = v2.x() - v1.x();
    double uy = v2.y() - v1.y();
    double uz = v2.getZ() - v1.getZ();

    double vx = v3.x() - v1.x();
    double vy = v3.y() - v1.y();
    double vz = v3.getZ() - v1.getZ();

    // Compute cross product
    double nx = uy * vz - uz * vy;
    double ny = -(ux * vz - uz * vx);

    //Angle aspect
    double aspect =  atan2(nx, ny);

    //Correct negative aspect
    if (aspect < 0)
            aspect += 2*M_PI;

    return aspect;
}






