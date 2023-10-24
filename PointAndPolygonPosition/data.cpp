#include "data.h"
#include <QtGui>
#include <vector>
#include <string>
#include <QFile>
#include <QTextStream>
#include <QPoint>
#include <QPolygon>

using namespace std;

Data::Data()
{

}

vector<QPolygon> Data::readPolygonsFromFile(QString &filePath) {
    vector<QPolygon> polygons; // create a vector to store the polygons

    QFile file(filePath); // open the specified file

    file.open(QIODevice::ReadOnly); // open file - does not work without it.. IDK

    QTextStream in(&file); // create a QTextStream to read from the file

    while (!in.atEnd()) {
        QPolygon polygon; // create a polygon object to store the vertices
        qDebug() << "new polygon";

        while (!in.atEnd()) {
            QString line = in.readLine().trimmed(); // read line

            if (line.isEmpty()) {
                break; // end of the polygon
            }

            QStringList parts = line.split(' '); // split the line into parts using spaces as delimiters

            if (parts.size() >= 2) {
                int x = parts[0].toInt(); // x coordinate
                int y = parts[1].toInt(); // y coordinate
                polygon.append(QPoint(x, y)); // add the vertex to the polygon

            }

        }
        qDebug() << polygon;
        polygons.push_back(polygon); // add the completed polygon to the vector

    }

    file.close(); // close file
    qDebug() << polygons;
    return polygons; // return the vector of polygons
}

