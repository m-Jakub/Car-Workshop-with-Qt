#include "mainwindow.h"
#include "database_manager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // short testing for database manager
    DatabaseManager dbManager("test.db");
    dbManager.addEmployee("John Doe", 10.0);
    dbManager.addEmployee("Jane Doe", 15.0);

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
