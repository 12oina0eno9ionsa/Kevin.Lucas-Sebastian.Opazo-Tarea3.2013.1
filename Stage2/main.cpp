#include <iostream>
#include <fstream>
#include <vector>
#include <map>

#include "door.h"
#include "window.h"
using namespace std;

int main(int argc, char * argv[]) {
    ifstream fin;
    int nDoors, nWindows, junk;
    vector<Door *> doors;
    vector<Window *> windows;
    map<int,bool> zones;

    zones.insert(make_pair(0,false));
    zones.insert(make_pair(1,false));
    zones.insert(make_pair(2,false));





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
    fin >> nWindows;
    cout << "nDoors:" << nDoors << " nWindows: " << nWindows << endl;
    int zone;
    for( int i=0; i<nDoors; i++) {
        fin >> junk >> junk >> junk >> zone;
        doors.push_back(new Door(zone));
    }
    for(int i=0;i<nWindows;i++){
        fin >> junk >> junk >> junk >> zone;
        windows.push_back(new Window(zone));
    }
    for (unsigned int i=0; i<doors.size(); i++) {
        cout<<"Door "<<i+1<<endl;
        doors[i]->changeState();
        doors[i]->changeState();
    }
    for (unsigned int i=0; i<windows.size(); i++){
        cout<<"Window "<<i+1<<endl;
        windows[i]->changeState();
        windows[i]->changeState();
    }


    bool flag=false;

    for(int i=0;i<zones.size();i++){
        if(!zones[1]){
            flag=true;
            break;
        }
    }


    cout<<"Checking :"<<endl;

    if(flag) cout<<"Alguna zona esta abierta"<<endl;
    else "Zonas Cerradas";

    cout<<"Door 0"<<endl;
    doors[0]->changeState();

    for(int i=0;i<zones.size();i++){
        if(!zones[1]){
            flag=false;
            break;
        }
    }


    cout<<"Checking :"<<endl;
    if(flag) cout<<"Alguna zona esta abierta"<<endl;
    else cout<<"Zonas Cerradas"<<endl;;


}
