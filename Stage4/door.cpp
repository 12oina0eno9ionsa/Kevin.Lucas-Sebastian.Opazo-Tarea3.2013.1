#include "door.h"
#include "doorview.h"

Door::Door() {}
// Constructor
Door::Door(MagneticSensor * sensor, DoorView * v)
    : magneticSensor(sensor), view(v)
{
    isClose=true;
    view->setDoorModel(this);
}

// Cambia el estado de la puerta (Metodo invocado al capturar un evento)
// Si esta abierto cierra la vista y cambia el estado del sensor. Caso contrario en el else.

void Door::changeState()
{
    if (magneticSensor->isClose())
    {
        view->setOpen();
        magneticSensor->setSensorOpen();
    }
    else
    {
        view->setClose();
        magneticSensor->setSensorClose();
    }
}
