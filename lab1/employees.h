#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "database_manager.h"
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

private:
    Ui::Employees *ui;
    DatabaseManager *dbManager; // Pointer to the database
    QHash<int, int> rowToIdMap; // Maps row number to employee ID
};

#endif // EMPLOYEES_H
