#include "draw.h"

#include <cstdlib>
#include <QtGui>

Draw::Draw(QWidget *parent) : QWidget(parent)
{
    analysis = false;
}

void Draw::mousePressEvent(QMouseEvent *event)
{
    //Mouse coordinates
    int x = event->pos().x();
    int y = event->pos().y();

    //Create new point
    QPointF3D p(x, y, rand() % 1000);

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

    //Draw triangles
    for (Triangle t: triangles)
    {
        // Get vertices
        QPointF3D v1 = t.getV1();
        QPointF3D v2 = t.getV2();
        QPointF3D v3 = t.getV3();

        //Create polygon
        QPolygonF pol;
        pol.push_back(v1);
        pol.push_back(v2);
        pol.push_back(v3);

        int col = 0;

        // Compute slope
        if (analysis)
        {
            //Get slope
            double slope = t.getSlope();

            //Convert slope to color
            double c = 255 / (M_PI);
            col = 255 - slope * c;
        }

        // Compute Aspect
        else
        {
            //Get aspect
            double aspect = t.getAspect();

            //Convert slope to color
            double c = 255 / (2*M_PI);
            col = 255 - aspect * c;
        }


        //Set color
        QColor qt_col(col, col, col);
        painter.setPen(qt_col);
        painter.setBrush(qt_col);

        // Draw triangle
        painter.drawPolygon(pol);
    }

    //Draw points
    int r = 5;
    for(QPointF3D point : points)
    {
        //Draw point
        painter.drawEllipse(point.x()-r, point.y()-r, 2*r, 2*r);
    }

    //Draw dt
    for(Edge e: dt)
    {
        //Draw edge
        painter.drawLine(e.getS(), e.getE());
    }

    //Draw contour lines
    QColor qt_col(0,0,0);
    painter.setPen(qt_col);
    for(Edge cl: contour_lines)
    {
        //Draw edge
        painter.drawLine(cl.getS(), cl.getE());
    }

    //End draw
    painter.end();
}
