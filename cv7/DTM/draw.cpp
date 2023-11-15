#include "draw.h"

#include <QtGui>

Draw::Draw(QWidget *parent) : QWidget(parent)
{

}

void Draw::mousePressEvent(QMouseEvent *event)
{
    //Mouse coordinates
    int x = event->pos().x();
    int y = event->pos().y();

    //Create new point
    QPointF3D p(x, y, 0.0);

    //Add to the polygon
    points.push_back(p);

    //Repaint
    repaint(); 

}

void Draw::paintEvent(QPaintEvent *event)
{
    //Create new object
    QPainter painter(this);

    //Start draw
    painter.begin(this);

    //Draw points
    int r = 5;
    for(QPointF3D point : points)
    {
        //Draw point
        painter.drawEllipse(point.x()-r, point.y()-r, 2*r, 2*r);
    }

    //End draw
    painter.end();
}
