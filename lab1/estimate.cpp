#include "estimate.h"
#include "ui_estimate.h"
#include "database_manager.h"
#include <QPushButton>
#include <QSqlQuery>
#include <QSqlError>

// bool DatabaseManager::createTables()
// {
//     if (!m_db.isOpen())
//     {
//         qDebug() << "Error: Database is not open.";
//         return false;
//     }

//     QSqlQuery query;

//     if (!query.exec("CREATE TABLE IF NOT EXISTS Employees ("
//                     "EmployeeID INTEGER PRIMARY KEY,"
//                     "Name TEXT NOT NULL,"
//                     "HourlyRate DECIMAL(10, 2) NOT NULL"
//                     ");"))
//     {
//         qDebug() << "Error: Failed to create Employees table:" << query.lastError().text();
//         m_db.close();
//         return false;
//     }

//     if (!query.exec("CREATE TABLE IF NOT EXISTS Tickets ("
//                     "TicketID INTEGER PRIMARY KEY,"
//                     "VehicleBrand TEXT NOT NULL,"
//                     "VehicleModel TEXT NOT NULL,"
//                     "RegistrationID TEXT NOT NULL,"
//                     "ProblemDescription TEXT NOT NULL,"
//                     "AssignedEmployeeID INTEGER,"
//                     "State TEXT NOT NULL,"
//                     "PricePaidByClient DECIMAL(10, 2) NOT NULL,"
//                     "FOREIGN KEY (AssignedEmployeeID) REFERENCES Employees(EmployeeID)"
//                     ");"))
//     {
//         qDebug() << "Error: Failed to create Tickets table:" << query.lastError().text();
//         m_db.close();
//         return false;
//     }

//     if (!query.exec("CREATE TABLE IF NOT EXISTS ScheduledRepairTimeSlots ("
//                     "TimeSlotID INTEGER PRIMARY KEY,"
//                     "TicketID INTEGER NOT NULL,"
//                     "EmployeeID INTEGER NOT NULL,"
//                     "StartHour TEXT NOT NULL,"
//                     "EndHour TEXT NOT NULL,"
//                     "DayOfWeek TEXT NOT NULL,"
//                     "FOREIGN KEY (TicketID) REFERENCES Tickets(TicketID)"
//                     ");"))
//     {
//         qDebug() << "Error: Failed to create ScheduledRepairTimeSlots table:" << query.lastError().text();
//         m_db.close();
//         return false;
//     }

//     if (!query.exec("CREATE TABLE IF NOT EXISTS Estimates ("
//                     "EstimateID INTEGER PRIMARY KEY,"
//                     "TicketID INTEGER NOT NULL,"
//                     "Description TEXT NOT NULL,"
//                     "ExpectedCost DECIMAL(10, 2) NOT NULL,"
//                     "AcceptedByClient BOOLEAN NOT NULL,"
//                     "FOREIGN KEY (TicketID) REFERENCES Tickets(TicketID)"
//                     ");"))
//     {
//         qDebug() << "Error: Failed to create Estimates table:" << query.lastError().text();
//         m_db.close();
//         return false;
//     }

//     if (!query.exec("CREATE TABLE IF NOT EXISTS Parts ("
//                     "PartID INTEGER PRIMARY KEY,"
//                     "TicketID INTEGER NOT NULL,"
//                     "Description TEXT NOT NULL,"
//                     "Amount DECIMAL(10, 2) NOT NULL,"
//                     "UnitPrice DECIMAL(10, 2) NOT NULL,"
//                     "TotalPrice DECIMAL(10, 2) GENERATED ALWAYS AS (Amount * UnitPrice) VIRTUAL,"
//                     "FOREIGN KEY (TicketID) REFERENCES Tickets(TicketID)"
//                     ");"))
//     {
//         qDebug() << "Error: Failed to create Parts table:" << query.lastError().text();
//         m_db.close();
//         return false;
//     }

//     if (!query.exec("CREATE TABLE IF NOT EXISTS WorkLog ("
//                     "WorkLogID INTEGER PRIMARY KEY,"
//                     "TicketID INTEGER NOT NULL,"
//                     "EmployeeID INTEGER NOT NULL,"
//                     "StartHour TEXT NOT NULL,"
//                     "EndHour TEXT NOT NULL,"
//                     "FOREIGN KEY (TicketID) REFERENCES Tickets(TicketID),"
//                     "FOREIGN KEY (EmployeeID) REFERENCES Employees(EmployeeID)"
//                     ");"))
//     {
//         qDebug() << "Error: Failed to create WorkLog table:" << query.lastError().text();
//         m_db.close();
//         return false;
//     }

//     qDebug() << "Tables created successfully.";

//     return true;
// }

Estimate::Estimate(DatabaseManager *dbManager, int ticketID, QWidget *parent)
    : QDialog(parent), ui(new Ui::Estimate), dbManager(dbManager), ticketID(ticketID)
{
    ui->setupUi(this);

    // Filling the fields with the ticket's details
    fillFields();

    // Setting accept button name
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Save");
}

Estimate::~Estimate()
{
    delete ui;
}

void Estimate::fillFields()
{
    QSqlQuery query;
    query.prepare("SELECT Description, ExpectedCost, AcceptedByClient FROM Estimates WHERE TicketID = :ticketID");
    query.bindValue(":ticketID", ticketID);
    if (!query.exec())
    {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    if (query.next())
    {
        ui->description->setText(query.value(0).toString());
        ui->expectedCost->setValue(query.value(1).toDouble());
        bool accepted = query.value(2).toBool();
        int index = accepted ? 1 : 0;
        ui->acceptedByClient->setCurrentIndex(index);
    }
}

void Estimate::on_buttonBox_accepted()
{
    if (dbManager->estimateExists(ticketID))
        dbManager->updateEstimate(ticketID, ui->description->toPlainText(), ui->expectedCost->value(), ui->acceptedByClient->currentIndex());

    else
        dbManager->addEstimate(ticketID, ui->description->toPlainText(), ui->expectedCost->value(), ui->acceptedByClient->currentIndex());
}
