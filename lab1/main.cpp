#include "mainwindow.h"
#include "employees.h"
#include "database_manager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DatabaseManager dbManager("database.db");

    // Filling the database with some data
    // Can be uncommented to fill the database with some data
    dbManager.fillDatabaseWithExemplaryData(&dbManager);

    MainWindow w(&dbManager);
    w.show();

    return a.exec();
}
