#include "addemployee.h"
#include "ui_addemployee.h"
#include "database_manager.h"

AddEmployee::AddEmployee(DatabaseManager *dbManager, QWidget *parent)
    : QWidget(parent), ui(new Ui::AddEmployee), dbManager(dbManager)
{
    ui->setupUi(this);
    setWindowTitle("Adding Employee");
}

AddEmployee::~AddEmployee()
{
    delete ui;
}

void AddEmployee::on_cancelButton_clicked()
{
    close();
}

