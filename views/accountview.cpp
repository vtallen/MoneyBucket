#include "accountview.h"
#include "ui_accountview.h"

#include "../ui/transactiondialog.h"

AccountView::AccountView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountView)
{
    ui->setupUi(this);

    AccountModel *model = new AccountModel(this);

    ui->accountTableView->setModel(model);

    connect(ui->addButton, &QPushButton::clicked, this, &AccountView::addButtonClicked);
    connect(ui->removeButton, &QPushButton::clicked, this, &AccountView::removeButtonClicked);

    connect(model, &AccountModel::dataChanged, this, &AccountView::modelDataChanged);
    modelDataChanged();
}

AccountView::~AccountView()
{
    delete ui;

}

void AccountView::modelDataChanged() {
    QHeaderView *header = ui->accountTableView->horizontalHeader();

    header->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(2, QHeaderView::Stretch);

    QHeaderView *vert = ui->accountTableView->verticalHeader();
    vert->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void AccountView::addButtonClicked() {
    TransactionDialog dialog(this);

    if (dialog.exec() == QDialog::Accepted) {

    }
}

void AccountView::removeButtonClicked() {
    if (!ui->accountTableView->selectionModel()->hasSelection()) return;

    // If there is a selection, we know there is only one since the selection mode was set for the table view
    auto selectedIndexes {ui->accountTableView->selectionModel()->selectedIndexes()};
}
