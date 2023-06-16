#include "sensor.h"
#include <iostream>
using namespace std;

//Constructor sensor.
Sensor::Sensor(int z, bool close){
    zone=z;
    this->close= close;
}

//Getter del estado y zona.

bool Sensor::isClose() const {
    return close;
}
int Sensor::getZone() const {
    return zone;
}

//Setter del estado del sensor.

void Sensor::setClose(bool isClose) {
    close=isClose;
    cout << "Sensor is "<< (close?"close":"open") << " in zone " << zone << endl;
}
