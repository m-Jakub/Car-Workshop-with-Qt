#include "employees.h"
#include "ui_employees.h"
#include "database_manager.h"
#include <QSqlQuery>

Employees::Employees(QWidget *parent)
    : QWidget(parent), ui(new Ui::Employees)
{
    ui->setupUi(this);

    // Setting up the table
    setupTable();

    QSqlQuery query("SELECT Name, HourlyRate FROM Employees");
    while (query.next())
    {
        QTableWidgetItem *nameItem = new QTableWidgetItem(query.value(0).toString());
        QTableWidgetItem *rateItem = new QTableWidgetItem(query.value(1).toString());

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, nameItem);
        ui->tableWidget->setItem(row, 1, rateItem);
    }
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

Employees::~Employees()
{
    delete ui;
}

void Employees::on_Delete_clicked()
{
    // // Getting the selected row
    // // Declare and initialize the dbManager object

    // int selectedRow = ui->tableWidget->currentRow();

    // // Checking if a row is selected
    // if (selectedRow >= 0)
    // {
    //     // Getting the name of the employee in the selected row
    //     QTableWidgetItem* nameItem = ui->tableWidget->item(selectedRow, 0);
    //     QString employeeName = nameItem->text();

    //     // Removing the employee from the database


    //     // Removing the selected row from the tableWidget
    //     ui->tableWidget->removeRow(selectedRow);
    // }
}

