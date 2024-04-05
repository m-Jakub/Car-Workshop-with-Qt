#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include <QWidget>

namespace Ui
{
    class Employees;
}

class Employees : public QWidget
{
    Q_OBJECT

public:
    explicit Employees(QWidget *parent = nullptr);
    ~Employees();
    void setupTable();

private slots:
    void on_Delete_clicked();

private:
    Ui::Employees *ui;
};

#endif // EMPLOYEES_H
