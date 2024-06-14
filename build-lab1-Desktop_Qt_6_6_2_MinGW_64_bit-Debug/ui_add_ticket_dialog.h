/********************************************************************************
** Form generated from reading UI file 'add_ticket_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_TICKET_DIALOG_H
#define UI_ADD_TICKET_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddTicketDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *Label_4;
    QLineEdit *brandLineEdit;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_7;
    QLabel *Label;
    QLineEdit *modelLineEdit;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_6;
    QLabel *Label_2;
    QLineEdit *registrationLineEdit;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QLabel *Label_3;
    QLineEdit *problemLineEdit;
    QLabel *Label_5;
    QTableWidget *tableWidget;

    void setupUi(QDialog *AddTicketDialog)
    {
        if (AddTicketDialog->objectName().isEmpty())
            AddTicketDialog->setObjectName("AddTicketDialog");
        AddTicketDialog->resize(746, 354);
        buttonBox = new QDialogButtonBox(AddTicketDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(630, 90, 81, 121));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget_3 = new QWidget(AddTicketDialog);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(20, 40, 160, 240));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Label_4 = new QLabel(verticalLayoutWidget_3);
        Label_4->setObjectName("Label_4");

        verticalLayout_2->addWidget(Label_4);

        brandLineEdit = new QLineEdit(verticalLayoutWidget_3);
        brandLineEdit->setObjectName("brandLineEdit");

        verticalLayout_2->addWidget(brandLineEdit);

        verticalSpacer_2 = new QSpacerItem(20, 58, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        verticalSpacer_7 = new QSpacerItem(20, 58, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_7);

        Label = new QLabel(verticalLayoutWidget_3);
        Label->setObjectName("Label");

        verticalLayout_2->addWidget(Label);

        modelLineEdit = new QLineEdit(verticalLayoutWidget_3);
        modelLineEdit->setObjectName("modelLineEdit");

        verticalLayout_2->addWidget(modelLineEdit);

        verticalSpacer_3 = new QSpacerItem(20, 58, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        verticalSpacer_6 = new QSpacerItem(20, 58, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_6);

        Label_2 = new QLabel(verticalLayoutWidget_3);
        Label_2->setObjectName("Label_2");

        verticalLayout_2->addWidget(Label_2);

        registrationLineEdit = new QLineEdit(verticalLayoutWidget_3);
        registrationLineEdit->setObjectName("registrationLineEdit");

        verticalLayout_2->addWidget(registrationLineEdit);

        verticalSpacer_4 = new QSpacerItem(20, 58, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        verticalSpacer_5 = new QSpacerItem(20, 58, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        Label_3 = new QLabel(verticalLayoutWidget_3);
        Label_3->setObjectName("Label_3");

        verticalLayout_2->addWidget(Label_3);

        problemLineEdit = new QLineEdit(verticalLayoutWidget_3);
        problemLineEdit->setObjectName("problemLineEdit");

        verticalLayout_2->addWidget(problemLineEdit);

        Label_5 = new QLabel(AddTicketDialog);
        Label_5->setObjectName("Label_5");
        Label_5->setGeometry(QRect(220, 30, 158, 16));
        tableWidget = new QTableWidget(AddTicketDialog);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(220, 60, 381, 241));
        tableWidget->setColumnCount(2);

        retranslateUi(AddTicketDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddTicketDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddTicketDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddTicketDialog);
    } // setupUi

    void retranslateUi(QDialog *AddTicketDialog)
    {
        AddTicketDialog->setWindowTitle(QCoreApplication::translate("AddTicketDialog", "Dialog", nullptr));
        Label_4->setText(QCoreApplication::translate("AddTicketDialog", "Brand Name", nullptr));
        Label->setText(QCoreApplication::translate("AddTicketDialog", "Model Item", nullptr));
        Label_2->setText(QCoreApplication::translate("AddTicketDialog", "Registration ID", nullptr));
        Label_3->setText(QCoreApplication::translate("AddTicketDialog", "Problem Description", nullptr));
        Label_5->setText(QCoreApplication::translate("AddTicketDialog", "Assign Employee:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddTicketDialog: public Ui_AddTicketDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_TICKET_DIALOG_H
