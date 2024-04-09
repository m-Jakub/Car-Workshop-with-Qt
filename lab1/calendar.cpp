#include "calendar.h"
#include "ui_calendar.h"

Calendar::Calendar(DatabaseManager *dbManager, QWidget *parent)
    : QDialog(parent), ui(new Ui::Calendar), dbManager(dbManager)
{
    ui->setupUi(this);
    setupTable();
}

Calendar::~Calendar()
{
    delete ui;
}

void Calendar::setupTable()
{
    // Setting the selection mode and behavior for the table widget
    ui->tableWidget->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
}

void Calendar::on_buttonBox_accepted()
{
    // TO DO: emit signal to update the calendar
    close();
}

void Calendar::on_buttonBox_rejected()
{
    close();
}

void Calendar::on_tableWidget_cellActivated(int row, int column)
{
    qDebug() << "Cell activated";
}
