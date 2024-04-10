#include "calendar.h"
#include "ui_calendar.h"

Calendar::Calendar(DatabaseManager *dbManager, int ticketID, int employeeID, QWidget *parent)
    : QDialog(parent), ui(new Ui::Calendar), dbManager(dbManager), ticketID(ticketID), employeeID(employeeID)
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
    QModelIndexList selectedIndexes = ui->tableWidget->selectionModel()->selectedIndexes();

    int day = 0;
    int startHour = 0;
    int endHour = 0;

    for (int column = 0; column < ui->tableWidget->columnCount(); ++column)
    {
        day = column + 1;
        startHour = 0;
        endHour = 0;
        for (int row = 0; row < ui->tableWidget->rowCount(); ++row)
        {
            QModelIndex index = ui->tableWidget->model()->index(row, column);
            if (selectedIndexes.contains(index))
            {
                if (startHour == 0)
                    startHour = row + 8;
            }
            else
            {
                if (startHour != 0)
                {
                    endHour = row + 8;
                    emit addRepairSchedule(QString::number(startHour), QString::number(endHour), QString::number(day));
                    startHour = 0;
                }
            }
        }
        close();
    }
}

void Calendar::on_buttonBox_rejected()
{
    close();
}

void Calendar::on_tableWidget_cellActivated(int row, int column)
{
    qDebug() << "Cell activated";
}
