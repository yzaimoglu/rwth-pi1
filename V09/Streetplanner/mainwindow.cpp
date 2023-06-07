#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <chrono>
#include <QDebug>
#include <QMessageBox>
#include <QRandomGenerator>

#include "city.h"
#include "street.h"
#include "addcitydialog.h"
#include "mapionrw.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mapIo(new MapIoNrw())
{
    ui->setupUi(this);

    // Übergabe der QGraphicsScene an die GraphicsView
    ui->graphicsView->setScene(&scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_teste_was_clicked()
{
    qDebug() << QString("Teste was clicked");
    qDebug() << QString("[TEST] Die Eingabe wird auf eine Zahl geprüft.");
    QString lineEditText = ui->lineEdit_teste_was->text();
    QMessageBox messageBox;
    bool istZahl;
    int zahl = lineEditText.toInt(&istZahl);

    if(istZahl) {
        messageBox.setText(QString("Line Edit Ausgabe: %1").arg(zahl+4));
        qDebug() << QString("Line Edit Ausgabe: %1").arg(zahl+4);
    } else {
        messageBox.setText(QString("Die Eingabe ist keine Zahl."));
        qDebug() << QString("Die Eingabe ist keine Zahl.");
    }
    messageBox.exec();
    qDebug() << QString("[TEST] Die Eingabe wurde überprüft.");

    qDebug() << QString("[TEST] Generiere ein random positioniertes Viereck.");
    // qrand ist obsolet, deswegen wird die Nutzung von QRandomGenerator empfohlen s. QT-Dokumentation
    QRandomGenerator randomGenerator = QRandomGenerator::securelySeeded();
    int x = randomGenerator.bounded(10);
    int y = randomGenerator.bounded(10);
    qDebug() << QString("[TEST] Random positioniertes Viereck hinzugefügt.");

    scene.addRect(x, y, 10, 10);
}


void MainWindow::on_actionBeenden_triggered()
{
    qDebug() << QString("Close clicked");
    close();
}


void MainWindow::on_actionClear_Scene_triggered()
{
    qDebug() << QString("Clear scene clicked");
    scene.clear();
}


void MainWindow::on_actionAbout_triggered()
{
    qDebug() << QString("About clicked");
    QMessageBox aboutBox;
    aboutBox.about(this, QString("Über das Programm"), QString("Streetplanner ist ein Straßenplanner."));
}

void MainWindow::on_pushButton_teste_draw_city_clicked()
{
    qDebug() << QString("Test Draw City clicked");

    qDebug() << QString("[TEST] Erstelle die Städte firstCity und secondCity.");
    City* firstCity = new City("firstCity", 20, 20);
    City* secondCity = new City("secondCity", 40, 40);
    qDebug() << QString("[TEST] Die Städte firstCity und secondCity erstellt.");

    qDebug() << QString("[TEST] Zeichne die Städte auf die Map.");
    firstCity->draw(scene);
    secondCity->draw(scene);
    qDebug() << QString("[TEST] Die Städte auf die Map gezeichnet.");
}


void MainWindow::on_pushButton_teste_map_functions_clicked()
{
    qDebug() << QString("[TEST] Erstelle die Map.");

    qDebug() << QString("[TEST] Erstelle die Städte firstCity, secondCity und thirdCity");
    City* firstCity = new City("firstCity", 20, 20);
    City* secondCity = new City("secondCity", 40, 40);
    City* thirdCityNotOnMap = new City("thirdCity", 60, 60);
    qDebug() << QString("[TEST] Die Städte firstCity, secondCity und thirdCity erstellt.");

    qDebug() << QString("[TEST] Füge die Städte firstCity und secondCity der Map hinzu.");
    map.addCity(firstCity);
    map.addCity(secondCity);
    qDebug() << QString("[TEST] Die Städte firstCity und secondCity der Map hinzugefügt.");


    Street* streetFirstSecond = new Street(firstCity, secondCity);
    Street* streetFirstThird = new Street(firstCity, thirdCityNotOnMap);

    bool addedFirstSecond = map.addStreet(streetFirstSecond);
    bool addedFirstThird = map.addStreet(streetFirstThird);

    if(addedFirstSecond) qDebug() << QString("[TEST] Straße zw. firstCity und secondCity der Map hinzugefügt.");
    else qDebug() << QString("[TEST] Straße zw. firstCity und secondCity konnte nicht der Map hinzugefügt werden.");

    if(addedFirstThird) qDebug() << QString("[TEST] Straße zw. firstCity und thirdCity der Map hinzugefügt.");
    else qDebug() << QString("[TEST] Straße zw. firstCity und thirdCity konnte nicht der Map hinzugefügt werden.");

    map.draw(scene);
}


void MainWindow::on_checkBox_test_buttons_ausblenden_clicked()
{
    qDebug() << QString("Test Buttons Ausblenden clicked %1 -> %2").arg(!ui->checkBox_test_buttons_ausblenden->isChecked()).arg(ui->checkBox_test_buttons_ausblenden->isChecked());
    if(!ui->checkBox_test_buttons_ausblenden->isChecked()) {
        ui->label_eingabe->show();
        ui->lineEdit_teste_was->show();
        ui->pushButton_teste_draw_city->show();
        ui->pushButton_teste_map_functions->show();
        ui->pushButton_teste_was->show();
    } else {
        ui->label_eingabe->hide();
        ui->lineEdit_teste_was->hide();
        ui->pushButton_teste_draw_city->hide();
        ui->pushButton_teste_map_functions->hide();
        ui->pushButton_teste_was->hide();
    }
}


void MainWindow::on_pushButton_add_city_dialog_clicked()
{
    AddCityDialog addCityDialog = AddCityDialog();
    int statusDialog = addCityDialog.exec();
    if(!statusDialog) {
        qDebug() << QString("Hinzufügen einer Stadt abgebrochen.");
        return;
    }

    City* createdCity = addCityDialog.createCity();
    if(createdCity == nullptr) {
        qDebug() << QString("Die Koordinaten müssen Zahlen sein.");
        return;
    }

    qDebug() << QString("Die Stadt %1 mit den Koordinaten x: %2, y: %3 wurde erstellt.").arg(createdCity->getName()).arg(createdCity->getX()).arg(createdCity->getY());
    map.addCity(createdCity);
}


void MainWindow::on_pushButton_mapio_map_fill_clicked()
{
    qDebug() << QString("Fill Map clicked");
    mapIo->fillMap(map);
    map.draw(scene);
}


void MainWindow::on_pushButton_teste_abstract_map_clicked()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = map.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
}

