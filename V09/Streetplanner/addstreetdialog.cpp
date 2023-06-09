#include "addstreetdialog.h"
#include "ui_addstreetdialog.h"
#include "street.h"
#include "stateroad.h"
#include "motorway.h"

#include <QMessageBox>
#include <QStringList>

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

    QList<QString> streetTypes;
    streetTypes.append("Straße");
    streetTypes.append("Landstraße");
    streetTypes.append("Autobahn");
    ui->comboBox_streetType->addItems(streetTypes);

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

    Street* streetToBeAdded;
    switch (ui->comboBox_streetType->currentIndex()) {
    // 0 = Straße, 1 = Landstraße, 2 = Autobahn
    case 1:
        streetToBeAdded = new StateRoad(firstCity, secondCity);
        break;
    case 2:
        streetToBeAdded = new Motorway(firstCity, secondCity);
        break;
    default:
        streetToBeAdded = new Street(firstCity, secondCity);
        break;
    }


    map->addStreet(streetToBeAdded);
    close();

    QMessageBox messageBox;
    messageBox.setText(QString("Es wurde eine %1 zwischen den Städten %2 und %3 erstellt.").arg(ui->comboBox_streetType->currentText()).arg(firstCity->getName()).arg(secondCity->getName()));
    qDebug() << QString("Es wurde eine %1 zwischen den Städten %2 und %3 erstellt.").arg(ui->comboBox_streetType->currentText()).arg(firstCity->getName()).arg(secondCity->getName());
}

