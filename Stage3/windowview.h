#ifndef WINDOWVIEW_H
#define WINDOWVIEW_H

#include <QGraphicsItemGroup>
#include <QGraphicsRectItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsSceneMouseEvent>
#include "magneticsensorview.h"

class Window; // Se declara la clase para evitar include recursivo

class WindowView : public QGraphicsItemGroup
{
public:
    explicit WindowView(int x, int y, int angle, MagneticSensorView * msView);
    void setWindowModel(Window * model);
    void setOpen();
    void setClose();
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *);
    ~WindowView();
private:
    void addMagneticSensor(MagneticSensorView & msView);
    void makeWindowView();
    Window * model;
    QGraphicsRectItem * windowPanel;
    QGraphicsRectItem * switchPillar;
    QGraphicsRectItem * magnet;
};


#endif // WINDOWVIEW_H
