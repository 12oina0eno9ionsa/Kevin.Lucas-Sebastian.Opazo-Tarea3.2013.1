#ifndef HOUSEWINDOW_H
#define HOUSEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPushButton>
#include <QGraphicsItemGroup>

QT_BEGIN_NAMESPACE
namespace Ui { class HouseWindow; }
QT_END_NAMESPACE

class HouseWindow : public QMainWindow
{
    Q_OBJECT

public:
    HouseWindow(QWidget *parent = nullptr);
    void addHouseHollow(QGraphicsItemGroup * ); // doors and windows
    void addSirenHollow(QGraphicsItemGroup * );
    QPushButton * getarmbutton();
    QPushButton * getdisarmbutton();
    ~HouseWindow();

private:
    Ui::HouseWindow *ui;
    QGraphicsScene interiorScene;
    QGraphicsScene sirenScene;
    QPushButton * armbutton;
    QPushButton * disarmbutton;


signals:
    void zonesStatusUpdated(QString status);

public slots:
    void updateZonesStatus(const QString& status);
};
#endif // HOUSEWINDOW_H
