#ifndef TICKETS_H
#define TICKETS_H

#include "database_manager.h"
#include "add_ticket_dialog.h"
#include "calendar.h"
#include <QWidget>
#include <QTableWidgetItem>

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
    void changeButtonsState(bool state);
    void setupTable();
    void populateTable();

signals:
    void ticketsUpdated();

private slots:
    void on_deleteButton_clicked();
    void on_addButton_clicked();
    void on_updateButton_clicked();
    void on_calendarButton_clicked();
    void onTableRowClicked(QTableWidgetItem *item);
    void on_stateComboBox_activated(int index);
    void on_estimateButton_clicked();
    void on_partsButton_clicked();
    void on_assignEmployeeButton_clicked();

private:
    Ui::Tickets *ui;
    DatabaseManager *dbManager;
    QHash<int, int> rowToIdMap;
    QHash<int, int> rowToEmployeeIDMap;
    AddTicketDialog *dialogWindow = nullptr;
    Calendar *calendar = nullptr;
    static int lastAddedTicketID;
};

#endif // TICKETS_H
