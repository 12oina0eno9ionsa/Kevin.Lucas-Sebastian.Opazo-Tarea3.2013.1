#include "window.h"

Window::Window()
{

}
//Constructor ventana , parametro entero zona

Window::Window(int zone): magneticSensor(zone) {
}

//Cambia el estado del sensor de la ventana.
void Window::changeState() {
    if (magneticSensor.isClose())
    {
        magneticSensor.setSensorOpen();
    }
    else
        magneticSensor.setSensorClose();
}

