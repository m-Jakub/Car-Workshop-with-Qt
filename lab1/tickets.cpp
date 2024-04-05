#include "tickets.h"
#include "ui_tickets.h"

Tickets::Tickets(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tickets)
{
    ui->setupUi(this);
}

Tickets::~Tickets()
{
    delete ui;
}
