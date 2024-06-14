#include "parts.h"
#include "ui_parts.h"
#include "database_manager.h"
#include "delete_confirmation_dialog.h"
#include "add_parts_dialog.h"
#include <QSqlQuery>
#include <QSqlError>

// if (!query.exec("CREATE TABLE IF NOT EXISTS Parts ("
//                 "PartID INTEGER PRIMARY KEY,"
//                 "TicketID INTEGER NOT NULL,"
//                 "Description TEXT NOT NULL,"
//                 "Amount DECIMAL(10, 2) NOT NULL,"
//                 "UnitPrice DECIMAL(10, 2) NOT NULL,"
//                 "TotalPrice DECIMAL(10, 2) GENERATED ALWAYS AS (Amount * UnitPrice) VIRTUAL,"
//                 "FOREIGN KEY (TicketID) REFERENCES Tickets(TicketID)"
//                 ");"))
// {
//     qDebug() << "Error: Failed to create Parts table:" << query.lastError().text();
//     m_db.close();
//     return false;
// }

Parts::Parts(DatabaseManager *dbManager, int ticketID, QWidget *parent)
    : QDialog(parent), ui(new Ui::Parts), dbManager(dbManager), ticketID(ticketID)
{
    ui->setupUi(this);

    setupTable();
    populateTable();
}

Parts::~Parts()
{
    delete ui;
}

void Parts::setupTable()
{
    // Setting column names
    QStringList headerLabels;
    headerLabels << "Name/Description"
                 << "Amount"
                 << "Unit price [$]"
                 << "Total price [$]";
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);

    // Resizing columns
    ui->tableWidget->setColumnWidth(0, 150);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    // Setting selection behavior to select the whole row
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Setting the window title
    setWindowTitle("Parts - Car Workshop Management System");

    // Making the table read-only
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void Parts::populateTable()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    QSqlQuery query;
    query.prepare("SELECT PartID, Description, Amount, UnitPrice, TotalPrice FROM Parts WHERE TicketID = :ticketID");
    query.bindValue(":ticketID", ticketID);
    if (!query.exec())
    {
        qDebug() << "Error: Failed to fetch parts:" << query.lastError().text();
        return;
    }

    while (query.next())
    {
        int id = query.value(0).toInt();
        QString description = query.value(1).toString();
        int amount = query.value(2).toInt();
        double unitPrice = query.value(3).toDouble();
        double totalPrice = query.value(4).toDouble();

        QTableWidgetItem *descriptionItem = new QTableWidgetItem(description);
        QTableWidgetItem *amountItem = new QTableWidgetItem(QString::number(amount));
        QTableWidgetItem *unitPriceItem = new QTableWidgetItem(QString::number(unitPrice, 'f', 2));
        QTableWidgetItem *totalPriceItem = new QTableWidgetItem(QString::number(totalPrice, 'f', 2));

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, descriptionItem);
        ui->tableWidget->setItem(row, 1, amountItem);
        ui->tableWidget->setItem(row, 2, unitPriceItem);
        ui->tableWidget->setItem(row, 3, totalPriceItem);

        rowToIdMap[row] = id;
    }
}

void Parts::on_deleteButton_clicked()
{
    int selectedRow = ui->tableWidget->currentRow();
    if (selectedRow >= 0)
    {
        QString description = ui->tableWidget->item(selectedRow, 0)->text();
        DeleteConfirmationDialog dialog(description);

        connect(&dialog, &DeleteConfirmationDialog::deleteConfirmed, this, [=]()
                {
            int partID = rowToIdMap.value(selectedRow);
            dbManager->removeParts(partID);
            ui->tableWidget->removeRow(selectedRow);
            rowToIdMap.remove(selectedRow); });
        dialog.exec();
    }
}

void Parts::on_addButton_clicked()
{
    dialogWindow = new AddPartsDialog(dbManager);

    connect(dialogWindow, &AddPartsDialog::addPart, this, [=](const QString &description, int amount, double unitPrice)
            {
        int id = dbManager->addParts(ticketID, description, amount, unitPrice);

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(description));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(amount)));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(unitPrice, 'f', 2)));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(amount * unitPrice, 'f', 2)));

        rowToIdMap[row] = id; });

    dialogWindow->exec();
}

void Parts::on_updateButton_clicked()
{
    int selectedRow = ui->tableWidget->currentRow();

    dialogWindow = new AddPartsDialog(dbManager, ui->tableWidget->item(selectedRow, 0)->text(), ui->tableWidget->item(selectedRow, 1)->text().toInt(), ui->tableWidget->item(selectedRow, 2)->text().toDouble());

    connect(dialogWindow, &AddPartsDialog::addPart, this, [=](const QString &description, int amount, double unitPrice)
            {
                int partID = rowToIdMap.value(selectedRow);
                dbManager->updateParts(partID, description, amount, unitPrice);

                ui->tableWidget->setItem(selectedRow, 0, new QTableWidgetItem(description));
                ui->tableWidget->setItem(selectedRow, 1, new QTableWidgetItem(QString::number(amount)));
                ui->tableWidget->setItem(selectedRow, 2, new QTableWidgetItem(QString::number(unitPrice, 'f', 2)));
                ui->tableWidget->setItem(selectedRow, 3, new QTableWidgetItem(QString::number(amount * unitPrice, 'f', 2)));
            });

    dialogWindow->exec();
}
