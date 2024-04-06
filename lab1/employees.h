#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "database_manager.h"
#include "addemployee.h"
#include <QWidget>

namespace Ui
{
    class Employees;
}

class Employees : public QWidget
{
    Q_OBJECT

public:
    explicit Employees(DatabaseManager *dbmanager, QWidget *parent = nullptr);
    ~Employees();
    void setupTable();
    void populateTable();

private slots:
    void on_Delete_clicked();
    void on_Add_clicked();
    // bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::Employees *ui;
    DatabaseManager *dbManager; // Pointer to the database
    QHash<int, int> rowToIdMap; // Maps row number to employee ID
    AddEmployee *addEmployeeWindow = nullptr;
};

#endif // EMPLOYEES_H
