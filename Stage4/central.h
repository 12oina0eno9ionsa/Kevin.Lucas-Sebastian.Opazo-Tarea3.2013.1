#ifndef CENTRAL_H
#define CENTRAL_H
#include <QObject>
#include <vector>
#include <QTimer>
#include <QMainWindow>
#include <QLabel>
#include "siren.h"
#include "sirenview.h"
#include "sensor.h"
//using namespace std; //needed by vector<>

class Central : public QObject //, public OtraClase
{
    Q_OBJECT
public:
    explicit Central(QObject *parent = nullptr);
    void addNewSensor(Sensor * ps);
    Siren * getSiren();
    void setStatus(bool s);
    ~Central();
private slots:
    void checkZones();
signals:
    void zonesStatusUpdated(QString status);

private:
    void checkCloseZones(bool closeZones[]);
    std::vector<Sensor *> zones;  // keep references to all sensors already installed in doors and windows.
    QTimer * timer;
    Siren * siren;
    bool status;
};

#endif // CENTRAL_H
