// add_employee_dialog.cpp
#include "add_employee_dialog.h"
#include "ui_add_employee_dialog.h"
#include "database_manager.h"

AddEmployeeDialog::AddEmployeeDialog(DatabaseManager *dbManager, const QString &name, double hourlyRate, QWidget *parent)
    : QDialog(parent), ui(new Ui::AddEmployeeDialog), dbManager(dbManager)
{
    ui->setupUi(this);
    setWindowTitle("Car Workshop Management System");
    fillFields(name, hourlyRate);
}

AddEmployeeDialog::~AddEmployeeDialog()
{
    delete ui;
}

void AddEmployeeDialog::fillFields(const QString &name, double hourlyRate)
{
    ui->nameLineEdit->setText(name);
    ui->hourlyRateDoubleSpinBox->setValue(hourlyRate);
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
