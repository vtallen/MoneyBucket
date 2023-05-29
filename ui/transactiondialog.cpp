#include "transactiondialog.h"
#include "ui_transactiondialog.h"

TransactionDialog::TransactionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransactionDialog)
{
    ui->setupUi(this);
    setWindowTitle("Add Transaction");

    connect(ui->dateEdit, &QDateEdit::dateChanged, this, &TransactionDialog::dateChanged);
    connect(ui->descriptionTextEdit, &QTextEdit::textChanged, this, &TransactionDialog::descriptionChanged);
    connect(ui->amountSpinBox, &QDoubleSpinBox::valueChanged, this, &TransactionDialog::amountChanged);
}

TransactionDialog::~TransactionDialog()
{
    delete ui;
}

void TransactionDialog::dateChanged() {
    date = ui->dateEdit->date();
}

void TransactionDialog::descriptionChanged() {
    description = ui->descriptionTextEdit->toPlainText();
}

void TransactionDialog::amountChanged() {
    amount = ui->amountSpinBox->value();
}
