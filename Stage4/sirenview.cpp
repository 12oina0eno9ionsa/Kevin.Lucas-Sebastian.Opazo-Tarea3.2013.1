
#include "sirenview.h"
#include <QBrush>
#include <QTimer>



// Constructor

SirenView::SirenView()
{
    flag=false;    //bool para controlar la animacion
    polygon=new QGraphicsPolygonItem(this);
    QPolygonF p;
    p.append(QPointF(0,30));
    p.append(QPointF(0,50));
    p.append(QPointF(30,80));
    p.append(QPointF(30,0));
    polygon->setPolygon(p);
    polygon->setBrush(Qt::white);
    addToGroup(polygon);
}

//Blinking alterna los colores rojo y azul

void SirenView::Blinking(){
    if(flag){
        polygon->setBrush(Qt::red);
        }
    else polygon->setBrush(Qt::blue);

    flag=!flag;
}

//StopBlinking setea el brush blanco

void SirenView::stopBlinking(){
    polygon->setBrush(Qt::white);
}

//Set modelo Siren

void SirenView::setSirenModel(Siren * m){
    model=m;
}
