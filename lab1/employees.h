#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include <QDockWidget>

namespace Ui {
class Employees;
}

class Employees : public QDockWidget
{
    Q_OBJECT

public:
    explicit Employees(QWidget *parent = nullptr);
    ~Employees();

private:
    Ui::Employees *ui;
};

#endif // EMPLOYEES_H
