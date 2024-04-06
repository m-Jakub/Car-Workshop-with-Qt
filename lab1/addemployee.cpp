#include "addemployee.h"
#include "ui_addemployee.h"
#include "database_manager.h"
#include <QKeyEvent>

AddEmployee::AddEmployee(DatabaseManager *dbManager, QWidget *parent)
    : QWidget(parent), ui(new Ui::AddEmployee), dbManager(dbManager)
{
    ui->setupUi(this);
    setWindowTitle("Adding Employee");

    // Installing event filters on line edit widgets
    // ui->hourlyRateLineEdit->installEventFilter(this);
}

AddEmployee::~AddEmployee()
{
    delete ui;
}

void AddEmployee::on_cancelButton_clicked()
{
    close();
}
