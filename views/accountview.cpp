#include "accountview.h"
#include "ui_accountview.h"
#include "../models/accountmodel.h"
#include "../ui/transactiondialog.h"

AccountView::AccountView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountView)
{
    ui->setupUi(this);

    m_model = new AccountModel(this, "AMEX HYSA", AccountModel::BANK_ACCOUNT);
    ui->accountTableView->setModel(m_model);
    ui->accountTableView->resizeColumnsToContents();

    connect(m_model, &QAbstractItemModel::dataChanged, this, &AccountView::transactionAdded);

    connect(ui->addButton, &QPushButton::clicked, this, &AccountView::addButtonClicked);
    transactionAdded();
}

AccountView::~AccountView()
{
    delete ui;

}

void AccountView::transactionAdded() {
    ui->balanceLabel->setText("$" + QString::number(m_model->getBalance()));
}

void AccountView::addButtonClicked() {
    TransactionDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        qDebug() << "Accepted";
    }
}
