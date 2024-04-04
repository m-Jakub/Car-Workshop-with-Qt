#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employees.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Car Workshop Management System");
}

MainWindow::~MainWindow()
{
    delete ui;
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
        employeesWindow = new Employees();

    if (employeesWindow && employeesWindow->isMinimized())
        employeesWindow->showNormal(); // Unminimising the window
    else
        employeesWindow->show();
    employeesWindow->raise();          // Bringing the window to the front
    employeesWindow->activateWindow(); // Activating the window
}
