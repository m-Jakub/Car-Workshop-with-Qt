#ifndef ESTIMATE_H
#define ESTIMATE_H

#include <database_manager.h>
#include <QDialog>

namespace Ui {
class Estimate;
}

class Estimate : public QDialog
{
    Q_OBJECT

public:
    explicit Estimate(DatabaseManager *dbmanager, int ticketID, QWidget *parent = nullptr);
    ~Estimate();
    void fillFields();

signals:
    void estimateUpdated();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Estimate *ui;
    DatabaseManager *dbManager;
    int ticketID;
};

#endif // ESTIMATE_H
