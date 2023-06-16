#include <iostream>
#include <fstream>
#include <vector>
#include "door.h"
#include <filesystem>

using namespace std;

int main(int argc, char * argv[]) {


    fstream fin("");
    int nDoors, junk;
    vector<Door *> doors;

    if (argc != 2) {
        cout << "Usage: "<<argv[0]<<" <configuration_file>" << endl;
        return -1;
    }

    fin.open(argv[1]);
    if (fin.fail()){
        cout << "Could not read file" << endl;
        return -2;
    }

    cout << "Argument:" << argv[1] << endl;

    fin >> nDoors;
    fin >> junk;
    cout << "nDoors:" << nDoors << " junk: " << junk << endl;

    // Crea las nDoors puertas utilizando solo la zona.

    for( int i=0; i<nDoors; i++) {
        int zone;
        fin >> junk >> junk >> junk >> zone;
        doors.push_back(new Door(zone));
    }

    //Abre y cierra todas las puertas

    for (unsigned int i=0; i<doors.size(); i++) {
        cout<<"Door "<<i+1<<endl;
        doors[i]->changeState();
        doors[i]->changeState();
    }

    return 0;

}
