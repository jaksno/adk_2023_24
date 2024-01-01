#ifndef EDGE_H
#define EDGE_H

#include "qpointf3d.h"

class Edge
{
private:
    QPointF3D s, e;

public:
    Edge(const QPointF3D &s_, const QPointF3D &e_){s = s_; e = e_;}
    Edge changeOrientation(){return Edge(e, s);}
    QPointF3D getS() const {return s;}
    QPointF3D getE() const {return e;}
    bool operator == (const Edge &edge){return s==edge.s && e==edge.e;}


};

#endif // EDGE_H
