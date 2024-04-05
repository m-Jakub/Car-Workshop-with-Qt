#include "mainwindow.h"
#include "employees.h"
#include "database_manager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // short testing for database manager
    DatabaseManager dbManager("test.db");
    dbManager.removeAllEmployees();
    dbManager.addEmployee("John Doe", 10.0);
    dbManager.addEmployee("Jane Doe", 15.0);
    dbManager.addEmployee("Adam Smith", 12.0);
    dbManager.addEmployee("Emily Johnson", 14.0);
    dbManager.addEmployee("Michael Williams", 11.0);
    dbManager.addEmployee("Olivia Brown", 13.0);
    dbManager.addEmployee("Daniel Jones", 10.0);
    dbManager.addEmployee("Sophia Miller", 15.0);
    dbManager.addEmployee("Matthew Davis", 12.0);
    dbManager.addEmployee("Ava Garcia", 14.0);
    dbManager.addEmployee("Jacob Rodriguez", 11.0);
    dbManager.addEmployee("Isabella Wilson", 13.0);
    dbManager.addEmployee("William Martinez", 10.0);
    dbManager.addEmployee("Mia Anderson", 15.0);
    dbManager.addEmployee("Joseph Taylor", 12.0);
    dbManager.addEmployee("Charlotte Thomas", 14.0);
    dbManager.addEmployee("David Hernandez", 11.0);
    dbManager.addEmployee("Samantha Moore", 13.0);
    dbManager.addEmployee("James Clark", 10.0);
    dbManager.addEmployee("Abigail Lewis", 15.0);

    dbManager.addCalendarEntry(1, QDateTime::currentDateTime(), QDateTime::currentDateTime().addSecs(3600), "Available", "No description");
    dbManager.addCalendarEntry(2, QDateTime::currentDateTime(), QDateTime::currentDateTime().addSecs(3600), "Available", "No description");
    dbManager.addCalendarEntry(1, QDateTime::currentDateTime().addDays(1), QDateTime::currentDateTime().addDays(1).addSecs(3600), "Available", "No description");

    dbManager.addTicket("Toyota", "Corolla", "ABC-123", "Engine failure", 1, 100.0, "Pending");
    dbManager.addTicket("Ford", "Focus", "XYZ-456", "Oil change", 2, 50.0, "Pending");

    dbManager.addRepairSchedule(1, 1, QDateTime::currentDateTime(), QDateTime::currentDateTime().addSecs(3600));
    dbManager.addRepairSchedule(2, 2, QDateTime::currentDateTime(), QDateTime::currentDateTime().addSecs(3600));
    dbManager.addRepairSchedule(1, 1, QDateTime::currentDateTime().addDays(1), QDateTime::currentDateTime().addDays(1).addSecs(3600));
    dbManager.addRepairSchedule(2, 2, QDateTime::currentDateTime().addDays(1), QDateTime::currentDateTime().addDays(1).addSecs(3600));

    dbManager.addEstimate(1, "Engine replacement", 500.0, false);
    dbManager.addEstimate(1, "Oil change", 10.0, true);

    dbManager.addParts(1, "Engine", 1, 500.0);
    dbManager.addParts(1, "Oil", 5, 10.0);

    dbManager.addWorkLogEntry(1, 1, QDateTime::currentDateTime(), QDateTime::currentDateTime().addSecs(3600));
    dbManager.addWorkLogEntry(1, 2, QDateTime::currentDateTime(), QDateTime::currentDateTime().addSecs(3600));

    // other code
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
