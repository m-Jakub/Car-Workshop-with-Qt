#include "add_ticket_dialog.h"
#include "ui_add_ticket_dialog.h"
#include "database_manager.h"
#include "calendar.h"
#include <QSqlQuery>

AddTicketDialog::AddTicketDialog(DatabaseManager *dbManager, const QString &brand, const QString &model, const QString &registrationID, const QString &problemDescription, int assignedEmployeeID, bool choose_employee_only, int ticketID, QWidget *parent)
    : QDialog(parent), ui(new Ui::AddTicketDialog), dbManager(dbManager), choose_employee_only(choose_employee_only), ticketID(ticketID)
{
    ui->setupUi(this);

    setupTable();
    populateTable();
    setWindowTitle("Car Workshop Management System");

    disableFields(choose_employee_only); // Disabling fields if choose_employee_only is true

    // Setting initial values to line edits if provided
    if (initialized = assignedEmployeeID != 0)
        fillFields(brand, model, registrationID, problemDescription, assignedEmployeeID);
}

AddTicketDialog::~AddTicketDialog()
{
    delete ui;
}

void AddTicketDialog::disableFields(bool disable)
{
    ui->brandLineEdit->setDisabled(disable);
    ui->modelLineEdit->setDisabled(disable);
    ui->registrationLineEdit->setDisabled(disable);
    ui->problemLineEdit->setDisabled(disable);
}

void AddTicketDialog::fillFields(const QString &brand, const QString &model, const QString &registrationID, const QString &problemDescription, int assignedEmployeeID)
{
    if (!brand.isEmpty())
    {
        ui->brandLineEdit->setText(brand);
    }
    if (!model.isEmpty())
    {
        ui->modelLineEdit->setText(model);
    }
    if (!registrationID.isEmpty())
    {
        ui->registrationLineEdit->setText(registrationID);
    }
    if (!problemDescription.isEmpty())
    {
        ui->problemLineEdit->setText(problemDescription);
    }
    if (assignedEmployeeID != 0)
    {
        QSqlQuery query;
        query.prepare("SELECT Name FROM Employees WHERE EmployeeId = :id");
        query.bindValue(":id", assignedEmployeeID);
        query.exec();
        query.next();
        QString employeeName = query.value(0).toString();

        for (int i = 0; i < ui->tableWidget->rowCount(); i++)
        {
            if (ui->tableWidget->item(i, 0)->text() == employeeName)
            {
                ui->tableWidget->selectRow(i);
                break;
            }
        }
    }
}

void AddTicketDialog::setupTable()
{
    // Setting column names
    QStringList headerLabels;
    headerLabels << "Name"
                 << "Hourly Rate [$]";
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);

    // Resizing columns
    ui->tableWidget->setColumnWidth(0, 200);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    // Setting selection behavior to select the whole row
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Setting the window title
    setWindowTitle("Employees - Car Workshop Management System");

    // Making the table read-only
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void AddTicketDialog::populateTable()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    QSqlQuery query("SELECT EmployeeId, Name, HourlyRate FROM Employees");
    while (query.next())
    {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        QString hourlyRate = query.value(2).toString();

        QTableWidgetItem *nameItem = new QTableWidgetItem(name);
        QTableWidgetItem *rateItem = new QTableWidgetItem(hourlyRate);

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, nameItem);
        ui->tableWidget->setItem(row, 1, rateItem);

        // Storing the ID in the rowToIdMap
        rowToIdMap[row] = id;
    }
}

void AddTicketDialog::on_buttonBox_accepted()
{
    QString brand = ui->brandLineEdit->text();
    QString model = ui->modelLineEdit->text();
    QString registrationID = ui->registrationLineEdit->text();
    QString problemDescription = ui->problemLineEdit->text();

    int row = ui->tableWidget->currentRow();
    int assignedEmployeeID = rowToIdMap[row];

    if (!initialized)
    {

        calendar = new Calendar(dbManager, 0, 0);
        connect(calendar, &Calendar::addRepairSchedule, this, [=](const QString &startHour, const QString &endHour, const QString &day)
                { emit addTicket(brand, model, registrationID, problemDescription, assignedEmployeeID, startHour, endHour, day); });
        calendar->exec();
    }
    if (choose_employee_only)
    {
        calendar = new Calendar(dbManager, ticketID, 0); //////////////////////////// TO DO
        connect(calendar, &Calendar::addRepairSchedule, this, [=](const QString &startHour, const QString &endHour, const QString &day)
                { emit addTicket(brand, model, registrationID, problemDescription, assignedEmployeeID, startHour, endHour, day); });
        calendar->exec();
    }
    else
        emit addTicket(brand, model, registrationID, problemDescription, assignedEmployeeID, "", "", "");

    close();
}

void AddTicketDialog::on_buttonBox_rejected()
{
    close();
}
