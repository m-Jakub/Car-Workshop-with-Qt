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
    query.prepare("UPDATE Tickets SET AssignedEmployeeID = NULL WHERE AssignedEmployeeID = :employeeID");
    query.bindValue(":employeeID", employeeID);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to remove employee from tickets:" << query.lastError().text();
        return false;
    }

    query.prepare("DELETE FROM ScheduledRepairTimeSlots WHERE EmployeeID = :employeeID");
    query.bindValue(":employeeID", employeeID);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to remove employee schedules:" << query.lastError().text();
        return false;
    }

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

QString DatabaseManager::getEmployeeName(int employeeID)
{
    if (!m_db.isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return "";
    }

    QSqlQuery query;
    query.prepare("SELECT Name FROM Employees WHERE EmployeeID = :employeeID");
    query.bindValue(":employeeID", employeeID);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to get employee name:" << query.lastError().text();
        return "";
    }

    if (query.next())
    {
        return query.value(0).toString();
    }

    return "";
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

bool DatabaseManager::ticketExists(const QString &registrationID)
{
    if (!m_db.isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return false;
    }

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Tickets WHERE RegistrationID = :registrationID");
    query.bindValue(":registrationID", registrationID);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to check if ticket exists:" << query.lastError().text();
        return false;
    }

    if (query.next())
    {
        return query.value(0).toInt() > 0;
    }

    return false;
}

bool DatabaseManager::removeTicket(int ticketID)
{
    if (!m_db.isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return false;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM ScheduledRepairTimeSlots WHERE TicketID = :ticketID");
    query.bindValue(":ticketID", ticketID);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to remove repair schedules:" << query.lastError().text();
        return false;
    }

    query.prepare("DELETE FROM Estimates WHERE TicketID = :ticketID");
    query.bindValue(":ticketID", ticketID);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to remove estimate parts:" << query.lastError().text();
        return false;
    }

    query.prepare("DELETE FROM Parts WHERE TicketID = :ticketID");
    query.bindValue(":ticketID", ticketID);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to remove work log entries:" << query.lastError().text();
        return false;
    }

    query.prepare("DELETE FROM WorkLog WHERE TicketID = :ticketID");
    query.bindValue(":ticketID", ticketID);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to remove work log entries:" << query.lastError().text();
        return false;
    }

    query.prepare("DELETE FROM Tickets WHERE TicketID = :ticketID");
    query.bindValue(":ticketID", ticketID);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to remove ticket:" << query.lastError().text();
        return false;
    }

    qDebug() << "Ticket and associated entries removed successfully.";
    return true;
}

bool DatabaseManager::updateTicket(int ticketID, const QString &vehicleBrand, const QString &vehicleModel, const QString &registrationID, const QString &problemDescription, int assignedEmployeeID)
{
    if (!m_db.isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return false;
    }

    QSqlQuery query;
    query.prepare("UPDATE Tickets SET VehicleBrand = :vehicleBrand, VehicleModel = :vehicleModel, RegistrationID = :registrationID, ProblemDescription = :problemDescription, AssignedEmployeeID = :assignedEmployeeID WHERE TicketID = :ticketID");
    query.bindValue(":vehicleBrand", vehicleBrand);
    query.bindValue(":vehicleModel", vehicleModel);
    query.bindValue(":registrationID", registrationID);
    query.bindValue(":problemDescription", problemDescription);
    query.bindValue(":assignedEmployeeID", assignedEmployeeID);
    query.bindValue(":ticketID", ticketID);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to update ticket:" << query.lastError().text();
        return false;
    }

    qDebug() << "Ticket updated successfully.";
    return true;
}

bool DatabaseManager::updateTicketState(int ticketID, const QString &state)
{
    if (!m_db.isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return false;
    }

    QSqlQuery query;
    query.prepare("UPDATE Tickets SET State = :state WHERE TicketID = :ticketID");
    query.bindValue(":state", state);
    query.bindValue(":ticketID", ticketID);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to update ticket state:" << query.lastError().text();
        return false;
    }

    qDebug() << "Ticket state updated successfully.";
    return true;
}

bool DatabaseManager::updateTicketPrice(int ticketID, double pricePaidByClient)
{
    if (!m_db.isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return false;
    }

    QSqlQuery query;
    query.prepare("UPDATE Tickets SET PricePaidByClient = :pricePaidByClient WHERE TicketID = :ticketID");
    query.bindValue(":pricePaidByClient", pricePaidByClient);
    query.bindValue(":ticketID", ticketID);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to update ticket price paid by client:" << query.lastError().text();
        return false;
    }

    qDebug() << "Ticket price paid by client updated successfully.";
    return true;
}

QString DatabaseManager::getTicketRegistrationID(int ticketID)
{
    if (!m_db.isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return "";
    }

    QSqlQuery query;
    query.prepare("SELECT RegistrationID FROM Tickets WHERE TicketID = :ticketID");
    query.bindValue(":ticketID", ticketID);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to get ticket registration ID:" << query.lastError().text();
        return "";
    }

    if (query.next())
    {
        return query.value(0).toString();
    }

    return "";
}

int DatabaseManager::addRepairSchedule(int ticketID, int employeeID, const QString &startHour, const QString &endHour, const QString &dayOfWeek)
{
    if (!m_db.isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return 0;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO ScheduledRepairTimeSlots (TicketID, EmployeeID, StartHour, EndHour, DayOfWeek)"
                  "VALUES (:ticketID, :employeeID, :startHour, :endHour, :dayOfWeek)");
    query.bindValue(":ticketID", ticketID);
    query.bindValue(":employeeID", employeeID);
    query.bindValue(":startHour", startHour);
    query.bindValue(":endHour", endHour);
    query.bindValue(":dayOfWeek", dayOfWeek);

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

bool DatabaseManager::updateEstimate(int ticketID, const QString &description, double expectedCost, bool acceptedByClient)
{
    if (!m_db.isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return false;
    }

    QSqlQuery query;
    query.prepare("UPDATE Estimates SET Description = :description, ExpectedCost = :expectedCost, AcceptedByClient = :acceptedByClient WHERE TicketID = :ticketID");
    query.bindValue(":description", description);
    query.bindValue(":expectedCost", expectedCost);
    query.bindValue(":acceptedByClient", acceptedByClient);
    query.bindValue(":ticketID", ticketID);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to update estimate:" << query.lastError().text();
        return false;
    }

    qDebug() << "Estimate updated successfully.";
    return true;
}

bool DatabaseManager::estimateExists(int ticketID)
{
    if (!m_db.isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return false;
    }

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Estimates WHERE TicketID = :ticketID");
    query.bindValue(":ticketID", ticketID);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to check if estimate exists:" << query.lastError().text();
        return false;
    }

    if (query.next())
    {
        return query.value(0).toInt() > 0;
    }

    return false;
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

bool DatabaseManager::removeParts(int partID)
{
    if (!m_db.isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return false;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM Parts WHERE PartID = :partID");
    query.bindValue(":partID", partID);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to remove parts:" << query.lastError().text();
        return false;
    }

    qDebug() << "Parts removed successfully.";
    return true;
}

bool DatabaseManager::updateParts(int partID, const QString &description, double amount, double unitPrice)
{
    if (!m_db.isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return false;
    }

    QSqlQuery query;
    query.prepare("UPDATE Parts SET Description = :description, Amount = :amount, UnitPrice = :unitPrice WHERE PartID = :partID");
    query.bindValue(":description", description);
    query.bindValue(":amount", amount);
    query.bindValue(":unitPrice", unitPrice);
    query.bindValue(":partID", partID);

    if (!query.exec())
    {
        qDebug() << "Error: Failed to update parts:" << query.lastError().text();
        return false;
    }

    qDebug() << "Parts updated successfully.";
    return true;
}

int DatabaseManager::addWorkLogEntry(int ticketID, int employeeID, const QString &startHour, const QString &endHour)
{
    if (!m_db.isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return 0;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO WorkLog (TicketID, EmployeeID, StartHour, EndHour)"
                  "VALUES (:ticketID, :employeeID, :startHour, :endHour)");
    query.bindValue(":ticketID", ticketID);
    query.bindValue(":employeeID", employeeID);
    query.bindValue(":startHour", startHour);
    query.bindValue(":endHour", endHour);

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
        m_db.close();
        return false;
    }

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
        m_db.close();
        return false;
    }

    if (!query.exec("CREATE TABLE IF NOT EXISTS ScheduledRepairTimeSlots ("
                    "TimeSlotID INTEGER PRIMARY KEY,"
                    "TicketID INTEGER NOT NULL,"
                    "EmployeeID INTEGER NOT NULL,"
                    "StartHour TEXT NOT NULL,"
                    "EndHour TEXT NOT NULL,"
                    "DayOfWeek TEXT NOT NULL,"
                    "FOREIGN KEY (TicketID) REFERENCES Tickets(TicketID)"
                    ");"))
    {
        qDebug() << "Error: Failed to create ScheduledRepairTimeSlots table:" << query.lastError().text();
        m_db.close();
        return false;
    }

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
        m_db.close();
        return false;
    }

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
        m_db.close();
        return false;
    }

    if (!query.exec("CREATE TABLE IF NOT EXISTS WorkLog ("
                    "WorkLogID INTEGER PRIMARY KEY,"
                    "TicketID INTEGER NOT NULL,"
                    "EmployeeID INTEGER NOT NULL,"
                    "StartHour TEXT NOT NULL,"
                    "EndHour TEXT NOT NULL,"
                    "FOREIGN KEY (TicketID) REFERENCES Tickets(TicketID),"
                    "FOREIGN KEY (EmployeeID) REFERENCES Employees(EmployeeID)"
                    ");"))
    {
        qDebug() << "Error: Failed to create WorkLog table:" << query.lastError().text();
        m_db.close();
        return false;
    }

    qDebug() << "Tables created successfully.";

    return true;
}

void DatabaseManager::fillDatabaseWithExemplaryData(DatabaseManager *dbManager)
{
    // Adding employees
    dbManager->addEmployee("John Doe", 20.0);
    dbManager->addEmployee("Ivan Ivanov", 25.0);
    dbManager->addEmployee("Oliver Smith", 30.0);
    dbManager->addEmployee("Maria Garcia", 35.0);
    dbManager->addEmployee("Anna Johnson", 40.0);

    // Adding tickets
    dbManager->addTicket("Ford", "Focus", "KR12345", "Engine failure", 1, 0.0, "created");
    dbManager->addTicket("Audi", "A4", "KR67890", "Brake failure", 2, 0.0, "in progress");
    dbManager->addTicket("BMW", "X5", "KR54321", "Gearbox failure", 3, 300.0, "closed");
    dbManager->addTicket("Mercedes", "C-Class", "KR09876", "Suspension failure", 4, 0.0, "in progress");
    dbManager->addTicket("Volkswagen", "Golf", "KR45678", "Steering failure", 5, 0.0, "done");
    dbManager->addTicket("Toyota", "Corolla", "KR78901", "Electrical fail", 1, 600.0, "closed");
    dbManager->addTicket("Opel", "Astra", "KR23456", "Cooling system failure", 2, 0.0, "created");

    // Adding repair schedules
    dbManager->addRepairSchedule(1, 1, "8", "12", "3");
    dbManager->addRepairSchedule(1, 1, "13", "17", "3");
    dbManager->addRepairSchedule(1, 2, "8", "10", "4");
    dbManager->addRepairSchedule(2, 2, "8", "11", "1");
    dbManager->addRepairSchedule(2, 3, "8", "12", "6");
    dbManager->addRepairSchedule(3, 3, "14", "16", "2");
    dbManager->addRepairSchedule(3, 5, "15", "19", "2");
    dbManager->addRepairSchedule(4, 4, "9", "12", "5");
    dbManager->addRepairSchedule(4, 4, "13", "17", "5");
    dbManager->addRepairSchedule(5, 5, "8", "12", "2");
    dbManager->addRepairSchedule(5, 5, "13", "17", "1");
    dbManager->addRepairSchedule(6, 1, "8", "12", "3");
    dbManager->addRepairSchedule(6, 1, "13", "17", "3");

    // Adding estimates
    dbManager->addEstimate(1, "Engine needs to be replaced, we have to order a new one.", 1000.0, false);
    dbManager->addEstimate(2, "Brake pads need to be replaced, we have them in stock.", 200.0, true);
    dbManager->addEstimate(3, "Gearbox needs to be repaired, we have to order parts.", 300.0, false);
    dbManager->addEstimate(6, "Electrical system needs to be repaired, we have to order parts.", 600.0, true);
    dbManager->addEstimate(7, "Cooling system needs to be repaired, we have to order parts.", 700.0, true);

    // Adding parts
    dbManager->addParts(1, "Engine", 1, 1000.0);
    dbManager->addParts(1, "Oil", 5, 10.0);
    dbManager->addParts(2, "Brake pads", 1, 200.0);
    dbManager->addParts(2, "Brake discs", 2, 50.0);
    dbManager->addParts(2, "Brake fluid", 1, 10.0);
    dbManager->addParts(3, "Gearbox", 1, 300.0);
    dbManager->addParts(6, "Electrical system parts", 1, 600.0);
    dbManager->addParts(7, "Cooling system parts", 1, 700.0);
}

bool DatabaseManager::isDatabaseEmpty()
{
    if (!m_db.isOpen())
    {
        qDebug() << "Error: Database is not open.";
        return true;
    }

    QStringList tables = m_db.tables();
    foreach (const QString &table, tables) {
        QSqlQuery query(QString("SELECT COUNT(*) FROM %1").arg(table));

        if (!query.exec())
        {
            qDebug() << "Error: Failed to check if database is empty:" << query.lastError().text();
            return true;
        }

        if (query.next())
        {
            if (query.value(0).toInt() != 0)
                return false;
        }
    }

    return true;
}