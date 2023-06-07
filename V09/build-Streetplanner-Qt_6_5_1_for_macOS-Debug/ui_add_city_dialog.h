/********************************************************************************
** Form generated from reading UI file 'add_city_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_CITY_DIALOG_H
#define UI_ADD_CITY_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>

QT_BEGIN_NAMESPACE

class Ui_add_city_dialog
{
public:
    QFormLayout *formLayout;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *add_city_dialog)
    {
        if (add_city_dialog->objectName().isEmpty())
            add_city_dialog->setObjectName("add_city_dialog");
        add_city_dialog->resize(400, 300);
        formLayout = new QFormLayout(add_city_dialog);
        formLayout->setObjectName("formLayout");
        buttonBox = new QDialogButtonBox(add_city_dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(0, QFormLayout::LabelRole, buttonBox);


        retranslateUi(add_city_dialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, add_city_dialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, add_city_dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(add_city_dialog);
    } // setupUi

    void retranslateUi(QDialog *add_city_dialog)
    {
        add_city_dialog->setWindowTitle(QCoreApplication::translate("add_city_dialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add_city_dialog: public Ui_add_city_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_CITY_DIALOG_H
