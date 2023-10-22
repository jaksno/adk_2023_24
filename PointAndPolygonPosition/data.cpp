#include "data.h"
#include <QtGui>
#include <vector>
#include <string>
#include <QFile>
#include <QTextStream>
#include <QPoint>
#include <QPolygon>
#include <iostream>

using namespace std;

Data::Data()
{

}

vector<QPolygon> Data::readPolygonsFromFile(QString &filePath){
    // read polygon/s data from txt file

    // format description
    //1 polygon_id
    //10 10 vertex num. 1
    //10 20 vertex num. 2
    //20 20 vertex num. 3
    //20 10 vertex num. 4
    //2 another polygon
    //20 20
    //20 45
    //45 20
    //...

    // create a vector to store the polygons
    vector<QPolygon> polygons;
    // open the specified file
    QFile file(filePath);
    // create a QTextStream to read from the file
    QTextStream in(&file);

    // run while QTextStream hasn't reached the end
    while(!in.atEnd()){
        QString line = in.readLine().trimmed(); // Read a line and remove spaces
        if (line.isEmpty()) {
            continue; // Skip empty lines
        }

        bool ok;
        int id = line.toInt(&ok); // if conversion of id(string->int) is succesfull, sets value ok to true

        if(ok){
            QPolygon polygon; // new polygon object to store vertices

            while(true){
                line = in.readLine().trimmed();

                if(line.isEmpty() || line.toInt(&ok)){
                    break;
                } // end of the polygon or start of a new polygon

                QStringList coords = line.split(' '); // split line into parts using spaces as delimiter

                if(coords.size() == 2){
                    double x = coords[0].toDouble();
                    double y = coords[1].toDouble();
                    polygon.append(QPoint(x, y));
                } // appends x and y coordinate (as a new vertex) to polygon
            }

            polygons.push_back(polygon); // add new polygon to polygons

        }

    }

    file.close(); // close the file
    return polygons; // return the vector of polygons
}
