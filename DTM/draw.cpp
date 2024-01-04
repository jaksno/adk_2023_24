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
        double r;
        double g;
        double b;
        double c;

        // Compute slope
        if (analysis)
        {
            //Get slope
            double slope = t.getSlope();

            //Convert slope to color
            double c = 255 / (M_PI);
            col = 255 - slope * c;
            r = col; g = col; b = col;

        }

        // Compute Aspect
        else
        {
            //Get aspect
            double aspect = t.getAspect();

            //Convert slope to color

            if (aspect < M_PI/2){
                c = 255 / (M_PI/2);

                r = 255;
                g = aspect * c;
                b = 0;
                qDebug() << 1;
            }
            else if ((M_PI/2 <= aspect) && (aspect < (3*M_PI)/4)){
                c = 255 / (M_PI/4);

                r = 3*255 - aspect * c;
                g = 255;
                b = 0;
                qDebug() << 2;
            }
            else if (((3*M_PI)/4 <= aspect) && (aspect < M_PI)){
                c = 255 / (M_PI/4);

                r = 0;
                g = 255;
                b = aspect * c - 3*255;
                qDebug() << 3;
            }
            else if ((M_PI <= aspect) && (aspect < (3*M_PI)/2)){
                c = 255 / (M_PI/2);

                r = 0;
                g = aspect * c - 3*255;
                b = 255;
                qDebug() << 4;
            }
            else if (((3*M_PI)/2 <= aspect) && (aspect < (7*M_PI)/4)){
                c = 255 / (M_PI/4);

                r = aspect * c - 6*255;
                g = 0;
                b = 255;
                qDebug() << 5;
            }
            else {
                c = 255 / (M_PI/4);

                r = 255;
                g = 0;
                b = aspect * c - 8*255;
                qDebug() << 6;
            }
            qDebug() << aspect;
        }

        qDebug() << std::abs(r);
        qDebug() << std::abs(g);
        qDebug() << std::abs(b);

        //Set color
        QColor qt_col(std::abs(r), std::abs(g), std::abs(b));
        qDebug() << qt_col;
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
