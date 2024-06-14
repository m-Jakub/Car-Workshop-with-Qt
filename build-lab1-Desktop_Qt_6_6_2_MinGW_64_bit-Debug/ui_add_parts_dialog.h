/********************************************************************************
** Form generated from reading UI file 'add_parts_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_PARTS_DIALOG_H
#define UI_ADD_PARTS_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddPartsDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *Label_4;
    QLineEdit *descriptionLineEdit;
    QSpacerItem *verticalSpacer_2;
    QLabel *Label;
    QSpinBox *amountSpinBox;
    QSpacerItem *verticalSpacer_3;
    QLabel *Label_2;
    QDoubleSpinBox *priceDoubleSpinBox;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QDialog *AddPartsDialog)
    {
        if (AddPartsDialog->objectName().isEmpty())
            AddPartsDialog->setObjectName("AddPartsDialog");
        AddPartsDialog->resize(360, 226);
        buttonBox = new QDialogButtonBox(AddPartsDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(250, 90, 81, 121));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget_3 = new QWidget(AddPartsDialog);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(50, 30, 160, 181));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Label_4 = new QLabel(verticalLayoutWidget_3);
        Label_4->setObjectName("Label_4");

        verticalLayout_2->addWidget(Label_4);

        descriptionLineEdit = new QLineEdit(verticalLayoutWidget_3);
        descriptionLineEdit->setObjectName("descriptionLineEdit");

        verticalLayout_2->addWidget(descriptionLineEdit);

        verticalSpacer_2 = new QSpacerItem(20, 58, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        Label = new QLabel(verticalLayoutWidget_3);
        Label->setObjectName("Label");

        verticalLayout_2->addWidget(Label);

        amountSpinBox = new QSpinBox(verticalLayoutWidget_3);
        amountSpinBox->setObjectName("amountSpinBox");

        verticalLayout_2->addWidget(amountSpinBox);

        verticalSpacer_3 = new QSpacerItem(20, 58, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        Label_2 = new QLabel(verticalLayoutWidget_3);
        Label_2->setObjectName("Label_2");

        verticalLayout_2->addWidget(Label_2);

        priceDoubleSpinBox = new QDoubleSpinBox(verticalLayoutWidget_3);
        priceDoubleSpinBox->setObjectName("priceDoubleSpinBox");

        verticalLayout_2->addWidget(priceDoubleSpinBox);

        verticalSpacer_6 = new QSpacerItem(20, 58, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_6);


        retranslateUi(AddPartsDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddPartsDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddPartsDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddPartsDialog);
    } // setupUi

    void retranslateUi(QDialog *AddPartsDialog)
    {
        AddPartsDialog->setWindowTitle(QCoreApplication::translate("AddPartsDialog", "Dialog", nullptr));
        Label_4->setText(QCoreApplication::translate("AddPartsDialog", "Name/Description", nullptr));
        Label->setText(QCoreApplication::translate("AddPartsDialog", "Amount", nullptr));
        Label_2->setText(QCoreApplication::translate("AddPartsDialog", "Unit price [$]", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPartsDialog: public Ui_AddPartsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_PARTS_DIALOG_H
