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
}

DatabaseManager::~DatabaseManager()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}

bool DatabaseManager::isOpen() const
{
    return m_db.isOpen();
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
    if (!isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return false;
    }

    QSqlQuery query;

    QString createTablesQuery =
        "CREATE TABLE IF NOT EXISTS Employees ("
        "EmployeeID INTEGER PRIMARY KEY,"
        "Name TEXT NOT NULL,"
        "HourlyRate DECIMAL(10, 2) NOT NULL"
        ");"
        "CREATE TABLE IF NOT EXISTS Calendar ("
        "CalendarID INTEGER PRIMARY KEY,"
        "EmployeeID INTEGER NOT NULL,"
        "StartTime DATETIME NOT NULL," // start time of a slot
        "EndTime DATETIME NOT NULL,"
        "Status TEXT NOT NULL," // busy or available
        "Description TEXT,"
        "FOREIGN KEY (EmployeeID) REFERENCES Employees(EmployeeID)" // connecting with Employees table
        ");"
        "CREATE TABLE IF NOT EXISTS Tickets ("
        "TicketID INTEGER PRIMARY KEY,"
        "VehicleBrand TEXT NOT NULL,"
        "VehicleModel TEXT NOT NULL,"
        "RegistrationID TEXT NOT NULL,"
        "ProblemDescription TEXT NOT NULL,"
        "AssignedEmployeeID INTEGER,"
        "State TEXT NOT NULL,"
        "PricePaidByClient DECIMAL(10, 2) NOT NULL,"
        "FOREIGN KEY (AssignedEmployeeID) REFERENCES Employees(EmployeeID)"
        ");"
        "CREATE TABLE IF NOT EXISTS ScheduledRepairTimeSlots ("
        "TimeSlotID INTEGER PRIMARY KEY,"
        "TicketID INTEGER NOT NULL,"
        "StartTime DATETIME NOT NULL,"
        "EndTime DATETIME NOT NULL,"
        "FOREIGN KEY (TicketID) REFERENCES Tickets(TicketID)"
        ");"
        "CREATE TABLE IF NOT EXISTS Estimates ("
        "EstimateID INTEGER PRIMARY KEY,"
        "TicketID INTEGER NOT NULL,"
        "Description TEXT NOT NULL,"
        "ExpectedCost DECIMAL(10, 2) NOT NULL,"
        "AcceptedByClient BOOLEAN NOT NULL,"
        "FOREIGN KEY (TicketID) REFERENCES Tickets(TicketID)"
        ");"
        "CREATE TABLE IF NOT EXISTS Parts ("
        "PartID INTEGER PRIMARY KEY,"
        "TicketID INTEGER NOT NULL,"
        "Description TEXT NOT NULL,"
        "Amount DECIMAL(10, 2) NOT NULL,"
        "UnitPrice DECIMAL(10, 2) NOT NULL,"
        "TotalPrice DECIMAL(10, 2) GENERATED ALWAYS AS (Amount * UnitPrice) VIRTUAL,"
        "FOREIGN KEY (TicketID) REFERENCES Tickets(TicketID)"
        ");"
        "CREATE TABLE IF NOT EXISTS WorkLog ("
        "WorkLogID INTEGER PRIMARY KEY,"
        "TicketID INTEGER NOT NULL,"
        "EmployeeID INTEGER NOT NULL,"
        "StartTime DATETIME NOT NULL,"
        "EndTime DATETIME NOT NULL,"
        "FOREIGN KEY (TicketID) REFERENCES Tickets(TicketID),"
        "FOREIGN KEY (EmployeeID) REFERENCES Employees(EmployeeID)"
        ");";

    bool success = query.exec(createTablesQuery);

    if (!success)
    {
        qDebug() << "Error: Failed to create tables:" << query.lastError().text();
        m_db.close(); // Close the database connection if table creation failed
        return false;
    }

    qDebug() << "Tables created successfully.";

    return true;
}