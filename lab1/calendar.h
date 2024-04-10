#ifndef CALENDAR_H
#define CALENDAR_H

#include "database_manager.h"
#include <QDialog>

namespace Ui {
class Calendar;
}

class Calendar : public QDialog
{
    Q_OBJECT

public:
    explicit Calendar(DatabaseManager *dbManager, int ticketID, int employeeID, QWidget *parent = nullptr);
    void setupTable();
    void populateTable();
    ~Calendar();

signals:
    void addRepairSchedule(const QString &startHour, const QString &endHour, const QString &day);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    // void on_tableWidget_cellActivated(int row, int column);

private:
    Ui::Calendar *ui;
    DatabaseManager *dbManager;
    int ticketID;
    int employeeID;
};

#endif // CALENDAR_H
