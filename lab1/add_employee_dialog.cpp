// add_employee_dialog.cpp
#include "add_employee_dialog.h"
#include "ui_add_employee_dialog.h"
#include "database_manager.h"

AddEmployeeDialog::AddEmployeeDialog(DatabaseManager *dbManager, const QString &name, double hourlyRate, QWidget *parent)
    : QDialog(parent), ui(new Ui::AddEmployeeDialog), dbManager(dbManager)
{
    ui->setupUi(this);
    setWindowTitle("Car Workshop Management System");

    // Setting initial values to line edits if provided
    if (!name.isEmpty())
    {
        ui->nameLineEdit->setText(name);
    }
    if (hourlyRate != 0.0)
    {
        ui->hourlyRateDoubleSpinBox->setValue(hourlyRate);
    }
}

AddEmployeeDialog::~AddEmployeeDialog()
{
    delete ui;
}

void AddEmployeeDialog::on_buttonBox_accepted()
{
    QString name = ui->nameLineEdit->text();
    double hourlyRate = ui->hourlyRateDoubleSpinBox->value();

    emit addEmployee(name, hourlyRate);

    close();
}

void AddEmployeeDialog::on_buttonBox_rejected()
{
    close();
}
