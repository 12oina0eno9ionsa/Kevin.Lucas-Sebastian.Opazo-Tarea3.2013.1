#include "magneticsensorview.h"
#include <QBrush>
//Constructor sensor
MagneticSensorView::MagneticSensorView()
    :switchView(0,0,8,6, this),magnetView(0,0,8,6, this)
{
    switchView.setBrush(QBrush(Qt::green));
    magnetView.setBrush(QBrush(Qt::black));
}
//Setters del color del sensor (Abierto y cerrado)
void MagneticSensorView::setCloseView(){
    switchView.setBrush(QBrush(Qt::green));
}
void MagneticSensorView::setOpenView(){
    switchView.setBrush(QBrush(Qt::red));
}

// Getters de los dos sensores (Fijo y sujeto a el objeto)
QGraphicsRectItem & MagneticSensorView::getSwitchView(){
    return switchView;
}
QGraphicsRectItem & MagneticSensorView::getMagnetView(){
    return magnetView;
}
