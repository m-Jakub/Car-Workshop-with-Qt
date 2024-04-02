#include "mainwindow.h"
#include "database_manager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // testing database manager
    DatabaseManager dbManager("test.db");

    // other code
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
