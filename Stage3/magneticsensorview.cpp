#include "magneticsensorview.h"
#include <QBrush>


//Vista del sensor
MagneticSensorView::MagneticSensorView()
    :switchView(0,0,8,6, this),magnetView(0,0,8,6, this)
{
    switchView.setBrush(QBrush(Qt::green));
    magnetView.setBrush(QBrush(Qt::lightGray));
}


// Setean el color para cuando abiertas y cerradas

void MagneticSensorView::setCloseView(){
    switchView.setBrush(QBrush(Qt::green));
}
void MagneticSensorView::setOpenView(){
    switchView.setBrush(QBrush(Qt::red));
}

// Getter de las View

QGraphicsRectItem & MagneticSensorView::getSwitchView(){
    return switchView;
}
QGraphicsRectItem & MagneticSensorView::getMagnetView(){
    return magnetView;
}
