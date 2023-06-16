#include "sensor.h"
#include <iostream>
using namespace std;
Sensor::Sensor(int z, bool close){
    zone=z;
    this->close= close;
}

// Getter del estado del sensor Close, y int zone
bool Sensor::isClose() const {
    return close;
}
int Sensor::getZone() const {
    return zone;
}

//Setea el estado del sensor.
void Sensor::setClose(bool isClose) {
    close=isClose;
    cout << "Sensor is "<< (close?"close":"open")<< endl;
}
