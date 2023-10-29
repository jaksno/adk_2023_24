#include "draw.h"

#include <QtGui>

Draw::Draw(QWidget *parent) : QWidget(parent)
{
    add_point = true;
    q.setX(-10);
    q.setY(-10);
}

void Draw::mousePressEvent(QMouseEvent *event)
{
    //Mouse coordinates
    int x = event->pos().x();
    int y = event->pos().y();

    //Change q coordinates
    if (add_point) {
        q.setX(x);
        q.setY(y);
    }

    //Add new vertex to polygon
    else
    {
        //Create new point
        QPoint p(x, y);

        //Add to the polygon
        pol.append(p);

    }

    //Repaint
    repaint();

}

void Draw::paintEvent(QPaintEvent *event)
{
    //Create new objects
    QPainter painter(this);

    //Start draw
    painter.begin(this);

    //Draw point
    int r = 3;
    painter.drawEllipse(q.x()-r, q.y()-r, 2*r, 2*r);

    // Draw polygons
    for (int i = 0; i < int(polygons.size()); i++) painter.drawPolygon(polygons[i]);

    // Highlite polygon
    QBrush brush(Qt::blue);
    painter.setBrush(brush);
    painter.drawPolygon(highlite);

    //End draw
    painter.end();
}


void Draw::drawPolygons(std::vector<QPolygon> &poly){
    // polygons to draw
    polygons.clear();
    for (QPolygon pol : poly) polygons.push_back(pol);
    repaint();
}

void Draw::highlitePolygon(QPolygon &polygon_highlite){
    // polygon to highlite
    highlite.clear();
    highlite = polygon_highlite;
    repaint();
}








