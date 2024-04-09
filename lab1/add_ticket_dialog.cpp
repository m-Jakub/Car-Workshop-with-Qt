#include "add_ticket_dialog.h"
#include "ui_add_ticket_dialog.h"
#include "database_manager.h"

AddTicketDialog::AddTicketDialog(DatabaseManager *dbManager, const QString &brand, const QString &model, const QString &registrationID, const QString &assignedEmployee, QWidget *parent)
    : QDialog(parent), ui(new Ui::AddTicketDialog), dbManager(dbManager)
{
    ui->setupUi(this);
    setWindowTitle("Car Workshop Management System");

    // Setting initial values to line edits if provided
    if (!brand.isEmpty())
    {
        ui->brandLineEdit->setText(brand);
    }
    if (!model.isEmpty())
    {
        ui->modelLineEdit->setText(model);
    }
    if (!registrationID.isEmpty())
    {
        ui->registrationLineEdit->setText(registrationID);
    }
    if (!assignedEmployee.isEmpty())
    {
        ui->problemLineEdit->setText(assignedEmployee);
    }
}

AddTicketDialog::~AddTicketDialog()
{
    delete ui;
}

void AddTicketDialog::on_buttonBox_accepted()
{
    QString brand = ui->brandLineEdit->text();
    QString model = ui->modelLineEdit->text();
    QString registrationID = ui->registrationLineEdit->text();
    // QString problemDescription = ui->problemDescriptionTextEdit->toPlainText();
    QString problemDescription = ui->problemLineEdit->text();
    // double pricePaidByClient = ui->pricePaidDoubleSpinBox->value();
    // QString state = ui->stateComboBox->currentText();

    emit addTicket(brand, model, registrationID, problemDescription);

    close();
}

void AddTicketDialog::on_buttonBox_rejected()
{
    close();
}
