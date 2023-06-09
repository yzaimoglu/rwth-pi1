#include "addstreetdialog.h"
#include "ui_addstreetdialog.h"
#include "street.h"

#include <QMessageBox>

AddStreetDialog::AddStreetDialog(QWidget *parent, Map* map) :
    QDialog(parent),
    ui(new Ui::AddStreetDialog),
    map(map)
{
    ui->setupUi(this);

    if(map == nullptr) {
        qDebug() << "Die Map darf kein nullptr sein.";
        this->close();
    }

    foreach(City* city, map->getCityList()) {
        qDebug() << city->getName();
        ui->comboBox_firstCity->addItem(city->getName());
        ui->comboBox_secondCity->addItem(city->getName());
    }
}

AddStreetDialog::~AddStreetDialog()
{
    delete ui;
}

void AddStreetDialog::on_pushButton_cancel_clicked()
{
    close();
}


void AddStreetDialog::on_pushButton_ok_clicked()
{
    if(ui->comboBox_firstCity->currentText() == ui->comboBox_secondCity->currentText()) {
        QMessageBox messageBox;
        messageBox.setText(QString("Du kannst keine Straße zwischen derselben Stadt erstellen."));
        qDebug() << QString("Du kannst keine Straße zwischen derselben Stadt erstellen.");
        messageBox.exec();
        return;
    }

    City* firstCity = map->findCity(ui->comboBox_firstCity->currentText());
    City* secondCity = map->findCity(ui->comboBox_secondCity->currentText());

    foreach(Street* street, map->getStreetList(firstCity)) {
        if(street->getFirstCity() == secondCity || street->getSecondCity() == secondCity) {
            QMessageBox messageBox;
            messageBox.setText(QString("Zwischen diesen Städten ist bereits eine Straße."));
            qDebug() << QString("Zwischen diesen Städten ist bereits eine Straße.");
            messageBox.exec();
            return;
        }
    }

    Street* streetToBeAdded = new Street(firstCity, secondCity);
    map->addStreet(streetToBeAdded);
    close();

    QMessageBox messageBox;
    messageBox.setText(QString("Es wurde eine Straße zwischen den Städten %1 und %2 erstellt.").arg(firstCity->getName()).arg(secondCity->getName()));
    qDebug() << QString("Es wurde eine Straße zwischen den Städten %1 und %2 erstellt.").arg(firstCity->getName()).arg(secondCity->getName());
}

