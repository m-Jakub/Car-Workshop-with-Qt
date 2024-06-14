/********************************************************************************
** Form generated from reading UI file 'estimate.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESTIMATE_H
#define UI_ESTIMATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Estimate
{
public:
    QTextEdit *description;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QDoubleSpinBox *expectedCost;
    QLabel *label_3;
    QComboBox *acceptedByClient;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Estimate)
    {
        if (Estimate->objectName().isEmpty())
            Estimate->setObjectName("Estimate");
        Estimate->resize(525, 291);
        description = new QTextEdit(Estimate);
        description->setObjectName("description");
        description->setGeometry(QRect(40, 40, 311, 221));
        label = new QLabel(Estimate);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 20, 211, 16));
        verticalLayoutWidget = new QWidget(Estimate);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(370, 10, 128, 241));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        expectedCost = new QDoubleSpinBox(verticalLayoutWidget);
        expectedCost->setObjectName("expectedCost");

        verticalLayout->addWidget(expectedCost);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        acceptedByClient = new QComboBox(verticalLayoutWidget);
        acceptedByClient->addItem(QString());
        acceptedByClient->addItem(QString());
        acceptedByClient->setObjectName("acceptedByClient");

        verticalLayout->addWidget(acceptedByClient);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        buttonBox = new QDialogButtonBox(verticalLayoutWidget);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Estimate);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Estimate, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Estimate, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Estimate);
    } // setupUi

    void retranslateUi(QDialog *Estimate)
    {
        Estimate->setWindowTitle(QCoreApplication::translate("Estimate", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Estimate", "Description:", nullptr));
        label_4->setText(QCoreApplication::translate("Estimate", "Expected cost of service", nullptr));
        label_3->setText(QCoreApplication::translate("Estimate", "Accepted by the client?", nullptr));
        acceptedByClient->setItemText(0, QCoreApplication::translate("Estimate", "No", nullptr));
        acceptedByClient->setItemText(1, QCoreApplication::translate("Estimate", "Yes", nullptr));

        pushButton->setText(QCoreApplication::translate("Estimate", "Save as PDF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Estimate: public Ui_Estimate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESTIMATE_H
