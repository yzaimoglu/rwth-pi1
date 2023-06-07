/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionBeenden;
    QAction *actionClear_Scene;
    QAction *actionAbout;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label_eingabe;
    QLineEdit *lineEdit_teste_was;
    QPushButton *pushButton_teste_map_functions;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_add_city_dialog;
    QPushButton *pushButton_mapio_map_fill;
    QPushButton *pushButton_teste_was;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_teste_draw_city;
    QCheckBox *checkBox_test_buttons_ausblenden;
    QPushButton *pushButton_teste_abstract_map;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuScene;
    QMenu *menuInformation;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionOpen->setEnabled(false);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionSave->setEnabled(false);
        actionBeenden = new QAction(MainWindow);
        actionBeenden->setObjectName("actionBeenden");
        actionBeenden->setShortcutContext(Qt::WindowShortcut);
        actionClear_Scene = new QAction(MainWindow);
        actionClear_Scene->setObjectName("actionClear_Scene");
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(-1);
        label_eingabe = new QLabel(centralwidget);
        label_eingabe->setObjectName("label_eingabe");

        gridLayout->addWidget(label_eingabe, 0, 0, 1, 1);

        lineEdit_teste_was = new QLineEdit(centralwidget);
        lineEdit_teste_was->setObjectName("lineEdit_teste_was");
        lineEdit_teste_was->setClearButtonEnabled(true);

        gridLayout->addWidget(lineEdit_teste_was, 1, 0, 1, 1);

        pushButton_teste_map_functions = new QPushButton(centralwidget);
        pushButton_teste_map_functions->setObjectName("pushButton_teste_map_functions");

        gridLayout->addWidget(pushButton_teste_map_functions, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 9, 0, 1, 1);

        pushButton_add_city_dialog = new QPushButton(centralwidget);
        pushButton_add_city_dialog->setObjectName("pushButton_add_city_dialog");

        gridLayout->addWidget(pushButton_add_city_dialog, 7, 0, 1, 1);

        pushButton_mapio_map_fill = new QPushButton(centralwidget);
        pushButton_mapio_map_fill->setObjectName("pushButton_mapio_map_fill");

        gridLayout->addWidget(pushButton_mapio_map_fill, 8, 0, 1, 1);

        pushButton_teste_was = new QPushButton(centralwidget);
        pushButton_teste_was->setObjectName("pushButton_teste_was");

        gridLayout->addWidget(pushButton_teste_was, 2, 0, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        gridLayout->addWidget(graphicsView, 0, 2, 10, 1);

        pushButton_teste_draw_city = new QPushButton(centralwidget);
        pushButton_teste_draw_city->setObjectName("pushButton_teste_draw_city");

        gridLayout->addWidget(pushButton_teste_draw_city, 3, 0, 1, 1);

        checkBox_test_buttons_ausblenden = new QCheckBox(centralwidget);
        checkBox_test_buttons_ausblenden->setObjectName("checkBox_test_buttons_ausblenden");

        gridLayout->addWidget(checkBox_test_buttons_ausblenden, 6, 0, 1, 1);

        pushButton_teste_abstract_map = new QPushButton(centralwidget);
        pushButton_teste_abstract_map->setObjectName("pushButton_teste_abstract_map");

        gridLayout->addWidget(pushButton_teste_abstract_map, 5, 0, 1, 1);

        gridLayout->setColumnStretch(2, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuScene = new QMenu(menubar);
        menuScene->setObjectName("menuScene");
        menuInformation = new QMenu(menubar);
        menuInformation->setObjectName("menuInformation");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuScene->menuAction());
        menubar->addAction(menuInformation->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionBeenden);
        menuScene->addAction(actionClear_Scene);
        menuInformation->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionBeenden->setText(QCoreApplication::translate("MainWindow", "Beenden", nullptr));
#if QT_CONFIG(shortcut)
        actionBeenden->setShortcut(QCoreApplication::translate("MainWindow", "Alt+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClear_Scene->setText(QCoreApplication::translate("MainWindow", "Clear Scene", nullptr));
#if QT_CONFIG(shortcut)
        actionClear_Scene->setShortcut(QCoreApplication::translate("MainWindow", "Alt+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "Streetplanner", nullptr));
        label_eingabe->setText(QCoreApplication::translate("MainWindow", "Ihre Eingabe", nullptr));
        lineEdit_teste_was->setText(QString());
        lineEdit_teste_was->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ihre Eingabe", nullptr));
        pushButton_teste_map_functions->setText(QCoreApplication::translate("MainWindow", "Teste Map Funktionen", nullptr));
        pushButton_add_city_dialog->setText(QCoreApplication::translate("MainWindow", "Stadt hinzuf\303\274gen", nullptr));
        pushButton_mapio_map_fill->setText(QCoreApplication::translate("MainWindow", "Fill Map", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_teste_was->setToolTip(QCoreApplication::translate("MainWindow", "Testet, ob Ihre Eingabe eine Zahl oder ein Text ist", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_teste_was->setText(QCoreApplication::translate("MainWindow", "Teste was", nullptr));
        pushButton_teste_draw_city->setText(QCoreApplication::translate("MainWindow", "Teste Draw City", nullptr));
        checkBox_test_buttons_ausblenden->setText(QCoreApplication::translate("MainWindow", "Test Buttons ausblenden", nullptr));
        pushButton_teste_abstract_map->setText(QCoreApplication::translate("MainWindow", "Teste Abstract Map", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuScene->setTitle(QCoreApplication::translate("MainWindow", "Scene", nullptr));
        menuInformation->setTitle(QCoreApplication::translate("MainWindow", "Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
