/********************************************************************************
** Form generated from reading UI file 'parts.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARTS_H
#define UI_PARTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Parts
{
public:
    QLabel *label;
    QTableWidget *tableWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *updateButton;
    QPushButton *deleteButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QDialogButtonBox *buttonBox;
    QPushButton *addButton;

    void setupUi(QDialog *Parts)
    {
        if (Parts->objectName().isEmpty())
            Parts->setObjectName("Parts");
        Parts->resize(683, 354);
        label = new QLabel(Parts);
        label->setObjectName("label");
        label->setGeometry(QRect(520, 70, 81, 16));
        tableWidget = new QTableWidget(Parts);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(30, 30, 461, 271));
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(4);
        verticalLayoutWidget = new QWidget(Parts);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(520, 100, 131, 171));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        updateButton = new QPushButton(verticalLayoutWidget);
        updateButton->setObjectName("updateButton");

        verticalLayout->addWidget(updateButton);

        deleteButton = new QPushButton(verticalLayoutWidget);
        deleteButton->setObjectName("deleteButton");

        verticalLayout->addWidget(deleteButton);

        verticalSpacer = new QSpacerItem(68, 28, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        buttonBox = new QDialogButtonBox(verticalLayoutWidget);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout);

        addButton = new QPushButton(Parts);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(30, 310, 121, 24));

        retranslateUi(Parts);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Parts, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Parts, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Parts);
    } // setupUi

    void retranslateUi(QDialog *Parts)
    {
        Parts->setWindowTitle(QCoreApplication::translate("Parts", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Parts", "Operations:", nullptr));
        updateButton->setText(QCoreApplication::translate("Parts", "Update", nullptr));
        deleteButton->setText(QCoreApplication::translate("Parts", "Delete", nullptr));
        addButton->setText(QCoreApplication::translate("Parts", "Add New Parts", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Parts: public Ui_Parts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARTS_H
