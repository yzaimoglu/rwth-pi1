#include "dijkstradialog.h"
#include "ui_dijkstradialog.h"
#include "dijkstra.h"

#include <QMessageBox>

DijkstraDialog::DijkstraDialog(QWidget *parent, Map* map) :
    QDialog(parent),
    ui(new Ui::DijkstraDialog),
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

DijkstraDialog::~DijkstraDialog()
{
    delete ui;
}

QVector<Street*> DijkstraDialog::dijkstra() {
    if(!ui->comboBox_firstCity->currentText().compare(ui->comboBox_secondCity->currentText())) {
        QMessageBox messageBox;
        messageBox.setText(QString("Die Städte müssen verschieden sein."));
        qDebug() << QString("Die Städte müssen verschieden sein.");
        messageBox.exec();
        return QVector<Street*>();
    }

    QVector<Street*> streets = Dijkstra::search(*map, ui->comboBox_firstCity->currentText(), ui->comboBox_secondCity->currentText());
    if(streets.empty()) {
        QMessageBox messageBox;
        qDebug() << QString("Zwischen diesen beiden Städten ist keine Strecke vorhanden");
        messageBox.setText("Zwischen diesen beiden Städten ist keine Strecke vorhanden");
        messageBox.exec();
    }
    return streets;
}
