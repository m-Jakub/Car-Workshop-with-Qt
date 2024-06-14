/********************************************************************************
** Form generated from reading UI file 'employees.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEES_H
#define UI_EMPLOYEES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Employees
{
public:
    QPushButton *addButton;
    QTableWidget *tableWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *calendarButton;
    QPushButton *updateButton;
    QPushButton *deleteButton;
    QLabel *label;

    void setupUi(QWidget *Employees)
    {
        if (Employees->objectName().isEmpty())
            Employees->setObjectName("Employees");
        Employees->resize(622, 404);
        addButton = new QPushButton(Employees);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(30, 310, 121, 24));
        tableWidget = new QTableWidget(Employees);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(30, 30, 371, 271));
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(2);
        verticalLayoutWidget = new QWidget(Employees);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(419, 80, 131, 191));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        calendarButton = new QPushButton(verticalLayoutWidget);
        calendarButton->setObjectName("calendarButton");

        verticalLayout->addWidget(calendarButton);

        updateButton = new QPushButton(verticalLayoutWidget);
        updateButton->setObjectName("updateButton");

        verticalLayout->addWidget(updateButton);

        deleteButton = new QPushButton(verticalLayoutWidget);
        deleteButton->setObjectName("deleteButton");

        verticalLayout->addWidget(deleteButton);

        label = new QLabel(Employees);
        label->setObjectName("label");
        label->setGeometry(QRect(420, 60, 81, 16));

        retranslateUi(Employees);

        QMetaObject::connectSlotsByName(Employees);
    } // setupUi

    void retranslateUi(QWidget *Employees)
    {
        Employees->setWindowTitle(QCoreApplication::translate("Employees", "Form", nullptr));
        addButton->setText(QCoreApplication::translate("Employees", "Add New Employee", nullptr));
        calendarButton->setText(QCoreApplication::translate("Employees", "Show Calendar", nullptr));
        updateButton->setText(QCoreApplication::translate("Employees", "Update", nullptr));
        deleteButton->setText(QCoreApplication::translate("Employees", "Delete", nullptr));
        label->setText(QCoreApplication::translate("Employees", "Operations:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Employees: public Ui_Employees {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEES_H
