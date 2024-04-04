#include "employees.h"
#include "ui_employees.h"

Employees::Employees(QWidget *parent)
    : QDockWidget(parent)
    , ui(new Ui::Employees)
{
    ui->setupUi(this);
    setWindowTitle("Employees");
}

Employees::~Employees()
{
    delete ui;
}
