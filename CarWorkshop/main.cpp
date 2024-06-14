#include "mainwindow.h"
#include "employees.h"
#include "database_manager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DatabaseManager dbManager("database.db");

    if (dbManager.isDatabaseEmpty())
        dbManager.fillDatabaseWithExemplaryData(&dbManager);

    MainWindow w(&dbManager);
    w.show();

    return a.exec();
}
