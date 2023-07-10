#ifndef ACCOUNT_TREE_H
#define ACCOUNT_TREE_H
#include <QAbstractItemModel>
#include <QList>
#include "accountmodel.h"

class TreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit TreeModel(const QString &data, QObject *parent = nullptr);
    ~TreeModel();

    QVariant data(const QModelIndex &index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

private:
    void setupModelData();

    TreeItem *rootItem;
};

#endif
