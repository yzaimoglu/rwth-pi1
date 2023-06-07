#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

#include "map.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_teste_was_clicked();

    void on_actionBeenden_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_triggered();

    void on_pushButton_teste_draw_city_clicked();

    void on_pushButton_teste_map_functions_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    Map map;
};
#endif // MAINWINDOW_H
