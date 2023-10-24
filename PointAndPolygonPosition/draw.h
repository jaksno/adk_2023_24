#ifndef DRAW_H
#define DRAW_H

#include <QWidget>




class Draw : public QWidget
{
    Q_OBJECT

private:
    bool add_point;
    QPoint q;
    QPolygon pol;
    std::vector<QPolygon> polygons;


public:
    explicit Draw(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void clear(){pol.clear();}
    QPoint getQ(){return q;}
    QPolygon getPol(){return pol;}
    void drawPolygons(std::vector<QPolygon> &polygons);



signals:

public slots:
};

#endif // DRAW_H
