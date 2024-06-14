#include "mainwindow.h"
#include "ui_mainwindow.h"
// #include "../build-lab1-Desktop_Qt_6_6_2_MinGW_64_bit-Debug/ui_mainwindow.h"

MainWindow::MainWindow(DatabaseManager *dbManager, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), dbManager(dbManager)
{
    ui->setupUi(this);
    setWindowTitle("Car Workshop Management System");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    // Close all top-level widgets except the main window
    QWidgetList topLevelWidgets = QApplication::topLevelWidgets();
    for (auto widget : topLevelWidgets)
    {
        if (widget != this)
        {
            widget->close();
        }
    }

    // Call the default close event handling
    QMainWindow::closeEvent(event);
}

void MainWindow::updateTables()
{
    if (employeesWindow)
        employeesWindow->populateTable();

    if (ticketsWindow)
        ticketsWindow->populateTable();
}

void MainWindow::on_Exit_clicked()
{
    QWidgetList topLevelWidgets = QApplication::topLevelWidgets();
    for (auto widget : topLevelWidgets)
    {
        widget->close();
    }

    qApp->exit();
}

void MainWindow::on_Employees_clicked()
{
    if (!employeesWindow)
    {
        employeesWindow = new Employees(dbManager);
        connect(employeesWindow, &Employees::employeesUpdated, this, &MainWindow::updateTables); // Connected to update the table widgets when the employees are updated
    }

    if (employeesWindow && employeesWindow->isMinimized())
        employeesWindow->showNormal();
    else
        employeesWindow->show();
    employeesWindow->raise();
    employeesWindow->activateWindow();
}

void MainWindow::on_Tickets_clicked()
{
    if (!ticketsWindow)
    {
        ticketsWindow = new Tickets(dbManager);
        connect(ticketsWindow, &Tickets::ticketsUpdated, this, &MainWindow::updateTables);
    }

    if (ticketsWindow && ticketsWindow->isMinimized())
        ticketsWindow->showNormal();
    else
        ticketsWindow->show();
    ticketsWindow->raise();
    ticketsWindow->activateWindow();
}
