#include "doorview.h"
#include "door.h"
#include <QBrush>

//Constructor de la vista de una puerta.

DoorView::DoorView(int x, int y, int angle, MagneticSensorView * sensorView) {
    makeDoorView();
    sensorView->setParentItem(this);
    addMagneticSensor(*sensorView);
    magnet = &(sensorView->getMagnetView());
    QTransform transform;         //Permite manipular la puerta
    transform.translate(x,y);         //  Traslada  a x y
    transform.rotate(angle);          // Rota en un angulo angle
    setTransform(transform);       // Setea los cambios en la puerta
}


void DoorView::makeDoorView() {
    //Pilar origen
    QGraphicsPolygonItem * origenPillar=new QGraphicsPolygonItem(this);
    QPolygonF p;
    p.append(QPointF(0,0));
    p.append(QPointF(0,20));
    p.append(QPointF(10,20));
    p.append(QPointF(10,10));
    p.append(QPointF(20,10));
    p.append(QPointF(20,0));
    origenPillar->setPolygon(p);
    origenPillar->setBrush(Qt::blue);
    //Pilar switch
    switchPillar=new QGraphicsPolygonItem(this);
    p.clear();
    p.append(QPointF(160,0));
    p.append(QPointF(160,10));
    p.append(QPointF(170,10));
    p.append(QPointF(170,20));
    p.append(QPointF(180,20));
    p.append(QPointF(180,0));
    switchPillar->setPolygon(p);
    switchPillar->setBrush(Qt::blue);
    //Panel puerta
    doorPanel = new QGraphicsRectItem(0, 0, 170, 10, this);
    QColor brown(165,42,42);
    doorPanel->setBrush(brown);
    doorPanel->setTransformOriginPoint(doorPanel->rect().left(), doorPanel->rect().bottom());
    addToGroup(origenPillar);
    addToGroup(switchPillar);
    addToGroup(doorPanel);
}

//Anade el sensor magnetico a la puerta

void DoorView::addMagneticSensor(MagneticSensorView & mv){
    mv.getMagnetView().setRect(doorPanel->rect().right()-mv.getMagnetView().rect().width(),
                                 doorPanel->rect().bottom(),
                                 mv.getMagnetView().rect().width(),
                                 mv.getMagnetView().rect().height());
    mv.getSwitchView().setRect(switchPillar->boundingRect().x()+switchPillar->boundingRect().width()/2,
                                 switchPillar->boundingRect().height(),
                                 mv.getSwitchView().rect().width(),
                                 mv.getSwitchView().rect().height());
    mv.getMagnetView().setTransformOriginPoint(0, 10);
    addToGroup(&mv.getMagnetView());
    addToGroup(&mv.getSwitchView());
}

// Captura el evento cuando es clickeada la puerta

void DoorView::mousePressEvent(QGraphicsSceneMouseEvent * event){
    if (model!= NULL && event->button()==Qt::LeftButton)
        model->changeState();
}

//Rota la puerta junto a su sensor (Open y Close).

void DoorView::setOpen(){
    doorPanel->setRotation(90);
    magnet->setRotation(90);
}
void DoorView::setClose(){
    doorPanel->setRotation(0);
    magnet->setRotation(0);
}
// Setea el modelo de la puerta que representa la vista.
void DoorView::setDoorModel(Door * doorModel){
    this->model=doorModel;
}

//Destructor
DoorView::~DoorView(){
    delete doorPanel;
    delete switchPillar;
    delete magnet;
}
