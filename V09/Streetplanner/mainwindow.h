#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

#include "map.h"
#include "mapio.h"

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

    void on_checkBox_test_buttons_ausblenden_clicked();

    void on_pushButton_add_city_dialog_clicked();

    void on_pushButton_mapio_map_fill_clicked();

    void on_pushButton_teste_abstract_map_clicked();

    void on_pushButton_teste_dijkstra_algorithm_clicked();

    void on_pushButton_dijkstra_dialog_clicked();

    void on_pushButton_mapio_map_fill_file_clicked();

    void on_pushButton_add_street_dialog_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    Map map;
    MapIo* mapIo;
};
#endif // MAINWINDOW_H
