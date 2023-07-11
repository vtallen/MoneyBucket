#include "accounttree.h"
AccountTreeModel::AccountTreeModel(const QString &data, QObject *parent)
    : QAbstractItemModel(parent)
{
    rootItem = new AccountTreeItem({tr("Account"), tr("Balance")});

    AccountTreeItem *bankAccounts = new AccountTreeItem({"Bank Accounts", "---"}, rootItem);
    AccountTreeItem *creditCards = new AccountTreeItem({"Credit Cards", "---"}, rootItem);
    AccountTreeItem *loans = new AccountTreeItem({"Loans", "---"}, rootItem);
    rootItem->appendChild(bankAccounts);
    rootItem->appendChild(creditCards);
    rootItem->appendChild(loans);
}

AccountTreeModel::~AccountTreeModel()
{
    delete rootItem;
}

QModelIndex AccountTreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    AccountTreeItem *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<AccountTreeItem*>(parent.internalPointer());

    AccountTreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    return QModelIndex();
}

QModelIndex AccountTreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    AccountTreeItem *childItem = static_cast<AccountTreeItem*>(index.internalPointer());
    AccountTreeItem *parentItem = childItem->parentItem();
    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

int AccountTreeModel::rowCount(const QModelIndex &parent) const
{
    AccountTreeItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<AccountTreeItem*>(parent.internalPointer());

    return parentItem->childCount();
}

int AccountTreeModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return static_cast<AccountTreeItem*>(parent.internalPointer())->columnCount();
    return rootItem->columnCount();
}

QVariant AccountTreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    AccountTreeItem *item = static_cast<AccountTreeItem*>(index.internalPointer());

    return item->data(index.column());
}

Qt::ItemFlags AccountTreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index);
}

QVariant AccountTreeModel::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}
