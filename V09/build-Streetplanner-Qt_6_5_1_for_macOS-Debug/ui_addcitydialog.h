/********************************************************************************
** Form generated from reading UI file 'addcitydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCITYDIALOG_H
#define UI_ADDCITYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_AddCityDialog
{
public:
    QFormLayout *formLayout;
    QLabel *label_add_city;
    QLineEdit *lineEdit_city_name;
    QLineEdit *lineEdit_x_coord;
    QLineEdit *lineEdit_y_coord;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_create;

    void setupUi(QDialog *AddCityDialog)
    {
        if (AddCityDialog->objectName().isEmpty())
            AddCityDialog->setObjectName("AddCityDialog");
        AddCityDialog->resize(400, 300);
        formLayout = new QFormLayout(AddCityDialog);
        formLayout->setObjectName("formLayout");
        label_add_city = new QLabel(AddCityDialog);
        label_add_city->setObjectName("label_add_city");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_add_city);

        lineEdit_city_name = new QLineEdit(AddCityDialog);
        lineEdit_city_name->setObjectName("lineEdit_city_name");

        formLayout->setWidget(1, QFormLayout::LabelRole, lineEdit_city_name);

        lineEdit_x_coord = new QLineEdit(AddCityDialog);
        lineEdit_x_coord->setObjectName("lineEdit_x_coord");

        formLayout->setWidget(2, QFormLayout::LabelRole, lineEdit_x_coord);

        lineEdit_y_coord = new QLineEdit(AddCityDialog);
        lineEdit_y_coord->setObjectName("lineEdit_y_coord");

        formLayout->setWidget(3, QFormLayout::LabelRole, lineEdit_y_coord);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(4, QFormLayout::LabelRole, verticalSpacer);

        pushButton_cancel = new QPushButton(AddCityDialog);
        pushButton_cancel->setObjectName("pushButton_cancel");

        formLayout->setWidget(5, QFormLayout::LabelRole, pushButton_cancel);

        pushButton_create = new QPushButton(AddCityDialog);
        pushButton_create->setObjectName("pushButton_create");

        formLayout->setWidget(6, QFormLayout::LabelRole, pushButton_create);


        retranslateUi(AddCityDialog);

        pushButton_create->setDefault(true);


        QMetaObject::connectSlotsByName(AddCityDialog);
    } // setupUi

    void retranslateUi(QDialog *AddCityDialog)
    {
        AddCityDialog->setWindowTitle(QCoreApplication::translate("AddCityDialog", "Dialog", nullptr));
        label_add_city->setText(QCoreApplication::translate("AddCityDialog", "Stadt hinzuf\303\274gen", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_city_name->setToolTip(QCoreApplication::translate("AddCityDialog", "Name der Stadt", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit_city_name->setPlaceholderText(QCoreApplication::translate("AddCityDialog", "Stadtname", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_x_coord->setToolTip(QCoreApplication::translate("AddCityDialog", "X-Koordinate der Stadt", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit_x_coord->setPlaceholderText(QCoreApplication::translate("AddCityDialog", "X-Koordinate", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_y_coord->setToolTip(QCoreApplication::translate("AddCityDialog", "Y-Koordinate der Stadt", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit_y_coord->setPlaceholderText(QCoreApplication::translate("AddCityDialog", "Y-Koordinate", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("AddCityDialog", "Abbrechen", nullptr));
        pushButton_create->setText(QCoreApplication::translate("AddCityDialog", "Erstellen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddCityDialog: public Ui_AddCityDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCITYDIALOG_H
