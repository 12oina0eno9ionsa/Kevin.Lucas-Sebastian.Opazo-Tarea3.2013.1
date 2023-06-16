#include "window.h"
#include "windowview.h"

Window::Window() {}
//Constructor
Window::Window(MagneticSensor * sensor, WindowView * v)
    : magneticSensor(sensor), view(v)
{
    isClose=true;
    view->setWindowModel(this);
}

//Cambia la vista de la ventana y cambia el estado del sensor. Se aplica para ambos casos
//para abrir y para cerrar.
void Window::changeState()
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
