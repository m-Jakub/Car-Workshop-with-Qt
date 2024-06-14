// delete_confirmation_dialog.h
#ifndef DELETE_CONFIRMATION_DIALOG_H
#define DELETE_CONFIRMATION_DIALOG_H

#include <QDialog>

namespace Ui
{
    class DeleteConfirmationDialog;
}

class DeleteConfirmationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteConfirmationDialog(const QString &itemName, QWidget *parent = nullptr);
    ~DeleteConfirmationDialog();

signals:
    void deleteConfirmed();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::DeleteConfirmationDialog *ui;
};

#endif // DELETE_CONFIRMATION_DIALOG_H
