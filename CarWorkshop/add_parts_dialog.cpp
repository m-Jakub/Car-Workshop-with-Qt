#include "add_parts_dialog.h"
#include "ui_add_parts_dialog.h"

AddPartsDialog::AddPartsDialog(DatabaseManager *dbManager, const QString &description, int amount, double price, QWidget *parent)
    : QDialog(parent), ui(new Ui::AddPartsDialog), dbManager(dbManager)
{
    ui->setupUi(this);
    setWindowTitle("Car Workshop Management System");
    fillFields(description, amount, price);
}

AddPartsDialog::~AddPartsDialog()
{
    delete ui;
}

void AddPartsDialog::fillFields(const QString &description, int amount, double price)
{
    ui->descriptionLineEdit->setText(description);
    ui->amountSpinBox->setValue(amount);
    ui->priceDoubleSpinBox->setValue(price);
}

void AddPartsDialog::on_buttonBox_accepted()
{
    QString description = ui->descriptionLineEdit->text();
    int amount = ui->amountSpinBox->value();
    double price = ui->priceDoubleSpinBox->value();


    emit addPart(description, amount, price, amount * price);

    close();
}
