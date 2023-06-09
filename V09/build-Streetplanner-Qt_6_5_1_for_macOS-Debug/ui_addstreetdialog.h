/********************************************************************************
** Form generated from reading UI file 'addstreetdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTREETDIALOG_H
#define UI_ADDSTREETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_AddStreetDialog
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBox_firstCity;
    QComboBox *comboBox_secondCity;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_ok;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *AddStreetDialog)
    {
        if (AddStreetDialog->objectName().isEmpty())
            AddStreetDialog->setObjectName("AddStreetDialog");
        AddStreetDialog->resize(400, 300);
        formLayout = new QFormLayout(AddStreetDialog);
        formLayout->setObjectName("formLayout");
        label = new QLabel(AddStreetDialog);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboBox_firstCity = new QComboBox(AddStreetDialog);
        comboBox_firstCity->setObjectName("comboBox_firstCity");

        formLayout->setWidget(1, QFormLayout::LabelRole, comboBox_firstCity);

        comboBox_secondCity = new QComboBox(AddStreetDialog);
        comboBox_secondCity->setObjectName("comboBox_secondCity");

        formLayout->setWidget(2, QFormLayout::LabelRole, comboBox_secondCity);

        pushButton_cancel = new QPushButton(AddStreetDialog);
        pushButton_cancel->setObjectName("pushButton_cancel");

        formLayout->setWidget(3, QFormLayout::LabelRole, pushButton_cancel);

        pushButton_ok = new QPushButton(AddStreetDialog);
        pushButton_ok->setObjectName("pushButton_ok");

        formLayout->setWidget(4, QFormLayout::LabelRole, pushButton_ok);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(5, QFormLayout::LabelRole, verticalSpacer);


        retranslateUi(AddStreetDialog);

        pushButton_ok->setDefault(true);


        QMetaObject::connectSlotsByName(AddStreetDialog);
    } // setupUi

    void retranslateUi(QDialog *AddStreetDialog)
    {
        AddStreetDialog->setWindowTitle(QCoreApplication::translate("AddStreetDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddStreetDialog", "Stra\303\237e hinzuf\303\274gen", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("AddStreetDialog", "Abbrechen", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("AddStreetDialog", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddStreetDialog: public Ui_AddStreetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTREETDIALOG_H
