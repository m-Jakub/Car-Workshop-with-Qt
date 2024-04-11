#include "worklog.h"
#include "ui_worklog.h"

Worklog::Worklog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Worklog)
{
    ui->setupUi(this);
}

Worklog::~Worklog()
{
    delete ui;
}
