#include "magnetic_sensor.h"

MagneticSensor::MagneticSensor(int z) : Sensor(z,true) {
}

//Setean el estado del sensor abierto y cerrado (bool).
void MagneticSensor::setSensorOpen() {
    setClose(false);
}
void MagneticSensor::setSensorClose() {
    setClose(true);
}
