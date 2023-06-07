#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <chrono>
#include <QDebug>
#include <QMessageBox>
#include <QRandomGenerator>

#include "city.h"
#include "street.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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

    // qrand ist obsolet, deswegen wird die Nutzung von QRandomGenerator empfohlen s. QT-Dokumentation
    QRandomGenerator randomGenerator = QRandomGenerator::securelySeeded();
    int x = randomGenerator.bounded(10);
    int y = randomGenerator.bounded(10);

    scene.addRect(x, y, 10, 10);
    qDebug() << QString("Teste was clicked");
}


void MainWindow::on_actionBeenden_triggered()
{
    qDebug() << QString("Close clicked");
    close();
}


void MainWindow::on_actionClear_Scene_triggered()
{
    scene.clear();
    qDebug() << QString("Clear scene clicked");
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox aboutBox;
    aboutBox.about(this, QString("Über das Programm"), QString("Streetplanner ist ein Straßenplanner."));
    qDebug() << QString("About clicked");
}

void MainWindow::on_pushButton_teste_draw_city_clicked()
{
    City* firstCity = new City("firstCity", 20, 20);
    City* secondCity = new City("secondCity", 40, 40);
    firstCity->draw(scene);
    secondCity->draw(scene);
    qDebug() << QString("Test Draw City clicked");
}


void MainWindow::on_pushButton_teste_map_functions_clicked()
{
    map = Map();
    City* firstCity = new City("firstCity", 20, 20);
    City* secondCity = new City("secondCity", 40, 40);
    City* thirdCityNotOnMap = new City("thirdCity", 60, 60);
    map.addCity(firstCity);
    map.addCity(secondCity);
    Street* streetFirstSecond = new Street(firstCity, secondCity);
    Street* streetFirstThird = new Street(firstCity, thirdCityNotOnMap);
    map.addStreet(streetFirstSecond);
    map.addStreet(streetFirstThird);
    map.draw(scene);
}

