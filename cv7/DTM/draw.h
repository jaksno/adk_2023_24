#ifndef DRAW_H
#define DRAW_H

#include <QWidget>

#include "QPointF3D.h"

class Draw : public QWidget
{
    Q_OBJECT

private:

    std::vector <QPointF3D> points;

public:
    explicit Draw(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void clear(){points.clear();}
    std::vector <QPointF3D> getPoints(){return points;}

signals:

public slots:
};

#endif // DRAW_H
