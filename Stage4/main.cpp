#include "housewindow.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include <vector>
#include "door.h"
#include "window.h"
#include "doorview.h"
#include "windowview.h"
#include "central.h"
#include <QtWidgets>
//using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HouseWindow gui;  // gui: Graphical User Interface
    Central central;
    std::ifstream fin;
    int nDoors, nWindows;
    std::vector<Door *> doors;
    std::vector<Window *> windows;
    if (argc != 2) {
        std::cout << "Usage: "<<argv[0]<<" <configuration_file>" << std::endl;
        return -1;
    }
    fin.open(argv[1]);
    if (fin.fail()){
        std::cout << "Could not read file" << std::endl;
        return -2;
    }
    std::cout << "Argument:" << argv[1] << std::endl;
    fin >> nDoors;
    fin >> nWindows;
    std::cout << "nDoors:" << nDoors << " nWindows: " << nWindows << std::endl;

    //Crea las nDoors puertas
    for( int i=0; i<nDoors; i++) {
        int x, y, angle, zone;
        fin >> x >> y >> angle >> zone;
        MagneticSensor * sensor = new MagneticSensor(zone);
        DoorView * doorView = new DoorView(x,y,angle, sensor->getView());
        doors.push_back(new Door(sensor, doorView));
        central.addNewSensor(sensor);
        gui.addHouseHollow(doorView);
    }
    // Crea las nWindows ventanas
    for( int i=0; i<nWindows; i++) {
        int x, y, angle, zone;
        fin >> x >> y >> angle >> zone;
        MagneticSensor * sensor = new MagneticSensor(zone);
        WindowView * windowView = new WindowView(x,y,angle, sensor->getView());
        windows.push_back(new Window(sensor, windowView));
        central.addNewSensor(sensor);
        gui.addHouseHollow(windowView);
    }

    gui.addSirenHollow(central.getSiren()->getView());


    //Eventos botones cuando son clickeados armar y desarmar

    QObject::connect(gui.getarmbutton(), &QPushButton::clicked, [&central]() {
        central.setStatus(true);
    });
    QObject::connect(gui.getdisarmbutton(), &QPushButton::clicked, [&central]() {
        central.setStatus(false);
    });

    //Checkea las zonas periodicamente
    QObject::connect(&central, SIGNAL(zonesStatusUpdated(QString)), &gui, SLOT(updateZonesStatus(QString)));

    gui.show();
    return a.exec();
}
