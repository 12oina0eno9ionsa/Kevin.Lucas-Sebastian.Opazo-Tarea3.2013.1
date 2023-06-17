#include "central.h"
#include "siren.h"
#include "sirenview.h"
#include <iostream>


//Constructor
Central::Central(QObject *parent)
    : QObject(parent), timer(new QTimer(this)) {   // Timer para el control de zonas
    connect(timer, SIGNAL(timeout()), this, SLOT(checkZones()));
    timer ->start(200);
    SirenView * sv = new SirenView();
    siren= new Siren(sv);
    status=true;

}
void Central::addNewSensor(Sensor * ps) {
    zones.push_back(ps);
}

//Revisa las zonas

void Central::checkZones() {
    if(status){    //Si esta activada la alarma
        bool closeZones[2];
        checkCloseZones(closeZones);
        if (closeZones[0] && closeZones[1]){
            siren->stop();
            emit zonesStatusUpdated("Zonas Cerradas.");
        }
        else{
            siren->play();
            emit zonesStatusUpdated("Alguna zona esta abierta.");
        }
    }
    else{   //Si no esta activada
        siren->stop();   //Empieza animacion de la sirena
        emit zonesStatusUpdated("Alarma Desactivada");  // Emite la senal a housewindow label
    }

}

// Checkea una por una las zonas
void Central::checkCloseZones(bool closeZones[]) {
    closeZones[0] = closeZones[1] = true;
    for (unsigned int i=0; i< zones.size(); i++)
        if (!(zones[i]->isClose())) {
            closeZones[zones[i]->getZone()] = false;
        }
}
// Setea el estado de la alarma
void Central::setStatus(bool s){
    status=s;
}

//Getter de la sirena
Siren * Central::getSiren(){
    return siren;
}
Central::~Central(){
    delete timer;
}
