#ifndef WKT_H
#define WKT_H

#include <string>
#include <vector>
#include <QtGui>

class wkt
{
public:
    wkt();
    std::vector<QPolygonF> readFile(std::string &filename, double &xmin, double &xmax, double &ymin, double &ymax);
};

#endif // WKT_H
