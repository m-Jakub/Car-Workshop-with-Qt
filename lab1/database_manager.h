// databasemanager.h

#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include <QSqlDatabase>
#include <QString>
#include <QDateTime>

class DatabaseManager
{
public:
    DatabaseManager(const QString& path);
    bool open();
    void close();

    // Methods for performing database operations
    bool addEmployee(const QString& name, double hourlyRate);
    bool removeEmployee(int employeeID);
    bool addCalendarEntry(int employeeID, const QDateTime& startTime, const QDateTime& endTime, const QString& status, const QString& description);
    bool addTicket(const QString& vehicleBrand, const QString& vehicleModel, const QString& registrationID, const QString& problemDescription, int assignedEmployeeID, double pricePaidByClient, const QString& state);
    bool addEstimate(int ticketID, const QString& description, double expectedCost, bool acceptedByClient);
    bool addParts(int ticketID, const QString& description, double amount, double unitPrice);
    bool addWorkLogEntry(int ticketID, int employeeID, const QDateTime& startTime, const QDateTime& endTime);

private:
    QSqlDatabase m_db;
    QString m_path;
};

#endif // DATABASE_MANAGER_H
