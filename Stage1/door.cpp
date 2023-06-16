#include "door.h"

Door::Door()
{

}
Door::Door(int zone): magneticSensor(zone) {
}
void Door::changeState() {
    if (magneticSensor.isClose())
    {
        magneticSensor.setSensorOpen();
    }
    else
        magneticSensor.setSensorClose();
}


bool Door::getState(){
    return magneticSensor.isClose();
}
