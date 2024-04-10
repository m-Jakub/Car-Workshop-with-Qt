#include "mainwindow.h"
#include "employees.h"
#include "database_manager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // short testing for database manager
    DatabaseManager dbManager("database.db");

    // other code
    MainWindow w(&dbManager);
    w.show();

    return a.exec();
}
