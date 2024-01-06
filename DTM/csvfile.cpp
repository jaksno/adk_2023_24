#include "csvfile.h"
#include "qpointf3d.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <QDir>


std::vector<QPointF3D> csv::getPointsFromFile(std::string &filename, double &xmin, double &xmax, double &ymin, double &ymax)
{

    // Declaration of variables
    std::vector<std::string> lines;
    std::vector<std::vector<std::string>> res;
    std::string line;
    std::ifstream file(filename);
    double x, y, z;
    std::vector<QPointF3D> points;

    // Read csv file
    // Read data in lines
    while(std::getline(file, line))
    {
        std::stringstream ss1(line);
        std::string field;
        while(std::getline(ss1, field, ','))
            lines.push_back(field);
        // Save a values
        res.push_back(lines);
        lines.clear();
    }
    // Close file
    file.close();

    // Save a data to variables and set bounding box
    // Read data in lines
    for(std::vector<std::string> line: res)
    {
        // Convert strings
        x  = -std::stod(line[0]);
        y  = -std::stod(line[1]);
        z  = std::stod(line[2]);

        // Update minmax box
        if(x < xmin) xmin = x;
        if(x > xmax) xmax = x;
        if(y < ymin) ymin = y;
        if(y > ymax) ymax = y;
        points.push_back(QPointF3D(x, y, z));
    }
    return points;
}
