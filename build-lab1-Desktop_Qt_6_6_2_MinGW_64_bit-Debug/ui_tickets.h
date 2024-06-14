/********************************************************************************
** Form generated from reading UI file 'tickets.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICKETS_H
#define UI_TICKETS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tickets
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *calendarButton;
    QPushButton *assignEmployeeButton;
    QPushButton *estimateButton;
    QPushButton *updateButton;
    QPushButton *partsButton;
    QPushButton *finalButton;
    QPushButton *deleteButton;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QComboBox *stateComboBox;
    QLabel *label_3;
    QDoubleSpinBox *priceDoubleSpinBox;
    QPushButton *addButton;
    QLabel *label;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Tickets)
    {
        if (Tickets->objectName().isEmpty())
            Tickets->setObjectName("Tickets");
        Tickets->resize(986, 456);
        verticalLayoutWidget = new QWidget(Tickets);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(800, 60, 171, 321));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        calendarButton = new QPushButton(verticalLayoutWidget);
        calendarButton->setObjectName("calendarButton");

        verticalLayout->addWidget(calendarButton);

        assignEmployeeButton = new QPushButton(verticalLayoutWidget);
        assignEmployeeButton->setObjectName("assignEmployeeButton");

        verticalLayout->addWidget(assignEmployeeButton);

        estimateButton = new QPushButton(verticalLayoutWidget);
        estimateButton->setObjectName("estimateButton");

        verticalLayout->addWidget(estimateButton);

        updateButton = new QPushButton(verticalLayoutWidget);
        updateButton->setObjectName("updateButton");

        verticalLayout->addWidget(updateButton);

        partsButton = new QPushButton(verticalLayoutWidget);
        partsButton->setObjectName("partsButton");

        verticalLayout->addWidget(partsButton);

        finalButton = new QPushButton(verticalLayoutWidget);
        finalButton->setObjectName("finalButton");

        verticalLayout->addWidget(finalButton);

        deleteButton = new QPushButton(verticalLayoutWidget);
        deleteButton->setObjectName("deleteButton");

        verticalLayout->addWidget(deleteButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        stateComboBox = new QComboBox(verticalLayoutWidget);
        stateComboBox->setObjectName("stateComboBox");

        verticalLayout->addWidget(stateComboBox);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        priceDoubleSpinBox = new QDoubleSpinBox(verticalLayoutWidget);
        priceDoubleSpinBox->setObjectName("priceDoubleSpinBox");
        priceDoubleSpinBox->setMaximum(99999.990000000005239);

        verticalLayout->addWidget(priceDoubleSpinBox);

        addButton = new QPushButton(Tickets);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(30, 400, 121, 24));
        label = new QLabel(Tickets);
        label->setObjectName("label");
        label->setGeometry(QRect(800, 40, 81, 16));
        tableWidget = new QTableWidget(Tickets);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(30, 40, 741, 341));
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(7);

        retranslateUi(Tickets);

        QMetaObject::connectSlotsByName(Tickets);
    } // setupUi

    void retranslateUi(QWidget *Tickets)
    {
        Tickets->setWindowTitle(QCoreApplication::translate("Tickets", "Form", nullptr));
        calendarButton->setText(QCoreApplication::translate("Tickets", "Show Calendar", nullptr));
        assignEmployeeButton->setText(QCoreApplication::translate("Tickets", "Assign Another Employee", nullptr));
        estimateButton->setText(QCoreApplication::translate("Tickets", "Estimate", nullptr));
        updateButton->setText(QCoreApplication::translate("Tickets", "Update", nullptr));
        partsButton->setText(QCoreApplication::translate("Tickets", "Parts Used", nullptr));
        finalButton->setText(QCoreApplication::translate("Tickets", "Save Final Costs to PDF", nullptr));
        deleteButton->setText(QCoreApplication::translate("Tickets", "Delete", nullptr));
        label_2->setText(QCoreApplication::translate("Tickets", "Change state:", nullptr));
        label_3->setText(QCoreApplication::translate("Tickets", "Price Paid by the Client:", nullptr));
        addButton->setText(QCoreApplication::translate("Tickets", "Add New Ticket", nullptr));
        label->setText(QCoreApplication::translate("Tickets", "Operations:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tickets: public Ui_Tickets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICKETS_H
