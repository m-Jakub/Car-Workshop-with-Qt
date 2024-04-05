#include "employees.h"
#include "ui_employees.h"
#include "database_manager.h"
#include <QSqlQuery>

Employees::Employees(DatabaseManager *dbManager, QWidget *parent)
    : QWidget(parent), ui(new Ui::Employees), dbManager(dbManager)
{
    ui->setupUi(this);

    // Setting up the table
    setupTable();
    populateTable();
    // QSqlQuery query("SELECT Name, HourlyRate FROM Employees");
    // while (query.next())
    // {
    //     QTableWidgetItem *nameItem = new QTableWidgetItem(query.value(0).toString());
    //     QTableWidgetItem *rateItem = new QTableWidgetItem(query.value(1).toString());

    //     int row = ui->tableWidget->rowCount();
    //     ui->tableWidget->insertRow(row);
    //     ui->tableWidget->setItem(row, 0, nameItem);
    //     ui->tableWidget->setItem(row, 1, rateItem);
    // }
}

void Employees::setupTable()
{
    // Setting column names
    QStringList headerLabels;
    headerLabels << "Name"
                 << "Hourly Rate [$]";
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);

    // Resizing columns
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    // Setting selection behavior to select the whole row
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Setting the window title
    setWindowTitle("Employees");
}

void Employees::populateTable()
{
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

Employees::~Employees()
{
    delete ui;
}

void Employees::on_Delete_clicked()
{
    int selectedRow = ui->tableWidget->currentRow();

    if (selectedRow >= 0)
    {
        // Retrieving the ID using the row index
        int employeeId = rowToIdMap.value(selectedRow);

        // Removing the employee from the database using the DatabaseManager object
        dbManager->removeEmployee(employeeId);

        ui->tableWidget->removeRow(selectedRow);

        // Removing the ID from the rowToIdMap
        rowToIdMap.remove(selectedRow);
    }
}
