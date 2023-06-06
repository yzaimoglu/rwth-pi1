#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <chrono>
#include <QDebug>
#include <QMessageBox>
#include <QRandomGenerator>

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
}


void MainWindow::on_actionBeenden_triggered()
{
    exit(0);
}

