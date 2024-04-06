#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "database_manager.h"
#include "add_employee_dialog.h"
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
    // ==================================================   
    // IMPLEMENT ENABLING AND DISABLING OF DELETE BUTTON
    // ==================================================   
    void on_deleteButton_clicked();
    void on_addButton_clicked();
    // ==================================================   
    // bool eventFilter(QObject *watched, QEvent *event);
    // ==================================================


    void on_updateButton_clicked();

private:
    Ui::Employees *ui;
    DatabaseManager *dbManager; // Pointer to the database
    QHash<int, int> rowToIdMap; // Maps row number to employee ID
    AddEmployeeDialog *dialogWindow = nullptr;
};

#endif // EMPLOYEES_H
