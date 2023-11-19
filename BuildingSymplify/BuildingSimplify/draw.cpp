#include "draw.h"

#include <QtGui>
#include <QFileDialog>
#include <iostream>

Draw::Draw(QWidget *parent) : QWidget(parent)
{

}


void Draw::paintEvent(QPaintEvent *event)
{
    // Draw polygon
    // Start draw
    QPainter painter(this);
    painter.begin(this);

    // Draw polygons loaded from file
    for (QPolygonF polygon : Draw::b)
    {
        painter.setPen(QPen(Qt::black, 1.5));
        painter.setBrush(Qt::white);
        painter.drawPolygon(polygon);
    }

    // Draw convex hull
    painter.setPen(QPen(Qt::gray, 1, Qt::DashLine));
    painter.setBrush(Qt::NoBrush);
    for (QPolygonF chs: ch)
        painter.drawPolygon(chs);

    //Draw simplified building
    painter.setPen(QPen(Qt::red, 2));
    painter.setBrush(Qt::NoBrush);
    for (QPolygonF bss : bs)
        painter.drawPolygon(bss);

    // End draw
    painter.end();
}


void Draw::drawPolygons(std::vector<QPolygonF> &polygons, double &x_t, double &y_t, double &x_m, double &y_m)
{
    // Clear the vector if needed
    b.clear();

    // Iterate over polygons and transform each one
    for (QPolygonF &pol : polygons)
    {
        QPolygonF tPolygon = transPolygon(pol, x_t, y_t, x_m, y_m);
        Draw::b.push_back(tPolygon);
    }


    // Repaint if needed
    repaint();
}



QPolygonF Draw::transPolygon(QPolygonF &polygon, double &x_t, double &y_t, double &x_m, double &y_m)
{
    // Transform x,y of polygon
    QPolygonF tPolygon;

    // Go through all points in polygon
    for (QPointF pol : polygon)
    {

        double dx = pol.x() - x_t;
        double dy = pol.y() - y_t;
        double x0 = dx/x_m;
        double y0 = dy/y_m;
        QPointF point(x0, y0);
        tPolygon << point;
    }
    return tPolygon;
}
