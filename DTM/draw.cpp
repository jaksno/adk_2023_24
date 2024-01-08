#include "draw.h"
#include "mainform.h"
#include "ui_mainform.h"
#include "algorithms.h"


#include <cstdlib>
#include <QtGui>
#include <set>

Draw::Draw(QWidget *parent) : QWidget(parent)
{
    analysis = false;
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
            double c = 255 * (M_PI);
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


        r = std::floor(std::abs(r));
        g = std::floor(std::abs(g));
        b = std::floor(std::abs(b));

        qDebug() << std::abs(r);
        qDebug() << std::abs(g);
        qDebug() << std::abs(b);
        //Set color
        QColor qt_col(r,g,b);
        //qDebug() << qt_col;
        painter.setPen(qt_col);
        painter.setBrush(qt_col);

        // Draw triangle
        painter.drawPolygon(pol);
    }

    //Draw points
    int r = 1;
    for(QPointF3D point : points)
    {
        //Draw point
        QColor qt_col(50,50,50);
        painter.setPen(qt_col);
        painter.drawEllipse(point.x()-r, point.y()-r, 2*r, 2*r);
    }

    //Draw dt
    for(Edge e: dt)
    {
        //Draw edge
        QColor qt_col(192,192,192);
        painter.setPen(qt_col);
        painter.drawLine(e.getS(), e.getE());
    }

    //Draw contour lines
    QColor qt_col(139, 69, 19);
    painter.setPen(qt_col);
    QFont font = painter.font();
    font.setPointSize(10);
    painter.setFont(font);
    int counter = 0;

    for (Edge cl : contour_lines)
    {
        // Draw edge
        painter.drawLine(cl.getS(), cl.getE());

        // Display elevation every 15 description
        if (counter % 15 == 0)
        {
            QPointF textPosition = cl.getS();
            double elevation = cl.getS().getZ();

            QString elevationText = QString::number(elevation) + " m";

            // Calculate the angle
            double angle = atan2(cl.getE().y() - cl.getS().y(), cl.getE().x() - cl.getS().x())*(180 / M_PI);

            // Draw
            painter.save();
            painter.translate(textPosition);
            painter.rotate(angle);
            painter.drawText(0, 0, elevationText);
            painter.restore();
        }

        counter++;
    }


    //End draw
    painter.end();
}

void Draw::drawPoints(std::vector<QPointF3D> &points3d)
{
    //Get transformation parameters
    double trans_x = getTransX();
    double trans_y = getTransY();
    double scale = getScale();
    int delta_x = getDeltaX();
    int delta_y = getDeltaY();

    //Draw vector of points
    std::vector<QPointF3D> trans = Algorithms::transformPoints(points3d, trans_x, trans_y, scale, delta_x, delta_y);
    Draw::setCSVPoints(trans);

    repaint();
}
