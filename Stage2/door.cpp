#include "door.h"

Door::Door()
{

}

//Constructor que crea el sensor de la puerta
Door::Door(int zone): magneticSensor(zone) {
}

//Cambia el estado del sensor de la puerta.
void Door::changeState() {
    if (magneticSensor.isClose())
    {
        magneticSensor.setSensorOpen();
    }
    else
        magneticSensor.setSensorClose();
}

