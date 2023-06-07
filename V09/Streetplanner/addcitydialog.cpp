#include "addcitydialog.h"
#include "ui_addcitydialog.h"

#include <QMessageBox>

AddCityDialog::AddCityDialog(QWidget *parent, Map* map, QString cityNameUI, QString xCoordUI, QString yCoordUI) :
    QDialog(parent),
    ui(new Ui::AddCityDialog),
    map(map),
    cityNameUI(cityNameUI),
    xCoordUI(xCoordUI),
    yCoordUI(yCoordUI)
{
    ui->setupUi(this);

    if(map == nullptr) {
        QMessageBox messageBox;
        messageBox.setText("Die übergebene Map darf kein nullptr sein.");
        qDebug() << "Die übergebene Map darf kein nullptr sein.";
        messageBox.exec();
        return;
    }

    ui->lineEdit_city_name->setText(cityNameUI);
    ui->lineEdit_x_coord->setText(xCoordUI);
    ui->lineEdit_y_coord->setText(yCoordUI);
}

AddCityDialog::~AddCityDialog()
{
    delete ui;
}

void AddCityDialog::createCity(QString cityName, int xCoordinate, int yCoordinate) {
    City* createdCity = new City(cityName, xCoordinate, yCoordinate);
    qDebug() << QString("Die Stadt %1 mit den Koordinaten x: %2, y: %3 wurde erstellt.").arg(createdCity->getName()).arg(createdCity->getX()).arg(createdCity->getY());
    (*map).addCity(createdCity);
}

void AddCityDialog::on_pushButton_create_clicked()
{
    QString cityName = ui->lineEdit_city_name->text();
    bool xCoordinateOk;
    bool yCoordinateOk;
    std::size_t cityNameOk;
    int xCoordinate = ui->lineEdit_x_coord->text().toInt(&xCoordinateOk);
    int yCoordinate = ui->lineEdit_y_coord->text().toInt(&yCoordinateOk);
    cityNameOk = cityName.toStdString().find_first_not_of("aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZäÄ ");
    qDebug() << QString("%1 %2 %3").arg(cityNameOk).arg(xCoordinateOk).arg(yCoordinateOk);
    if(!xCoordinateOk || !yCoordinateOk || !(cityNameOk == std::string::npos)) {
        QMessageBox messageBox;
        messageBox.setText("Die Koordinaten müssen aus Zahlen bestehen und der Stadtname aus dem deutschen Alphabet.");
        qDebug() << "Die Koordinaten müssen aus Zahlen bestehen und der Stadtname aus dem deutschen Alphabet.";
        messageBox.exec();
        return;
    }

    if(map->getCityList().contains(map->findCity(cityName))) {
        QMessageBox messageBox;
        messageBox.setText("Die Map hat bereits diese Stadt.");
        qDebug() << "Die Map hat bereits diese Stadt.";
        messageBox.exec();
        return;
    }
    createCity(cityName, xCoordinate, yCoordinate);
    close();
}


void AddCityDialog::on_pushButton_cancel_clicked()
{
    QMessageBox messageBox;
    messageBox.setText("Die Stadterstellung wurde abgebrochen.");
    qDebug() << "Die Stadterstellung wurde abgebrochen.";
    messageBox.exec();
    close();
}

