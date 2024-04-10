// add_employee_dialog.h
#ifndef ADD_EMPLOYEE_DIALOG_H
#define ADD_EMPLOYEE_DIALOG_H

#include <QDialog>
#include "database_manager.h"

namespace Ui
{
    class AddEmployeeDialog;
}

class AddEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddEmployeeDialog(DatabaseManager *dbManager, const QString &name = "", double hourlyRate = 0.0, QWidget *parent = nullptr);
    ~AddEmployeeDialog();

signals:
    void addEmployee(const QString &name, double hourlyRate);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::AddEmployeeDialog *ui;
    DatabaseManager *dbManager;
};

#endif // ADD_EMPLOYEE_DIALOG_H
