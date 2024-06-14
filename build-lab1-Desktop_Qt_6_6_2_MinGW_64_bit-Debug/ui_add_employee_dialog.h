/********************************************************************************
** Form generated from reading UI file 'add_employee_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_EMPLOYEE_DIALOG_H
#define UI_ADD_EMPLOYEE_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddEmployeeDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *hourlyRateLabel;
    QDoubleSpinBox *hourlyRateDoubleSpinBox;

    void setupUi(QDialog *AddEmployeeDialog)
    {
        if (AddEmployeeDialog->objectName().isEmpty())
            AddEmployeeDialog->setObjectName("AddEmployeeDialog");
        AddEmployeeDialog->resize(400, 120);
        buttonBox = new QDialogButtonBox(AddEmployeeDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(290, 40, 81, 71));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget_3 = new QWidget(AddEmployeeDialog);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(30, 10, 160, 101));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(verticalLayoutWidget_3);
        nameLabel->setObjectName("nameLabel");

        verticalLayout_2->addWidget(nameLabel);

        nameLineEdit = new QLineEdit(verticalLayoutWidget_3);
        nameLineEdit->setObjectName("nameLineEdit");

        verticalLayout_2->addWidget(nameLineEdit);

        hourlyRateLabel = new QLabel(verticalLayoutWidget_3);
        hourlyRateLabel->setObjectName("hourlyRateLabel");

        verticalLayout_2->addWidget(hourlyRateLabel);

        hourlyRateDoubleSpinBox = new QDoubleSpinBox(verticalLayoutWidget_3);
        hourlyRateDoubleSpinBox->setObjectName("hourlyRateDoubleSpinBox");

        verticalLayout_2->addWidget(hourlyRateDoubleSpinBox);


        retranslateUi(AddEmployeeDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddEmployeeDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddEmployeeDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddEmployeeDialog);
    } // setupUi

    void retranslateUi(QDialog *AddEmployeeDialog)
    {
        AddEmployeeDialog->setWindowTitle(QCoreApplication::translate("AddEmployeeDialog", "Dialog", nullptr));
        nameLabel->setText(QCoreApplication::translate("AddEmployeeDialog", "Name:", nullptr));
        hourlyRateLabel->setText(QCoreApplication::translate("AddEmployeeDialog", "Hourly Rate:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddEmployeeDialog: public Ui_AddEmployeeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_EMPLOYEE_DIALOG_H
