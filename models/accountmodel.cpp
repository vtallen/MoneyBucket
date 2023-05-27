#include "accountmodel.h"

AccountModel::AccountModel(QObject *parent, QString name, AccountType accountType)
    : QAbstractTableModel{parent}
    , m_name{name}
    , m_accountType{accountType}
{
    QString date1 = "2004-05-26";

    QString date2 = "2000-07-28";
    QString date3 = "2034-10-26";
    table.append({QDate::fromString(date1, "yyyy-MM-dd"),"Bought snacks","500.66"});
    table.append({QDate::fromString(date2, "yyyy-MM-dd"),"Was not alive","500.66"});
    table.append({QDate::fromString(date3, "yyyy-MM-dd"),"FUTURE","500.66"});
    sortByDate(true);

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
        return AccountModel::Columns::COLUMNS_MAX;
    }

    return 0;
}

QVariant AccountModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        return table.at(index.row()).at(index.column());
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
    else if (value.toString() != "") table[index.row()][index.column()] = value;
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


bool AccountModel::compareDateAscending(const QVector<QVariant> &vec1, const QVector<QVariant> &vec2) {
    QVariant date1 = vec1[0];
    QVariant date2 = vec2[0];

    return date1.toDate() < date2.toDate();
}

bool AccountModel::compareDateDescending(const QVector<QVariant> &vec1, const QVector<QVariant> &vec2) {
    QVariant date1 = vec1[0];
    QVariant date2 = vec2[0];

    return date1.toDate() > date2.toDate();
}

void AccountModel::sortByDate(const bool sortDescending = true) {
    if (sortDescending) std::sort(table.begin(), table.end(), compareDateDescending);
    else std::sort(table.begin(), table.end(), compareDateAscending);
}
