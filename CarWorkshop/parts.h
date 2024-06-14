#ifndef PARTS_H
#define PARTS_H

#include "database_manager.h"
#include "add_parts_dialog.h"
#include <QDialog>

namespace Ui
{
    class Parts;
}

class Parts : public QDialog
{
    Q_OBJECT

public:
    explicit Parts(DatabaseManager *dbManager, int ticketID, QWidget *parent = nullptr);
    ~Parts();
    void setupTable();
    void populateTable();

private slots:
    void on_deleteButton_clicked();
    void on_addButton_clicked();
    void on_updateButton_clicked();

private:
    Ui::Parts *ui;
    DatabaseManager *dbManager;
    QHash<int, int> rowToIdMap;
    AddPartsDialog *dialogWindow = nullptr;
    int ticketID;
};

#endif // PARTS_H
