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
    explicit Calendar(DatabaseManager *dbManager, QWidget *parent = nullptr);
    void setupTable();
    ~Calendar();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

    void on_tableWidget_cellActivated(int row, int column);

private:
    Ui::Calendar *ui;
    DatabaseManager *dbManager;
};

#endif // CALENDAR_H
