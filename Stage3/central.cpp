#include "central.h"
#include <iostream>

// Timer que checkea la zona cada 200ms

Central::Central(QObject *parent)
    : QObject(parent), timer(new QTimer(this)) {
    connect(timer, SIGNAL(timeout()), this, SLOT(checkZones()));
    timer ->start(200);
}

// Agrega sensor a la lista de zonas

void Central::addNewSensor(Sensor * ps) {
    zones.push_back(ps);
}



void Central::checkZones() {
    bool closeZones[2];
    checkCloseZones(closeZones);
    if (closeZones[0] && closeZones[1])
        std::cout << "Zonas Cerradas." << std::endl;
    else
        std::cout << "Alguna zona esta abierta." << std::endl;
}

// Revisa las zonas cerradas.
void Central::checkCloseZones(bool closeZones[]) {
    closeZones[0] = closeZones[1] = true;
    for (unsigned int i=0; i< zones.size(); i++)
        if (!(zones[i]->isClose())) {
            closeZones[zones[i]->getZone()] = false;
        }
}
// Destructor
Central::~Central(){
    delete timer;
}
