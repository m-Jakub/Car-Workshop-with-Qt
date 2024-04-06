// database_manager.cpp

#include "database_manager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseManager::DatabaseManager(const QString &path)
    : m_path(path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(m_path);

    open();
    createTables();
}

int DatabaseManager::addEmployee(const QString &name, double hourlyRate)
{
    if (!m_db.isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return 0;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO Employees (Name, HourlyRate) VALUES (:name, :hourlyRate)");
    query.bindValue(":name", name);
    query.bindValue(":hourlyRate", hourlyRate);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to add employee:" << query.lastError().text();
        return 0;
    }

    int employeeID = query.lastInsertId().toInt();

    qDebug() << "Employee added successfully with ID:" << employeeID;
    return employeeID;
}

bool DatabaseManager::removeEmployee(int employeeID)
{
    if (!m_db.isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return false;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM Employees WHERE EmployeeID = :employeeID");
    query.bindValue(":employeeID", employeeID);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to remove employee:" << query.lastError().text();
        return false;
    }

    qDebug() << "Employee removed successfully.";
    return true;
}

bool DatabaseManager::updateEmployee(int employeeID, const QString &name, double hourlyRate)
{
    if (!m_db.isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return false;
    }

    QSqlQuery query;
    query.prepare("UPDATE Employees SET Name = :name, HourlyRate = :hourlyRate WHERE EmployeeID = :employeeID");
    query.bindValue(":name", name);
    query.bindValue(":hourlyRate", hourlyRate);
    query.bindValue(":employeeID", employeeID);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to update employee:" << query.lastError().text();
        return false;
    }

    qDebug() << "Employee updated successfully.";
    return true;
}

bool DatabaseManager::removeAllEmployees()
{
    if (!m_db.isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return false;
    }

    QSqlQuery query("DELETE FROM Employees");

    if (!query.exec())
    {
        qDebug() << "Error: Failed to remove all employees:" << query.lastError().text();
        return false;
    }

    qDebug() << "All employees removed successfully.";
    return true;
}

int DatabaseManager::addCalendarEntry(int employeeID, const QDateTime &startTime, const QDateTime &endTime, const QString &status, const QString &description)
{
    if (!m_db.isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return 0;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO Calendar (EmployeeID, StartTime, EndTime, Status, Description)"
                  "VALUES (:employeeID, :startTime, :endTime, :status, :description)");
    query.bindValue(":employeeID", employeeID);
    query.bindValue(":startTime", startTime);
    query.bindValue(":endTime", endTime);
    query.bindValue(":status", status);
    query.bindValue(":description", description);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to add calendar entry:" << query.lastError().text();
        return 0;
    }

    int calendarID = query.lastInsertId().toInt();

    qDebug() << "Calendar entry added successfully with ID:" << calendarID;
    return calendarID;
}

int DatabaseManager::addTicket(const QString &vehicleBrand, const QString &vehicleModel, const QString &registrationID, const QString &problemDescription, int assignedEmployeeID, double pricePaidByClient, const QString &state)
{
    if (!m_db.isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return 0;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO Tickets (VehicleBrand, VehicleModel, RegistrationID, ProblemDescription, AssignedEmployeeID, State, PricePaidByClient)"
                  "VALUES (:vehicleBrand, :vehicleModel, :registrationID, :problemDescription, :assignedEmployeeID, :state, :pricePaidByClient)");
    query.bindValue(":vehicleBrand", vehicleBrand);
    query.bindValue(":vehicleModel", vehicleModel);
    query.bindValue(":registrationID", registrationID);
    query.bindValue(":problemDescription", problemDescription);
    query.bindValue(":assignedEmployeeID", assignedEmployeeID);
    query.bindValue(":state", state);
    query.bindValue(":pricePaidByClient", pricePaidByClient);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to add ticket:" << query.lastError().text();
        return 0;
    }

    int ticketID = query.lastInsertId().toInt();

    qDebug() << "Ticket added successfully with ID:" << ticketID;
    return ticketID;
}

int DatabaseManager::addRepairSchedule(int ticketID, int employeeID, const QDateTime &startTime, const QDateTime &endTime)
{
    if (!m_db.isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return 0;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO ScheduledRepairTimeSlots (TicketID, StartTime, EndTime)"
                  "VALUES (:ticketID, :startTime, :endTime)");
    query.bindValue(":ticketID", ticketID);
    query.bindValue(":startTime", startTime);
    query.bindValue(":endTime", endTime);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to add repair schedule:" << query.lastError().text();
        return 0;
    }

    int timeSlotID = query.lastInsertId().toInt();

    qDebug() << "Repair schedule added successfully.";
    return timeSlotID;
}

int DatabaseManager::addEstimate(int ticketID, const QString &description, double expectedCost, bool acceptedByClient)
{
    if (!m_db.isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return 0;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO Estimates (TicketID, Description, ExpectedCost, AcceptedByClient)"
                  "VALUES (:ticketID, :description, :expectedCost, :acceptedByClient)");
    query.bindValue(":ticketID", ticketID);
    query.bindValue(":description", description);
    query.bindValue(":expectedCost", expectedCost);
    query.bindValue(":acceptedByClient", acceptedByClient);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to add estimate:" << query.lastError().text();
        return 0;
    }

    int estimateID = query.lastInsertId().toInt();

    qDebug() << "Estimate added successfully.";
    return estimateID;
}

int DatabaseManager::addParts(int ticketID, const QString &description, double amount, double unitPrice)
{
    if (!m_db.isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return 0;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO Parts (TicketID, Description, Amount, UnitPrice)"
                  "VALUES (:ticketID, :description, :amount, :unitPrice)");
    query.bindValue(":ticketID", ticketID);
    query.bindValue(":description", description);
    query.bindValue(":amount", amount);
    query.bindValue(":unitPrice", unitPrice);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to add parts:" << query.lastError().text();
        return 0;
    }

    int partID = query.lastInsertId().toInt();

    qDebug() << "Parts added successfully.";
    return partID;
}

int DatabaseManager::addWorkLogEntry(int ticketID, int employeeID, const QDateTime &startTime, const QDateTime &endTime)
{
    if (!m_db.isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return 0;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO WorkLog (TicketID, EmployeeID, StartTime, EndTime)"
                  "VALUES (:ticketID, :employeeID, :startTime, :endTime)");
    query.bindValue(":ticketID", ticketID);
    query.bindValue(":employeeID", employeeID);
    query.bindValue(":startTime", startTime);
    query.bindValue(":endTime", endTime);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to add work log entry:" << query.lastError().text();
        return 0;
    }

    int workLogID = query.lastInsertId().toInt();

    qDebug() << "Work log entry added successfully.";
    return workLogID;
}

bool DatabaseManager::open()
{
    if (!m_db.open())
    {
        qDebug() << "Error: Failed to open database:" << m_db.lastError().text();
        return false;
    }
    else
    {
        qDebug() << "Database: connection ok";
        return true;
    }
}

void DatabaseManager::close()
{
    m_db.close();
}
bool DatabaseManager::createTables()
{
    if (!m_db.isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return false;
    }

    QSqlQuery query;

    if (!query.exec("CREATE TABLE IF NOT EXISTS Employees ("
                    "EmployeeID INTEGER PRIMARY KEY,"
                    "Name TEXT NOT NULL,"
                    "HourlyRate DECIMAL(10, 2) NOT NULL"
                    ");"))
    {
        qDebug() << "Error: Failed to create Employees table:" << query.lastError().text();
        m_db.close(); // Close the database connection if table creation failed
        return false;
    }

    // Create Calendar table
    if (!query.exec("CREATE TABLE IF NOT EXISTS Calendar ("
                    "CalendarID INTEGER PRIMARY KEY,"
                    "EmployeeID INTEGER NOT NULL,"
                    "StartTime DATETIME NOT NULL,"
                    "EndTime DATETIME NOT NULL,"
                    "Status TEXT NOT NULL,"
                    "Description TEXT,"
                    "FOREIGN KEY (EmployeeID) REFERENCES Employees(EmployeeID)"
                    ");"))
    {
        qDebug() << "Error: Failed to create Calendar table:" << query.lastError().text();
        m_db.close(); // Close the database connection if table creation failed
        return false;
    }

    // Create Tickets table
    if (!query.exec("CREATE TABLE IF NOT EXISTS Tickets ("
                    "TicketID INTEGER PRIMARY KEY,"
                    "VehicleBrand TEXT NOT NULL,"
                    "VehicleModel TEXT NOT NULL,"
                    "RegistrationID TEXT NOT NULL,"
                    "ProblemDescription TEXT NOT NULL,"
                    "AssignedEmployeeID INTEGER,"
                    "State TEXT NOT NULL,"
                    "PricePaidByClient DECIMAL(10, 2) NOT NULL,"
                    "FOREIGN KEY (AssignedEmployeeID) REFERENCES Employees(EmployeeID)"
                    ");"))
    {
        qDebug() << "Error: Failed to create Tickets table:" << query.lastError().text();
        m_db.close(); // Close the database connection if table creation failed
        return false;
    }

    // Create ScheduledRepairTimeSlots table
    if (!query.exec("CREATE TABLE IF NOT EXISTS ScheduledRepairTimeSlots ("
                    "TimeSlotID INTEGER PRIMARY KEY,"
                    "TicketID INTEGER NOT NULL,"
                    "StartTime DATETIME NOT NULL,"
                    "EndTime DATETIME NOT NULL,"
                    "FOREIGN KEY (TicketID) REFERENCES Tickets(TicketID)"
                    ");"))
    {
        qDebug() << "Error: Failed to create ScheduledRepairTimeSlots table:" << query.lastError().text();
        m_db.close(); // Close the database connection if table creation failed
        return false;
    }

    // Create Estimates table
    if (!query.exec("CREATE TABLE IF NOT EXISTS Estimates ("
                    "EstimateID INTEGER PRIMARY KEY,"
                    "TicketID INTEGER NOT NULL,"
                    "Description TEXT NOT NULL,"
                    "ExpectedCost DECIMAL(10, 2) NOT NULL,"
                    "AcceptedByClient BOOLEAN NOT NULL,"
                    "FOREIGN KEY (TicketID) REFERENCES Tickets(TicketID)"
                    ");"))
    {
        qDebug() << "Error: Failed to create Estimates table:" << query.lastError().text();
        m_db.close(); // Close the database connection if table creation failed
        return false;
    }

    // Create Parts table
    if (!query.exec("CREATE TABLE IF NOT EXISTS Parts ("
                    "PartID INTEGER PRIMARY KEY,"
                    "TicketID INTEGER NOT NULL,"
                    "Description TEXT NOT NULL,"
                    "Amount DECIMAL(10, 2) NOT NULL,"
                    "UnitPrice DECIMAL(10, 2) NOT NULL,"
                    "TotalPrice DECIMAL(10, 2) GENERATED ALWAYS AS (Amount * UnitPrice) VIRTUAL,"
                    "FOREIGN KEY (TicketID) REFERENCES Tickets(TicketID)"
                    ");"))
    {
        qDebug() << "Error: Failed to create Parts table:" << query.lastError().text();
        m_db.close(); // Close the database connection if table creation failed
        return false;
    }

    // Create WorkLog table
    if (!query.exec("CREATE TABLE IF NOT EXISTS WorkLog ("
                    "WorkLogID INTEGER PRIMARY KEY,"
                    "TicketID INTEGER NOT NULL,"
                    "EmployeeID INTEGER NOT NULL,"
                    "StartTime DATETIME NOT NULL,"
                    "EndTime DATETIME NOT NULL,"
                    "FOREIGN KEY (TicketID) REFERENCES Tickets(TicketID),"
                    "FOREIGN KEY (EmployeeID) REFERENCES Employees(EmployeeID)"
                    ");"))
    {
        qDebug() << "Error: Failed to create WorkLog table:" << query.lastError().text();
        m_db.close(); // Close the database connection if table creation failed
        return false;
    }

    qDebug() << "Tables created successfully.";

    return true;
}