#ifndef SIREN_H
#define SIREN_H
#include <QTimer>


class SirenView;

class Siren : public QObject
{
private:
    Siren();
public:
    Siren(SirenView * sv);
    SirenView * getView();
    void play();
    void stop();
private:
    SirenView * model;
    bool status;
    QTimer * timer;


};

#endif // SIREN_H
