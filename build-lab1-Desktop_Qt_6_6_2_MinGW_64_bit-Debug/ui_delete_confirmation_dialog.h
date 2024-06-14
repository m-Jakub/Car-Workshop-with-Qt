/********************************************************************************
** Form generated from reading UI file 'delete_confirmation_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETE_CONFIRMATION_DIALOG_H
#define UI_DELETE_CONFIRMATION_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DeleteConfirmationDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *messageLabel;

    void setupUi(QDialog *DeleteConfirmationDialog)
    {
        if (DeleteConfirmationDialog->objectName().isEmpty())
            DeleteConfirmationDialog->setObjectName("DeleteConfirmationDialog");
        DeleteConfirmationDialog->resize(418, 92);
        buttonBox = new QDialogButtonBox(DeleteConfirmationDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(190, 50, 211, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        messageLabel = new QLabel(DeleteConfirmationDialog);
        messageLabel->setObjectName("messageLabel");
        messageLabel->setGeometry(QRect(20, 20, 371, 20));

        retranslateUi(DeleteConfirmationDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DeleteConfirmationDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DeleteConfirmationDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DeleteConfirmationDialog);
    } // setupUi

    void retranslateUi(QDialog *DeleteConfirmationDialog)
    {
        DeleteConfirmationDialog->setWindowTitle(QCoreApplication::translate("DeleteConfirmationDialog", "Dialog", nullptr));
        messageLabel->setText(QCoreApplication::translate("DeleteConfirmationDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteConfirmationDialog: public Ui_DeleteConfirmationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETE_CONFIRMATION_DIALOG_H
