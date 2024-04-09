// add_ticket_dialog.h
#ifndef ADD_TICKET_DIALOG_H
#define ADD_TICKET_DIALOG_H

#include <QDialog>
#include "database_manager.h"

namespace Ui
{
    class AddTicketDialog;
}

class AddTicketDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddTicketDialog(DatabaseManager *dbManager, const QString &brand = "", const QString &model = "", const QString &registrationID = "",  const QString &assignedEmployee = "", QWidget *parent = nullptr);
    ~AddTicketDialog();

signals:
    void addTicket(const QString &brand, const QString &model, const QString &serialNumber, const QString &assignedEmployee);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::AddTicketDialog *ui;
    DatabaseManager *dbManager;
};

#endif // ADD_TICKET_DIALOG_H
