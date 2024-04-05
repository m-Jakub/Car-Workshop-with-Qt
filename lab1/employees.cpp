#include "employees.h"
#include "ui_employees.h"
#include <QSqlQuery>

Employees::Employees(QWidget *parent)
    : QWidget(parent), ui(new Ui::Employees)
{
    ui->setupUi(this);

    QSqlQuery query("SELECT * FROM Employees");
    while (query.next())
    {
        QTableWidgetItem *nameItem = new QTableWidgetItem(query.value(1).toString());
        QTableWidgetItem *rateItem = new QTableWidgetItem(query.value(2).toString());

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, nameItem);
        ui->tableWidget->setItem(row, 1, rateItem);
    }
}

Employees::~Employees()
{
    delete ui;
}
