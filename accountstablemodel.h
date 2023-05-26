#ifndef ACCOUNTSTABLEMODEL_H
#define ACCOUNTSTABLEMODEL_H

#include <QAbstractTableModel>

class AccountsTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit AccountsTableModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};

#endif // ACCOUNTSTABLEMODEL_H
