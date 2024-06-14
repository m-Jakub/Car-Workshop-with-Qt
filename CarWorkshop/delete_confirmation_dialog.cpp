// deleteconfirmationdialog.cpp
#include "delete_confirmation_dialog.h"
#include "ui_delete_confirmation_dialog.h"

DeleteConfirmationDialog::DeleteConfirmationDialog(const QString &itemName, QWidget *parent) : QDialog(parent),
                                                                                               ui(new Ui::DeleteConfirmationDialog)
{
    ui->setupUi(this);
    ui->messageLabel->setText(tr("Are you sure you want to delete %1?").arg(itemName));
}

DeleteConfirmationDialog::~DeleteConfirmationDialog()
{
    delete ui;
}

void DeleteConfirmationDialog::on_buttonBox_accepted()
{
    emit deleteConfirmed();
    close();
}


void DeleteConfirmationDialog::on_buttonBox_rejected()
{
    close();
}

