#include "accountmodel.h"

AccountModel::AccountModel(QObject *parent, QString name, AccountType accountType)
    : QAbstractTableModel{parent}
    , m_name{name}
    , m_accountType{accountType}
{
    table.append({"05/25/23","Bought snacks","500.66"});
}

int AccountModel::rowCount(const QModelIndex &parent) const
{
    if(!parent.isValid()) {
        return table.size();
    }
    return 0;
}

int AccountModel::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid()) {
        return NUM_COLUMNS;
    }

    return 0;
}

QVariant AccountModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        return table.at(index.row()).at(index.column());
    } else if ((role == Qt::DecorationRole) && (index.column() == 6)) {
        return QColor{table.at(index.row()).at(index.column())};
    }
    return QVariant{};
}

QVariant AccountModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        switch (section) {
        case 0:
            return "Date";
        case 1:
            return "Description";
        case 2:
            return "Amount";
        default:
            return "";
        }
    }
    return QVariant{};
}

bool AccountModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!(role == Qt::EditRole)) return false;
    else if (value.toString() != "") table[index.row()][index.column()] = value.toString();
    else return false;

    emit dataChanged(index, index);
    return true;
}

Qt::ItemFlags AccountModel::flags(const QModelIndex &index) const
{
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

double AccountModel::getBalance() {
    double balance{};
    for (int i{0}; i < table.size(); ++i) {
        balance += table[i][2].toDouble();
    }
    return balance;
}
