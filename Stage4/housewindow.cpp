#include "housewindow.h"
#include "ui_housewindow.h"


//Constructor

HouseWindow::HouseWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::HouseWindow)
{
    ui->setupUi(this);
    ui->houseRegion->setScene(&interiorScene);
    ui->sirenRegion->setScene(&sirenScene);
    armbutton = ui->ArmButton;
    disarmbutton = ui->DisarmButton;
}
void HouseWindow::addHouseHollow(QGraphicsItemGroup * compoundItem){
    interiorScene.addItem(compoundItem);
}
// Anade la vista de la sirena

void HouseWindow::addSirenHollow(QGraphicsItemGroup * sirenItem){
    sirenScene.addItem(sirenItem);
}
//Destructor
HouseWindow::~HouseWindow()
{
    delete ui;
}

// Update a el label

void HouseWindow::updateZonesStatus(const QString& status){
    ui->label->setText(status);
}

//Getter de los botones.
QPushButton * HouseWindow::getarmbutton(){
    return armbutton;
}
QPushButton * HouseWindow::getdisarmbutton(){
    return disarmbutton;
}
