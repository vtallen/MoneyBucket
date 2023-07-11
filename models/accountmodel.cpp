#include "accountmodel.h"

AccountModel::AccountModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    mTransactions.push_back(new Transaction{QDate(2023, 1, 10), 10, "Test Transaction"});
    mTransactions.push_back(new Transaction{QDate(2024, 1, 10), 10, "Test Transaction"});
}

AccountModel::~AccountModel() {
    qDeleteAll(mTransactions);
}

int AccountModel::rowCount(const QModelIndex &parent) const
{
    return mTransactions.size();
}

int AccountModel::columnCount(const QModelIndex &parent) const
{
    return TableColumns::MAX_TABLE_COLUMNS;
}

bool AccountModel::hasChildren(const QModelIndex &parent) const
{
    return false;
}

QVariant AccountModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= mTransactions.count()) return QVariant();

    Transaction *transaction = mTransactions[index.row()];
    assert(transaction && "Transaction was nullptr");

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        if (index.column() == TableColumns::DATE) return transaction->date;
        if (index.column() == TableColumns::AMOUNT) return transaction->amount;
        if (index.column() == TableColumns::DESCRIPTION) return transaction->description;
    }

    return QVariant();
}

bool AccountModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid()) return false;

    Transaction *transaction = mTransactions[index.row()];
    assert(transaction && "AccountModel::setData - transaction was nullptr");
    bool hasChange = false;

    if (role == Qt::EditRole) {
        if (index.column() == DATE) {
            if (transaction->date != value.toDate()) {
                transaction->date = value.toDate();
                hasChange = true;
            }
        } else if (index.column() == AMOUNT) {
            if (transaction->amount != value.toDouble()) {
                transaction->amount = value.toDouble();
                hasChange = true;
            }
        } else if (index.column() == DESCRIPTION) {
            if (transaction->description != value.toString()) {
                transaction->description = value.toString();
                hasChange = true;
            }
        }
    }

    if (hasChange) {
        emit dataChanged(index, index);
        return true;
    }

    return false;
}

QVariant AccountModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case DATE:
            return QString("Date");
        case AMOUNT:
            return QString("Amount");
        case DESCRIPTION:
            return QString("Description");
        }
    }

    return QVariant();
}

bool AccountModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (orientation == Qt::Vertical) {
        mTransactions[section]->date = value.toDate();
    }

    return false;
}



bool AccountModel::insertRows(int row, int count, const QModelIndex &parent)
{

}

Qt::ItemFlags AccountModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()) return QAbstractTableModel::flags(index);

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

