#ifndef TICKETS_H
#define TICKETS_H

#include <QWidget>

namespace Ui {
class Tickets;
}

class Tickets : public QWidget
{
    Q_OBJECT

public:
    explicit Tickets(QWidget *parent = nullptr);
    ~Tickets();

private:
    Ui::Tickets *ui;
};

#endif // TICKETS_H
