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
    QPointF p(x, y);

    //Add vertex to the building
    b.append(p);

    //Repaint
    repaint(); 

}


void Draw::paintEvent(QPaintEvent *event)
{
    //Create new object
    QPainter painter(this);

    //Start draw
    painter.begin(this);

    //Draw raw building
    painter.setPen(Qt::black);
    painter.drawPolygon(b);

    //Draw convex hull
    painter.setPen(Qt::blue);
    painter.drawPolygon(ch);

    //Draw simplified building
    painter.setPen(Qt::red);
    painter.drawPolygon(bs);

    //End draw
    painter.end();
}
