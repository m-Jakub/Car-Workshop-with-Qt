#include "calendar.h"
#include "ui_calendar.h"
#include "database_manager.h"
#include <QSqlQuery>
#include <QSqlError>

Calendar::Calendar(DatabaseManager *dbManager, int ticketID, int employeeID, QWidget *parent)
    : QDialog(parent), ui(new Ui::Calendar), dbManager(dbManager), ticketID(ticketID), employeeID(employeeID)
{
    ui->setupUi(this);
    setupTable();
    populateTable();
    disableSelectionOfOccupiedSlots();
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
    setWindowTitle("Calendar - Car Workshop Management System");
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void Calendar::populateTable()
{
    if (employeeID != 0)
    {
        // Getting the employee's schedule
        QSqlQuery query;
        query.prepare("SELECT DayOfWeek, StartHour, EndHour FROM ScheduledRepairTimeSlots WHERE EmployeeId = :employeeId");
        query.bindValue(":employeeId", employeeID);
        if (!query.exec())
        {
            qDebug() << "Error executing query:" << query.lastError().text();
            return;
        }

        while (query.next())
        {
            int day = query.value(0).toInt();
            int startHour = query.value(1).toInt();
            int endHour = query.value(2).toInt();

            for (int row = startHour - 8; row < endHour - 8; ++row)
            {
                // Setting background color for the cell
                QTableWidgetItem *item = ui->tableWidget->item(row, day - 1);
                if (!item)
                {
                    item = new QTableWidgetItem(); // Create new QTableWidgetItem if it doesn't exist
                    ui->tableWidget->setItem(row, day - 1, item);
                }
                item->setBackground(QColor(Qt::gray));
            }
        }
    }
    if (ticketID != 0)
    {
        // Getting the ticket's schedule
        QSqlQuery query;
        query.prepare("SELECT DayOfWeek, StartHour, EndHour FROM ScheduledRepairTimeSlots WHERE TicketId = :ticketId");
        query.bindValue(":ticketId", ticketID);
        if (!query.exec())
        {
            qDebug() << "Error executing query:" << query.lastError().text();
            return;
        }

        while (query.next())
        {
            int day = query.value(0).toInt();
            int startHour = query.value(1).toInt();
            int endHour = query.value(2).toInt();

            for (int row = startHour - 8; row < endHour - 8; ++row)
            {
                // Setting background color for the cell
                QTableWidgetItem *item = ui->tableWidget->item(row, day - 1);
                if (!item)
                {
                    item = new QTableWidgetItem(); // Create new QTableWidgetItem if it doesn't exist
                    ui->tableWidget->setItem(row, day - 1, item);
                }
                item->setBackground(QColor(Qt::gray));
            }
        }
    }
}

void Calendar::addSelectedSlotsToRepairSchedule()
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
                {
                    startHour = row + 8;
                }
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
        if (startHour != 0)
        {
            endHour = ui->tableWidget->rowCount() + 8; // Last hour of the day
            emit addRepairSchedule(QString::number(startHour), QString::number(endHour), QString::number(day));
        }
    }
}

void Calendar::disableSelectionOfOccupiedSlots()
{
    for (int column = 0; column < ui->tableWidget->columnCount(); ++column)
    {
        for (int row = 0; row < ui->tableWidget->rowCount(); ++row)
        {
            QTableWidgetItem *item = ui->tableWidget->item(row, column);
            if (item && item->background().color() != Qt::white)
            {
                ui->tableWidget->item(row, column)->setFlags(ui->tableWidget->item(row, column)->flags() & ~Qt::ItemIsSelectable);
            }
        }
    }
}

void Calendar::on_buttonBox_accepted()
{
    addSelectedSlotsToRepairSchedule();
}
