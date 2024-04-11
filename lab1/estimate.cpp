#include "estimate.h"
#include "ui_estimate.h"
#include "database_manager.h"
#include <QPushButton>
#include <QSqlQuery>
#include <QSqlError>
#include <QPdfWriter>
#include <QPainter>
#include <QWidget>
#include <QFileDialog>

Estimate::Estimate(DatabaseManager *dbManager, int ticketID, QWidget *parent)
    : QDialog(parent), ui(new Ui::Estimate), dbManager(dbManager), ticketID(ticketID)
{
    ui->setupUi(this);

    // Filling the fields with the ticket's details
    fillFields();

    // Setting accept button name
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Save");
}

Estimate::~Estimate()
{
    delete ui;
}

void Estimate::fillFields()
{
    QSqlQuery query;
    query.prepare("SELECT Description, ExpectedCost, AcceptedByClient FROM Estimates WHERE TicketID = :ticketID");
    query.bindValue(":ticketID", ticketID);
    if (!query.exec())
    {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    if (query.next())
    {
        ui->description->setText(query.value(0).toString());
        ui->expectedCost->setValue(query.value(1).toDouble());
        bool accepted = query.value(2).toBool();
        int index = accepted ? 1 : 0;
        ui->acceptedByClient->setCurrentIndex(index);
    }
}

void Estimate::saveEstimateAsPDF()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as PDF", "", "PDF files (*.pdf)");
    if (fileName.isEmpty())
        return;

    QPdfWriter pdfWriter(fileName);

    // Setting document properties
    pdfWriter.setCreator("Car Workshop Management System");

    QPainter painter(&pdfWriter);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // Printing Description to text
    painter.drawText(100, 100, "Description:");
    painter.drawText(1000, 100, ui->description->toPlainText());
    
    // Printing Expected Cost below
    painter.drawText(100, 500, "Expected Cost:");
    painter.drawText(1200, 500, (QString::number(ui->expectedCost->value()) + " $"));
    

    // Printing Accepted By Client
    painter.drawText(100, 900, "Accepted By Client:");
    painter.drawText(1500, 900, ui->acceptedByClient->currentText());
}

void Estimate::on_buttonBox_accepted()
{
    if (dbManager->estimateExists(ticketID))
        dbManager->updateEstimate(ticketID, ui->description->toPlainText(), ui->expectedCost->value(), ui->acceptedByClient->currentIndex());

    else
        dbManager->addEstimate(ticketID, ui->description->toPlainText(), ui->expectedCost->value(), ui->acceptedByClient->currentIndex());
}

void Estimate::on_pushButton_clicked()
{
    saveEstimateAsPDF();
}

