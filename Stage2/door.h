#ifndef DOOR_H
#define DOOR_H
#include "magnetic_sensor.h"
class Door
{
private:
    Door(); // a door creation without sensor is not allowed.
public:
    Door(int zone);
    void changeState();
    int getzone();
private:
    MagneticSensor magneticSensor;
};

#endif // DOOR_H
