#ifndef ACCOUNT_TREE_ITEM
#define ACCOUNT_TREE_ITEM

#include <QList>
#include <QVariant>

class AccountTreeItem
{
public:
    explicit AccountTreeItem(const QList<QVariant> &data, AccountTreeItem *parentItem = nullptr);
    ~AccountTreeItem();

    void appendChild(AccountTreeItem *child);

    AccountTreeItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    AccountTreeItem *parentItem();

private:
    QList<AccountTreeItem *> m_childItems;
    QList<QVariant> m_itemData;
    AccountTreeItem *m_parentItem;
};

#endif
