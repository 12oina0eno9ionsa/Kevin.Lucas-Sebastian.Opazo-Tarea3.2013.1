#include "windowview.h"
#include "qpen.h"
#include "window.h"
#include <QBrush>


//Constructor vista de la ventana.

WindowView::WindowView(int x, int y, int angle, MagneticSensorView * sensorView) {
    makeWindowView();
    sensorView->setParentItem(this);
    addMagneticSensor(*sensorView);
    magnet = &(sensorView->getMagnetView());
    QTransform transform;
    transform.translate(x,y);  // Traslada la ventana a x y
    transform.rotate(angle);  // Rota la ventana en un angulo de angle
    setTransform(transform);
}


//Vista de la ventana.

void WindowView::makeWindowView() {
    // Borde
    QGraphicsRectItem* border = new QGraphicsRectItem(0,0,200,20,this);
    border->setBrush(QBrush(Qt::white));
    border->setPen(QPen(Qt::black, 1, Qt::DashLine));
    // Pilar origen
    QGraphicsRectItem * origenPillar = new QGraphicsRectItem(0,0,20,20,this);
    origenPillar->setBrush(Qt::blue);
    // Pilar switch
    switchPillar = new QGraphicsRectItem(180,0,20,20,this);
    switchPillar->setBrush(Qt::blue);
    // Cristal estatico
    QGraphicsRectItem * fixedGlass = new QGraphicsRectItem(21,4,82,6,this);
    QColor lightSkyBlue(135,206,250);
    fixedGlass->setBrush(lightSkyBlue);
    // Cristal movible
    windowPanel = new QGraphicsRectItem(97,11,82,6,this);
    windowPanel->setBrush(lightSkyBlue);
    windowPanel->setTransformOriginPoint(windowPanel->rect().left(), windowPanel->rect().bottom());
    addToGroup(border);
    addToGroup(origenPillar);
    addToGroup(switchPillar);
    addToGroup(fixedGlass);
    addToGroup(windowPanel);
}

//Anade el sensor magnetico a la ventana, respecto a el panel movible.

void WindowView::addMagneticSensor(MagneticSensorView & mv){
    mv.getMagnetView().setRect(windowPanel->rect().right()-mv.getMagnetView().rect().width(),
                               windowPanel->rect().bottom(),
                               mv.getMagnetView().rect().width(),
                               mv.getMagnetView().rect().height());
    mv.getSwitchView().setRect(switchPillar->boundingRect().x()+switchPillar->boundingRect().width()/2,
                               switchPillar->boundingRect().height(),
                               mv.getSwitchView().rect().width(),
                               mv.getSwitchView().rect().height());
    mv.getMagnetView().setTransformOriginPoint(0, 0);
    addToGroup(&mv.getMagnetView());
    addToGroup(&mv.getSwitchView());
}

// Captura el evento cuando es clickeada la ventana.

void WindowView::mousePressEvent(QGraphicsSceneMouseEvent * event){
    if (model!= NULL && event->button()==Qt::LeftButton)
        model->changeState();
}
// Setters Open y Close, mueven el panel movil junto a su sensor

void WindowView::setOpen() {
    windowPanel->setPos(windowPanel->x() - 70, windowPanel->y());
    magnet->setPos(magnet->x() - 70, magnet->y());
}
void WindowView::setClose() {
    windowPanel->setPos(windowPanel->x() + 70, windowPanel->y());
    magnet->setPos(magnet->x() + 70, magnet->y());
}
// Setea la ventana que representa esta vista.

void WindowView::setWindowModel(Window * modelView){
    this->model=modelView;
}
// Destructor
WindowView::~WindowView(){
    delete windowPanel;
    delete switchPillar;
    delete magnet;
}
