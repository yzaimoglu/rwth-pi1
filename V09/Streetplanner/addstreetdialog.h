#ifndef ADDSTREETDIALOG_H
#define ADDSTREETDIALOG_H

#include <QDialog>

#include "map.h"

namespace Ui {
class AddStreetDialog;
}

class AddStreetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddStreetDialog(QWidget *parent = nullptr, Map* map = nullptr);
    ~AddStreetDialog();

private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButton_ok_clicked();

private:
    Ui::AddStreetDialog *ui;
    Map* map;
};

#endif // ADDSTREETDIALOG_H
