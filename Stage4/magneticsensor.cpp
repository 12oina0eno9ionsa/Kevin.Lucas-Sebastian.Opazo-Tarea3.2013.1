#include "magneticsensor.h"

MagneticSensor::MagneticSensor(int z): Sensor(z,true) {
    view = new MagneticSensorView();
}

// Setters para controlar el estado del sensor


void MagneticSensor::setSensorOpen() {
    setClose(false);
    view->setOpenView();
}
void MagneticSensor::setSensorClose() {
    setClose(true);
    view->setCloseView();
}
MagneticSensorView * MagneticSensor::getView() {
    return view;
}
MagneticSensor::~MagneticSensor(){
    delete view;
}
