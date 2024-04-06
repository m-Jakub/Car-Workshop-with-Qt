// add_employee_dialog.cpp
#include "add_employee_dialog.h"
#include "ui_add_employee_dialog.h"
#include "database_manager.h"

AddEmployeeDialog::AddEmployeeDialog(DatabaseManager *dbManager, QWidget *parent)
    : QDialog(parent), ui(new Ui::AddEmployeeDialog), dbManager(dbManager)
{
    ui->setupUi(this);
    setWindowTitle("Adding Employee");
}

AddEmployeeDialog::~AddEmployeeDialog()
{
    delete ui;
}
// void Employees::on_Add_clicked()
// {
//     // Instantiating the AddEmployeeDialog
//     addEmployeeWindow = new AddEmployeeDialog(dbManager);

//     // Connecting the addEmployee signal to a slot that adds the employee to the table
//     connect(addEmployeeWindow, &AddEmployeeDialog::addEmployee, this, [=](const QString &name, double hourlyRate)
//             {
//         // Inserting the employee into the database
//         int id = dbManager->addEmployee(name, hourlyRate);

//         // Inserting the employee into the tableWidget
//         int row = ui->tableWidget->rowCount();
//         ui->tableWidget->insertRow(row);
//         ui->tableWidget->setItem(row, 0, new QTableWidgetItem(name));
//         ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(hourlyRate)));

//         // Storing the ID in the rowToIdMap
//         rowToIdMap[row] = id; });

//     // Displaying the addEmployeeWindow
//     addEmployeeWindow->exec();
// }

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
