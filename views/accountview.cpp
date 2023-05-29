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
    ui->accountTableView->setSelectionMode(QAbstractItemView::SingleSelection);

    connect(m_model, &QAbstractItemModel::dataChanged, this, &AccountView::modelDataChanged);

    connect(ui->addButton, &QPushButton::clicked, this, &AccountView::addButtonClicked);
    connect(ui->removeButton, &QPushButton::clicked, this, &AccountView::removeButtonClicked);
    modelDataChanged();
}

AccountView::~AccountView()
{
    delete ui;

}

void AccountView::modelDataChanged() {
    ui->balanceLabel->setText("$" + QString::number(m_model->getBalance()));
}

void AccountView::addButtonClicked() {
    TransactionDialog dialog(this);

    if (dialog.exec() == QDialog::Accepted) {
        if (dialog.date.isValid()) m_model->addTransaction(dialog.date, dialog.description, dialog.amount);
    }
}

void AccountView::removeButtonClicked() {
    if (!ui->accountTableView->selectionModel()->hasSelection()) return;

    // If there is a selection, we know there is only one since the selection mode was set for the table view
    auto selectedIndexes {ui->accountTableView->selectionModel()->selectedIndexes()};
    m_model->removeTransaction(selectedIndexes.at(0));

}
