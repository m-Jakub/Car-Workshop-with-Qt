#ifndef TICKETS_H
#define TICKETS_H

#include "database_manager.h"
#include "add_ticket_dialog.h"
#include <QWidget>

namespace Ui
{
    class Tickets;
}

class Tickets : public QWidget
{
    Q_OBJECT

public:
    explicit Tickets(DatabaseManager *dbManager, QWidget *parent = nullptr);
    ~Tickets();
    void setupTable();
    void populateTable();

signals:
    void ticketsUpdated();

private slots:
    void on_deleteButton_clicked();
    void on_addButton_clicked();
    void on_updateButton_clicked();

private:
    Ui::Tickets *ui;
    DatabaseManager *dbManager;
    QHash<int, int> rowToIdMap;
    AddTicketDialog *dialogWindow = nullptr;
};

#endif // TICKETS_H
