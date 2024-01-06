#ifndef CSVFILE_H
#define CSVFILE_H

#include <string>
#include <vector>
#include <QtGui>
#include "qpointf3d.h"

class csv
{
public:
    csv();
    static std::vector<QPointF3D> getPointsFromFile(std::string &filename, double &xmin, double &xmax, double &ymin, double &ymax);
};

#endif
