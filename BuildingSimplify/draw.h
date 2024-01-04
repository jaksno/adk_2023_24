#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include <vector>

class Draw : public QWidget
{
    Q_OBJECT

private:
    std::vector<QPolygonF> b, ch, bs; // b - buildings; ch - convex hulls; bs - simplify buildings

public:
    explicit Draw(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void setSimplifiedBuilding(std::vector<QPolygonF> &bs_){bs = bs_;}
    void setConvexBuilding(std::vector<QPolygonF> &ch_){ch = ch_;}
    void clearAll(){b.clear(); bs.clear(); ch.clear();}
    void clearRes(){bs.clear(); ch.clear();}
    void drawPolygons(std::vector<QPolygonF> &polygons, double &x_t, double &y_t, double &x_m, double &y_m);
    QPolygonF transPolygon(QPolygonF &polygon, double &x_t, double &y_t, double &x_m, double &y_m);
    std::vector<QPolygonF> getBuilding(){return b;}

signals:

public slots:

};

#endif // DRAW_H
