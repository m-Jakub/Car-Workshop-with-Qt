#include "tickets.h"
#include "ui_tickets.h"
#include "database_manager.h"
#include "delete_confirmation_dialog.h"
#include <QSqlQuery>

Tickets::Tickets(DatabaseManager *dbManager, QWidget *parent)
    : QWidget(parent), ui(new Ui::Tickets), dbManager(dbManager)
{
    ui->setupUi(this);

    setupTable();
    populateTable();
}

Tickets::~Tickets()
{
    delete ui;
}

void Tickets::setupTable()
{
    //     int addTicket(const QString& vehicleBrand, const QString& vehicleModel, const QString& registrationID, const QString& problemDescription, int assignedEmployeeID, double pricePaidByClient, const QString& state);

    // Setting column names
    QStringList headerLabels;
    headerLabels << "State"
                 << "Brand"
                 << "Model"
                 << "Registration"
                 << "Problem Description"
                 << "Assigned Employee";
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);

    // Resizing columns
    ui->tableWidget->setColumnWidth(4, 150);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    // Setting selection behavior to select the whole row
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Setting the window title
    setWindowTitle("Tickets - Car Workshop Management System");

    // Making the table read-only
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void Tickets::populateTable()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    QSqlQuery query("SELECT TicketId, VehicleBrand, VehicleModel, RegistrationID, ProblemDescription, AssignedEmployeeID, PricePaidByClient, State FROM Tickets");
    while (query.next())
    {
        int id = query.value(0).toInt();
        QString brand = query.value(1).toString();
        QString model = query.value(2).toString();
        QString registration = query.value(3).toString();
        QString problemDescription = query.value(4).toString();
        int assignedEmployeeID = query.value(5).toInt();
        QString assignedEmployeeName = dbManager->getEmployeeName(assignedEmployeeID);
        QString pricePaidByClient = query.value(6).toString();
        QString state = query.value(7).toString();

        QTableWidgetItem *brandItem = new QTableWidgetItem(brand);
        QTableWidgetItem *modelItem = new QTableWidgetItem(model);
        QTableWidgetItem *registrationItem = new QTableWidgetItem(registration);
        QTableWidgetItem *problemDescriptionItem = new QTableWidgetItem(problemDescription);
        QTableWidgetItem *assignedEmployeeItem = new QTableWidgetItem(assignedEmployeeName);
        QTableWidgetItem *pricePaidItem = new QTableWidgetItem(pricePaidByClient);
        QTableWidgetItem *stateItem = new QTableWidgetItem(state);

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, stateItem);
        ui->tableWidget->setItem(row, 1, brandItem);
        ui->tableWidget->setItem(row, 2, modelItem);
        ui->tableWidget->setItem(row, 3, registrationItem);
        ui->tableWidget->setItem(row, 4, problemDescriptionItem);
        ui->tableWidget->setItem(row, 5, assignedEmployeeItem);

        // Storing the ID in the rowToIdMap
        rowToIdMap[row] = id;
    }
}

void Tickets::on_deleteButton_clicked()
{
    int selectedRow = ui->tableWidget->currentRow();

    if (selectedRow >= 0)
    {
        QString Brand = ui->tableWidget->item(selectedRow, 1)->text();
        QString Model = ui->tableWidget->item(selectedRow, 2)->text();
        QString Registration = ui->tableWidget->item(selectedRow, 3)->text();

        DeleteConfirmationDialog confirmationDialog(Brand + " " + Model + " " + Registration);

        connect(&confirmationDialog, &DeleteConfirmationDialog::deleteConfirmed, this, [=]()
                {
            int id = rowToIdMap.value(selectedRow);
            dbManager->removeTicket(id);
            ui->tableWidget->removeRow(selectedRow);
            rowToIdMap.remove(selectedRow); 
            
            emit ticketsUpdated(); });

        confirmationDialog.exec();
    }
}

int Tickets::lastAddedTicketID = 0; // created for a proper work of the addTicket signal

void Tickets::on_addButton_clicked()
{
    dialogWindow = new AddTicketDialog(dbManager);

    connect(dialogWindow, &AddTicketDialog::addTicket, this, [=](const QString &brand, const QString &model, const QString &registration, const QString problemDescription, int assignedEmployeeID, QString startHour, QString endHour, QString day)
            {
                // Inserting the ticket into the database
                if (!dbManager->ticketExists(registration))
                {
                    lastAddedTicketID = dbManager->addTicket(brand, model, registration, problemDescription, assignedEmployeeID, 0, "created");

                    // Inserting the ticket into the tableWidget
                    int row = ui->tableWidget->rowCount();
                    ui->tableWidget->insertRow(row);
                    ui->tableWidget->setItem(row, 0, new QTableWidgetItem("created"));
                    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(brand));
                    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(model));
                    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(registration));
                    ui->tableWidget->setItem(row, 4, new QTableWidgetItem(problemDescription));
                    ui->tableWidget->setItem(row, 5, new QTableWidgetItem(dbManager->getEmployeeName(assignedEmployeeID)));
                    ui->tableWidget->setItem(row, 6, new QTableWidgetItem(QString::number(0)));

                    // Storing the ID in the rowToIdMap
                    rowToIdMap[row] = lastAddedTicketID;

                    emit ticketsUpdated(); // Emitting the signal to update the employees table
                }
                // Inserting the repair schedule into the database
                dbManager->addRepairSchedule(lastAddedTicketID, assignedEmployeeID, startHour, endHour, day);
            });

    dialogWindow->exec();
}

void Tickets::on_updateButton_clicked()
{
    int selectedRow = ui->tableWidget->currentRow();

    dialogWindow = new AddTicketDialog(dbManager, ui->tableWidget->item(selectedRow, 1)->text(), ui->tableWidget->item(selectedRow, 2)->text(), ui->tableWidget->item(selectedRow, 3)->text(), ui->tableWidget->item(selectedRow, 4)->text());

    connect(dialogWindow, &AddTicketDialog::addTicket, this, [=](const QString &brand, const QString &model, const QString &registration, const QString problemDescription)
            {
        int ticketId = rowToIdMap.value(selectedRow);

        // Retreiving assigned employee id, price paid by client and state
        QSqlQuery query("SELECT AssignedEmployeeID, PricePaidByClient, State FROM Tickets WHERE TicketId = " + QString::number(ticketId));
        QString assignedEmployeeID = query.value(0).toString();
        QString pricePaidByClient = query.value(1).toString();
        QString state = query.value(2).toString();

        dbManager->updateTicket(ticketId, brand, model, registration, problemDescription, assignedEmployeeID.toInt(), pricePaidByClient.toDouble(), state);

        ui->tableWidget->item(selectedRow, 1)->setText(brand);
        ui->tableWidget->item(selectedRow, 2)->setText(model);
        ui->tableWidget->item(selectedRow, 3)->setText(registration);
        ui->tableWidget->item(selectedRow, 4)->setText(problemDescription); 
        
        emit ticketsUpdated(); });

    dialogWindow->exec();
}
