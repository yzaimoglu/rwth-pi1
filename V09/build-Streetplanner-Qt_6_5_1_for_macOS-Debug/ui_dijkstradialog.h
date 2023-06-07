/********************************************************************************
** Form generated from reading UI file 'dijkstradialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIJKSTRADIALOG_H
#define UI_DIJKSTRADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_DijkstraDialog
{
public:
    QFormLayout *formLayout;
    QComboBox *comboBox_firstCity;
    QComboBox *comboBox_secondCity;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DijkstraDialog)
    {
        if (DijkstraDialog->objectName().isEmpty())
            DijkstraDialog->setObjectName("DijkstraDialog");
        DijkstraDialog->resize(400, 300);
        formLayout = new QFormLayout(DijkstraDialog);
        formLayout->setObjectName("formLayout");
        comboBox_firstCity = new QComboBox(DijkstraDialog);
        comboBox_firstCity->setObjectName("comboBox_firstCity");

        formLayout->setWidget(1, QFormLayout::LabelRole, comboBox_firstCity);

        comboBox_secondCity = new QComboBox(DijkstraDialog);
        comboBox_secondCity->setObjectName("comboBox_secondCity");

        formLayout->setWidget(2, QFormLayout::LabelRole, comboBox_secondCity);

        label = new QLabel(DijkstraDialog);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(4, QFormLayout::LabelRole, verticalSpacer);

        buttonBox = new QDialogButtonBox(DijkstraDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(3, QFormLayout::LabelRole, buttonBox);


        retranslateUi(DijkstraDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DijkstraDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DijkstraDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DijkstraDialog);
    } // setupUi

    void retranslateUi(QDialog *DijkstraDialog)
    {
        DijkstraDialog->setWindowTitle(QCoreApplication::translate("DijkstraDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DijkstraDialog", "Dijkstra - K\303\274rzeste Weg Suche", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DijkstraDialog: public Ui_DijkstraDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIJKSTRADIALOG_H
