#include "addcitydialog.h"
#include "ui_addcitydialog.h"

AddCityDialog::AddCityDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCityDialog)
{
    ui->setupUi(this);
}

AddCityDialog::~AddCityDialog()
{
    delete ui;
}

City* AddCityDialog::createCity() {
    QString cityName = ui->lineEdit_city_name->text();
    bool xCoordinateOk;
    bool yCoordinateOk;
    int xCoordinate = ui->lineEdit_x_coord->text().toInt(&xCoordinateOk);
    int yCoordinate = ui->lineEdit_y_coord->text().toInt(&yCoordinateOk);
    if(!xCoordinateOk || !yCoordinateOk) {
        return nullptr;
    }
    return new City(cityName, xCoordinate, yCoordinate);
}
