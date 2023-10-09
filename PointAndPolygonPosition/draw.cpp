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
    QPoint p(x, y);

    //Add to the polygon
    pol.append(p);

    //Repaint
    repaint();

}

void Draw::paintEvent(QPaintEvent *event)
{
    //Create new object
    QPainter painter(this);

    //Start draw
    painter.begin(this);

    //Draw objects
    painter.drawPolygon(pol);

    //End draw
    painter.end();
}
