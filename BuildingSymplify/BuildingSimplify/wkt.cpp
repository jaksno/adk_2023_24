#include "wkt.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <QDir>


wkt::wkt()
{

}

std::vector<QPolygonF> wkt::readFile(std::string &filename, double &xmin, double &xmax, double &ymin, double &ymax)
{
    // Read WKT File
    // Vector for storing result
    std::vector<QPolygonF> polygons;
    std::string line, column;
    std::ifstream file(filename);

    // Check if file is opened
    if(!file.is_open()) throw std::runtime_error("File not opened.");

    // Read column names
    if(file.good())
    {
        // Get first line from file and create stringstream
        std::getline(file, line);
        std::stringstream stringstream(line);
        while(std::getline(stringstream, column, ',')){
        }
    }

    // Read CSV file
    while(std::getline(file, line))
    {
        // Edit
        line.erase(remove(line.begin(), line.end(), '"'), line.end());
        line.erase(remove(line.begin(), line.end(), '('), line.end());
        line.erase(remove(line.begin(), line.end(), ')'), line.end());
        line.erase(0,12);

        // Set variable
        int columnID = 0;
        int coordinates = 0;
        int x, y;
        std::stringstream stringstream(line);
        std::string coordinate_pair, coordinate;
        QPolygonF pol;

        // Go through all points in polygon
        while(std::getline(stringstream, coordinate_pair, ','))
        {
            std::stringstream ss2(coordinate_pair);
            while(std::getline(ss2, coordinate, ' '))
            {
                if (coordinate == "") continue;
                if (coordinates < 2)
                {
                    // Coordinate x
                    if (coordinates == 0)
                    {
                        // Convert string to integer
                        x = (std::stod(coordinate));
                        if (x < xmin) xmin = x;
                        if (x > xmax) xmax = x;
                        coordinates++;
                    }
                    // Coordinate y
                    else if (coordinates == 1)
                    {
                        // Convert string to integer
                        y = (std::stod(coordinate));
                        if (y < ymin) ymin = y;
                        if (y > ymax) ymax = y;
                        coordinates++;
                    }
                }
            }
            // Coordinates add to point
            if (coordinates == 2)
            {
                QPointF p(x,y);
                pol << p;
                coordinates = 0;
            }
            columnID++;
        }
        // Save
        polygons.push_back(pol);
    }
    // Close file
    file.close();
    return polygons;
}

