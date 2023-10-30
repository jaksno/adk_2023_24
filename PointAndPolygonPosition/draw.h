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
    int pol_con_point_id;
    QPolygon highlite;

public:
    explicit Draw(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void clear(){polygons.clear();}
    QPoint getQ(){return q;}
    QPolygon getPol(){return pol;}
    void drawPolygons(std::vector<QPolygon> &polygons);
    std::vector<QPolygon> getPolData() {return polygons;};
    void highlitePolygon(QPolygon &polygon_highlite);
    void reset_brush();

signals:

public slots:
};

#endif // DRAW_H
