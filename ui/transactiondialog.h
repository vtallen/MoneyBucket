#ifndef TRANSACTIONDIALOG_H
#define TRANSACTIONDIALOG_H

#include <QDialog>
#include <QString>
#include <QDate>

namespace Ui {
class TransactionDialog;
}

class TransactionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TransactionDialog(QWidget *parent = nullptr);
    ~TransactionDialog();

    QDate date;
    QString description;
    double amount;

private:
    Ui::TransactionDialog *ui;

private slots:
    void dateChanged();
    void descriptionChanged();
    void amountChanged();
};

#endif // TRANSACTIONDIALOG_H
