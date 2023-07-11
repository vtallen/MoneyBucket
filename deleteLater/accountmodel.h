#ifndef CUSTOMTABLEMODEL_H
#define CUSTOMTABLEMODEL_H

#include <QAbstractItemModel>
#include <QMainWindow>
#include <QString>
#include <QVector>
#include <QDate>

class AccountModel: public QAbstractTableModel
{
public:
    enum AccountType {
        BANK_ACCOUNT,
        CREDIT_CARD,
    };

    // If column order is changed, these functions will need to be changed as well: AccountModel::addTransaction
    enum Columns {
       DATE,
       DESCRIPTION,
       AMOUNT,
       COLUMNS_MAX,
    };

    enum SortMode {
        DATE_ASCENDING,
        DATE_DESCENDING,
    };

    explicit AccountModel(QObject *parent = nullptr, QString name = "untitled", AccountType accountType = BANK_ACCOUNT);

    // QAbstractItem Interface
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;

    // Getters
    double getBalance();

    // Setters
    void setSort(SortMode sorting);
    void addTransaction(const QDate &date, const QString &description, double amount);
    void removeTransaction(const QModelIndex &index);

    // Functions
    void sort();

private:
    // Members
    QString m_name;
    const AccountType m_accountType;
    QVector<QVector<QVariant>> table;
    SortMode m_sortMode{SortMode::DATE_DESCENDING};

    // Functions
    static bool compareDateAscending(const QVector<QVariant> &vec1, const QVector<QVariant> &vec2);
    static bool compareDateDescending(const QVector<QVariant> &vec1, const QVector<QVariant> &vec2);
};

#endif // CUSTOMTABLEMODEL_H
