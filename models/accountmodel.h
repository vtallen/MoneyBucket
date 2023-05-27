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

    enum Columns {
       DATE,
       DESCRIPTION,
       AMOUNT,
       COLUMNS_MAX,
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

    // Functions
    void sortByDate(bool sortDescending);

private:
    // Members
    QString m_name;
    const AccountType m_accountType;
    QVector<QVector<QVariant>> table;

    // Functions
    static bool compareDateAscending(const QVector<QVariant> &vec1, const QVector<QVariant> &vec2);
    static bool compareDateDescending(const QVector<QVariant> &vec1, const QVector<QVariant> &vec2);
};

#endif // CUSTOMTABLEMODEL_H
