#ifndef ADDCITYDIALOG_H
#define ADDCITYDIALOG_H

#include <QDialog>

#include "map.h"

namespace Ui {
class AddCityDialog;
}

class AddCityDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddCityDialog(QWidget *parent = nullptr, Map* map = nullptr, QString cityNameUI = "", QString xCoordUI = "", QString yCoordUI = "");
    ~AddCityDialog();
    void createCity(QString cityName, int xCoordinate, int yCoordinate, int cityType);

private slots:
    void on_pushButton_create_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::AddCityDialog *ui;
    Map* map;
    QString cityNameUI;
    QString xCoordUI;
    QString yCoordUI;
};

#endif // ADDCITYDIALOG_H
