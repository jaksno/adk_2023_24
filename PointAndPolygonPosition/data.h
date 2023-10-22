#ifndef DATA_H
#define DATA_H

#include <QtGui>
#include <vector>
#include <string>

using namespace std;

class Data
{
public:
    Data();

    vector<QPolygon> readPolygonsFromFile(QString &filePath);
};

#endif // DATA_H
