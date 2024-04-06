#ifndef ADDEMPLOYEE_H
#define ADDEMPLOYEE_H

#include "database_manager.h"
#include <QWidget>

namespace Ui
{
    class AddEmployee;
}

class AddEmployee : public QWidget
{
    Q_OBJECT

public:
    explicit AddEmployee(DatabaseManager *dbManager, QWidget *parent = nullptr);
    ~AddEmployee();

private slots:
    void on_cancelButton_clicked();

private:
    Ui::AddEmployee *ui;
    DatabaseManager *dbManager;
};

#endif // ADDEMPLOYEE_H
