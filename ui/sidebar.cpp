#include "sidebar.h"
#include "ui_sidebar.h"

Sidebar::Sidebar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sidebar)
{
    ui->setupUi(this);
    AccountTreeModel *model = new AccountTreeModel("TEST", this);
    ui->accountsTreeView->setModel(model);
}

Sidebar::~Sidebar()
{
    delete ui;
}
