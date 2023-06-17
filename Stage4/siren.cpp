#include "siren.h"
#include "sirenview.h"
#include <QUrl>


//Constructor
Siren::Siren(SirenView * sv)
    : model(sv)
{

    model->setSirenModel(this);
    status=false;
    timer = new QTimer(this);  //Timer para la animacion Blinking cada 100ms
    timer->setInterval(100);
    QObject::connect(timer,&QTimer::timeout,[=](){
        this->getView()->Blinking();
    });
}


//Empieza el timer, empieza la animacion Blinking
void Siren::play(){

    timer->start();
}
// Para el timer
void Siren::stop(){

    timer->stop();
    model->stopBlinking();

}
//Get Vista

SirenView * Siren::getView(){
    return model;
}

