#ifndef CUSTOMTABLEMODEL_H
#define CUSTOMTABLEMODEL_H

#include <QAbstractItemModel>
#include <QMainWindow>
#include <QString>
#include <QVector>

class AccountModel: public QAbstractTableModel
{
public:
    enum AccountType {
        BANK_ACCOUNT,
        CREDIT_CARD,
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

private:
    static constexpr int NUM_COLUMNS{3};
    QString m_name;
    const AccountType m_accountType;
    QVector<QVector<QString>> table;

};

#endif // CUSTOMTABLEMODEL_H
