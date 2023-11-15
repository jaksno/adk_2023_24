#ifndef DRAW_H
#define DRAW_H

#include <QWidget>

class Draw : public QWidget
{
    Q_OBJECT

private:
    QPolygonF b;
    QPolygonF ch;
    QPolygonF bs;

public:
    explicit Draw(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void clear(){b.clear();}
    QPolygonF getBuilding(){return b;}
    void setSimplifiedBuilding(QPolygonF &bs_){bs = bs_;}

signals:

public slots:
};

#endif // DRAW_H
