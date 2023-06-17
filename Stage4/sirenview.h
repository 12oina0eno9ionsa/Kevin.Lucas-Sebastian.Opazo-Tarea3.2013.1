#ifndef SIRENVIEW_H
#define SIRENVIEW_H

#include <QGraphicsItemGroup>
#include <QGraphicsRectItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QBrush>

class Siren;

class SirenView:public QGraphicsItemGroup{
public:
    SirenView();
    void setSirenModel(Siren * m);
    void stopBlinking();
    void Blinking();
private:
    Siren * model;
    QGraphicsPolygonItem * polygon;
    bool flag;
};

#endif // SIRENVIEW_H
