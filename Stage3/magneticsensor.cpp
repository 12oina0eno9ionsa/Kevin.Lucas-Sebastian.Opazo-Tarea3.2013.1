#include "magneticsensor.h"

//Constructor, crea y asigna la vista del sensor.

MagneticSensor::MagneticSensor(int z): Sensor(z,true) {
    view = new MagneticSensorView();
}

//Setters para cambiar el estado del sensor y su vista.

void MagneticSensor::setSensorOpen() {
    setClose(false);
    view->setOpenView();
}
void MagneticSensor::setSensorClose() {
    setClose(true);
    view->setCloseView();
}

//Getter vista del sensor

MagneticSensorView * MagneticSensor::getView() {
    return view;
}

//Destructor
MagneticSensor::~MagneticSensor(){
    delete view;
}
