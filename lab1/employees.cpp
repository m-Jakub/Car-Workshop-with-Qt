#include "employees.h"
#include "ui_employees.h"
#include "database_manager.h"
#include "delete_confirmation_dialog.h"
#include <QSqlQuery>

Employees::Employees(DatabaseManager *dbManager, QWidget *parent)
    : QWidget(parent), ui(new Ui::Employees), dbManager(dbManager)
{
    ui->setupUi(this);

    setupTable();
    populateTable();
    populateTable();
}

Employees::~Employees()
{
    delete ui;
}

void Employees::setupTable()
{
    // Setting column names
    QStringList headerLabels;
    headerLabels << "Name"
                 << "Hourly Rate [$]";
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);

    // Resizing columns
    ui->tableWidget->setColumnWidth(0, 200);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    // Setting selection behavior to select the whole row
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Setting the window title
    setWindowTitle("Employees - Car Workshop Management System");

    // Making the table read-only
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void Employees::populateTable()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    QSqlQuery query("SELECT EmployeeId, Name, HourlyRate FROM Employees");
    while (query.next())
    {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        QString hourlyRate = query.value(2).toString();

        QTableWidgetItem *nameItem = new QTableWidgetItem(name);
        QTableWidgetItem *rateItem = new QTableWidgetItem(hourlyRate);

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, nameItem);
        ui->tableWidget->setItem(row, 1, rateItem);

        // Storing the ID in the rowToIdMap
        rowToIdMap[row] = id;
    }
}

void Employees::on_deleteButton_clicked()
{
    int selectedRow = ui->tableWidget->currentRow();

    if (selectedRow >= 0)
    {
        // Retrieving the name using the row index
        QString employeeName = ui->tableWidget->item(selectedRow, 0)->text();

        // Instantiating the DeleteConfirmationDialog with the employee name
        DeleteConfirmationDialog confirmationDialog(employeeName);

        // Connecting the deleteConfirmed() signal to a slot that performs deletion
        // Lambda function is executed when the deleteConfirmed signal is emitted
        connect(&confirmationDialog, &DeleteConfirmationDialog::deleteConfirmed, this, [=]()
                {
            // Retrieve the ID using the row index
            int employeeId = rowToIdMap.value(selectedRow);

            // Removing the employee from the database using the DatabaseManager object
            dbManager->removeEmployee(employeeId);

            // Removing the row from the tableWidget
            ui->tableWidget->removeRow(selectedRow);

            // Removing the ID from the rowToIdMap
            rowToIdMap.remove(selectedRow); 
            
            emit employeesUpdated();});

        // Displaying the confirmation dialog
        confirmationDialog.exec();
    }
}

void Employees::on_addButton_clicked()
{
    // Instantiating the AddEmployeeDialog
    dialogWindow = new AddEmployeeDialog(dbManager);

    // Connecting the addEmployee signal to a slot that adds the employee to the table
    connect(dialogWindow, &AddEmployeeDialog::addEmployee, this, [=](const QString &name, double hourlyRate)
            {
        // Inserting the employee into the database
        int id = dbManager->addEmployee(name, hourlyRate);

        // Inserting the employee into the tableWidget
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(name));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(hourlyRate)));

        // Storing the ID in the rowToIdMap
        rowToIdMap[row] = id; 
        
        emit employeesUpdated();});

    // Displaying the addEmployeeWindow
    dialogWindow->exec();
}

void Employees::on_updateButton_clicked()
{
    int selectedRow = ui->tableWidget->currentRow();

    // Instantiating the AddEmployeeDialog
    dialogWindow = new AddEmployeeDialog(dbManager, ui->tableWidget->item(selectedRow, 0)->text(), ui->tableWidget->item(selectedRow, 1)->text().toDouble());

    connect(dialogWindow, &AddEmployeeDialog::addEmployee, this, [=](const QString &name, double hourlyRate)
            {
         // Retrieve the ID using the row index
        int employeeId = rowToIdMap.value(selectedRow);

        // Inserting the employee into the database
        dbManager->updateEmployee(employeeId, name, hourlyRate);
        // Inserting the employee into the tableWidget
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->setItem(selectedRow, 0, new QTableWidgetItem(name));
        ui->tableWidget->setItem(selectedRow, 1, new QTableWidgetItem(QString::number(hourlyRate))); 
        
        emit employeesUpdated();});

    // Displaying the addEmployeeWindow
    dialogWindow->exec();
}

void Employees::on_calendarButton_clicked()
{
    int selectedRow = ui->tableWidget->currentRow();
    // Instantiating the CalendarDialog
    calendar = new Calendar(dbManager, 0, rowToIdMap.value(selectedRow));

    // Displaying the calendarDialog
    calendar->exec();
}
