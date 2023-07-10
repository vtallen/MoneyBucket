#include "accountview.h"
#include "ui_accountview.h"
#include "../ui/transactiondialog.h"

AccountView::AccountView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountView)
{
    ui->setupUi(this);

    connect(ui->addButton, &QPushButton::clicked, this, &AccountView::addButtonClicked);
    connect(ui->removeButton, &QPushButton::clicked, this, &AccountView::removeButtonClicked);
    modelDataChanged();
}

AccountView::~AccountView()
{
    delete ui;

}

void AccountView::modelDataChanged() {
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
