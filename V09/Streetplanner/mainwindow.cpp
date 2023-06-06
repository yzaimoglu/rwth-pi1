#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_teste_was_clicked()
{
    QString lineEditText = ui->lineEdit_teste_was->text();
    bool istZahl;
    int zahl = lineEditText.toInt(&istZahl);
    if(istZahl) {
        qDebug() << QString("Line Edit Ausgabe: %1").arg(zahl+4);
    } else {
        qDebug() << QString("Die Eingabe ist keine Zahl.");
    }
}

