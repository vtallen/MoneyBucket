#include "accountstablemodel.h"

AccountsTableModel::AccountsTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int AccountsTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int AccountsTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant AccountsTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
