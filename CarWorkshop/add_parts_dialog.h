#ifndef ADD_PARTS_DIALOG_H
#define ADD_PARTS_DIALOG_H

#include "database_manager.h"
#include <QDialog>

namespace Ui {
class AddPartsDialog;
}

class AddPartsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddPartsDialog(DatabaseManager *dbManager, const QString &description = "", int amount = 0, double price = 0.0, QWidget *parent = nullptr);
    ~AddPartsDialog();
    void fillFields(const QString &description, int amount, double price);

signals:
    void addPart(const QString &description, int amount, double price, double total);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddPartsDialog *ui;
    DatabaseManager *dbManager;
};

#endif // ADD_PARTS_DIALOG_H
