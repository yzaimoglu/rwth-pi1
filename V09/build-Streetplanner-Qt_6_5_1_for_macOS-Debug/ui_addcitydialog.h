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
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_AddCityDialog
{
public:
    QFormLayout *formLayout;
    QLabel *label_add_city;
    QLineEdit *lineEdit_city_name;
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit_x_coord;
    QLineEdit *lineEdit_y_coord;
    QSpacerItem *verticalSpacer;

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

        buttonBox = new QDialogButtonBox(AddCityDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(5, QFormLayout::LabelRole, buttonBox);

        lineEdit_x_coord = new QLineEdit(AddCityDialog);
        lineEdit_x_coord->setObjectName("lineEdit_x_coord");

        formLayout->setWidget(2, QFormLayout::LabelRole, lineEdit_x_coord);

        lineEdit_y_coord = new QLineEdit(AddCityDialog);
        lineEdit_y_coord->setObjectName("lineEdit_y_coord");

        formLayout->setWidget(3, QFormLayout::LabelRole, lineEdit_y_coord);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(4, QFormLayout::LabelRole, verticalSpacer);


        retranslateUi(AddCityDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddCityDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddCityDialog, qOverload<>(&QDialog::reject));

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
    } // retranslateUi

};

namespace Ui {
    class AddCityDialog: public Ui_AddCityDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCITYDIALOG_H
