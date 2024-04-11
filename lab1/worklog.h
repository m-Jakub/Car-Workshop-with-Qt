#ifndef WORKLOG_H
#define WORKLOG_H

#include <QDialog>

namespace Ui {
class Worklog;
}

class Worklog : public QDialog
{
    Q_OBJECT

public:
    explicit Worklog(QWidget *parent = nullptr);
    ~Worklog();

private:
    Ui::Worklog *ui;
};

#endif // WORKLOG_H
