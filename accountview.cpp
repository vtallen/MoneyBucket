#include "accountview.h"
#include "ui_accountview.h"
#include "accountmodel.h"

AccountView::AccountView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountView)
{
    ui->setupUi(this);

    m_model = new AccountModel(this, "AMEX HYSA", AccountModel::BANK_ACCOUNT);
    ui->accountTableView->setModel(m_model);
    ui->accountTableView->resizeColumnsToContents();

    connect(m_model, &QAbstractItemModel::dataChanged, this, &AccountView::transactionAdded);

    transactionAdded();
}

AccountView::~AccountView()
{
    delete ui;

}

void AccountView::transactionAdded() {
    ui->balanceLabel->setText("$" + QString::number(m_model->getBalance()));
}
