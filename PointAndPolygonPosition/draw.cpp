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
    //Create new object
    QPainter painter(this);

    //Start draw
    painter.begin(this);

    //Draw polygon
    painter.drawPolygon(pol);

    //Draw point
    int r = 5;
    painter.drawEllipse(q.x()-r, q.y()-r, 2*r, 2*r);

    //End draw
    painter.end();
}

void Draw::setSource()
{
    // Add point q / polygon vertex
    add_point = !add_point;
}
