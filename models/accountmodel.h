#ifndef ACCOUNTMODEL_H
#define ACCOUNTMODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include <QVariant>
#include <QDate>

#include <cassert>

class AccountModel : public QAbstractTableModel
{
    enum AccountType {
        BANK_ACCOUNT,
        LOAN,
        CREDIT_CARD,
        MAX_ACCOUNT_TYPES,
    };

public:
    explicit AccountModel(QObject *parent = nullptr);
    ~AccountModel() override;

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;

    bool hasChildren(const QModelIndex &parent) const override;

    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role) override;

    bool insertRows(int row, int count, const QModelIndex &parent) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

private:
    enum TableColumns {
        DATE,
        AMOUNT,
        DESCRIPTION,
        MAX_TABLE_COLUMNS,
    };

    struct Transaction {
        QDate date;
        double amount;
        QString description;
    };

    QVector<Transaction*> mTransactions;
};

#endif // ACCOUNTMODEL_H
