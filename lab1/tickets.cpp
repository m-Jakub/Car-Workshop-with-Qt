#include "tickets.h"
#include "ui_tickets.h"
#include "database_manager.h"
#include "delete_confirmation_dialog.h"
#include <QSqlQuery>

Tickets::Tickets(DatabaseManager *dbManager, QWidget *parent)
    : QWidget(parent), ui(new Ui::Tickets), dbManager(dbManager)
{
    ui->setupUi(this);

    setupTable();
    populateTable();
}

Tickets::~Tickets()
{
    delete ui;
}

void Tickets::setupTable()
{
    //     int addTicket(const QString& vehicleBrand, const QString& vehicleModel, const QString& registrationID, const QString& problemDescription, int assignedEmployeeID, double pricePaidByClient, const QString& state);

    // Setting column names
    QStringList headerLabels;
    headerLabels << "Brand"
                 << "Model"
                 << "Registration"
                 << "Problem Description"
                 << "Assigned Employee"
                 << "Price Paid"
                 << "State";
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);

    // Resizing columns
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    // Setting selection behavior to select the whole row
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Setting the window title
    setWindowTitle("Tickets - Car Workshop Management System");

    // Making the table read-only
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void Tickets::populateTable()
{
    QSqlQuery query("SELECT TicketId, VehicleBrand, VehicleModel, RegistrationID, ProblemDescription, AssignedEmployeeID, PricePaidByClient, State FROM Tickets");
    while (query.next())
    {
        int id = query.value(0).toInt();
        QString brand = query.value(1).toString();
        QString model = query.value(2).toString();
        QString registration = query.value(3).toString();
        QString problemDescription = query.value(4).toString();
        int assignedEmployeeID = query.value(5).toInt();
        QString assignedEmployeeName = dbManager->getEmployeeName(assignedEmployeeID);
        double pricePaid = query.value(6).toDouble();
        QString state = query.value(7).toString();

        QTableWidgetItem *brandItem = new QTableWidgetItem(brand);
        QTableWidgetItem *modelItem = new QTableWidgetItem(model);
        QTableWidgetItem *registrationItem = new QTableWidgetItem(registration);
        QTableWidgetItem *problemDescriptionItem = new QTableWidgetItem(problemDescription);
        QTableWidgetItem *assignedEmployeeItem = new QTableWidgetItem(assignedEmployeeName);
        QTableWidgetItem *pricePaidItem = new QTableWidgetItem(QString::number(pricePaid));
        QTableWidgetItem *stateItem = new QTableWidgetItem(state);

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, brandItem);
        ui->tableWidget->setItem(row, 1, modelItem);
        ui->tableWidget->setItem(row, 2, registrationItem);
        ui->tableWidget->setItem(row, 3, problemDescriptionItem);
        ui->tableWidget->setItem(row, 4, assignedEmployeeItem);
        ui->tableWidget->setItem(row, 5, pricePaidItem);
        ui->tableWidget->setItem(row, 6, stateItem);

        // Storing the ID in the rowToIdMap
        rowToIdMap[row] = id;
    }
}
// oid Employees::on_addButton_clicked()
// {
//     // Instantiating the AddEmployeeDialog
//     if (!dialogWindow)
//         dialogWindow = new AddEmployeeDialog(dbManager);

//     // Connecting the addEmployee signal to a slot that adds the employee to the table
//     connect(dialogWindow, &AddEmployeeDialog::addEmployee, this, [=](const QString &name, double hourlyRate)
//             {
//         // Inserting the employee into the database
//         int id = dbManager->addEmployee(name, hourlyRate);

//         // Inserting the employee into the tableWidget
//         int row = ui->tableWidget->rowCount();
//         ui->tableWidget->insertRow(row);
//         ui->tableWidget->setItem(row, 0, new QTableWidgetItem(name));
//         ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(hourlyRate)));

//         // Storing the ID in the rowToIdMap
//         rowToIdMap[row] = id; });

//     // Displaying the addEmployeeWindow
//     dialogWindow->exec();
// }

void Tickets::on_addButton_clicked()
{
    if (!dialogWindow)
        dialogWindow = new AddTicketDialog(dbManager);

    connect(dialogWindow, &AddTicketDialog::addTicket, this, [=](const QString &brand, const QString &model, const QString &registration, int assignedEmployeeID)
            {
        // Inserting the ticket into the database
        int id = dbManager->addTicket(brand, model, registration, "problemDescription", assignedEmployeeID, 0, "state");

        // Inserting the ticket into the tableWidget
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(brand));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(model));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(registration));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem("problemDescription"));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(dbManager->getEmployeeName(assignedEmployeeID)));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(0)));
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem("state"));

        // Storing the ID in the rowToIdMap
        rowToIdMap[row] = id; });

    dialogWindow->exec();
}
