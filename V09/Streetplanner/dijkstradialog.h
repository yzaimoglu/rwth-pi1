#ifndef DIJKSTRADIALOG_H
#define DIJKSTRADIALOG_H

#include <QDialog>
#include "map.h"

namespace Ui {
class DijkstraDialog;
}

class DijkstraDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DijkstraDialog(QWidget *parent = nullptr, Map* map = nullptr);
    ~DijkstraDialog();
    QVector<Street*> dijkstra();

private:
    Ui::DijkstraDialog *ui;
    Map* map;
};

#endif // DIJKSTRADIALOG_H
