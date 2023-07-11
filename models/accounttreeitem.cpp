#include "accounttreeitem.h"

AccountTreeItem::AccountTreeItem(const QList<QVariant> &data, AccountTreeItem *parent)
    : m_itemData(data), m_parentItem(parent)
{}

AccountTreeItem::~AccountTreeItem()
{
    qDeleteAll(m_childItems);
}

void AccountTreeItem::appendChild(AccountTreeItem *item)
{
    m_childItems.append(item);
}

AccountTreeItem *AccountTreeItem::child(int row)
{
    if (row < 0 || row >= m_childItems.size())
        return nullptr;
    return m_childItems.at(row);
}

int AccountTreeItem::childCount() const
{
    return m_childItems.count();
}

int AccountTreeItem::row() const
{
    if (m_parentItem)
        return m_parentItem->m_childItems.indexOf(const_cast<AccountTreeItem*>(this));

    return 0;
}

int AccountTreeItem::columnCount() const
{
    return m_itemData.count();
}

QVariant AccountTreeItem::data(int column) const
{
    if (column < 0 || column >= m_itemData.size())
        return QVariant();
    return m_itemData.at(column);
}

AccountTreeItem *AccountTreeItem::parentItem()
{
    return m_parentItem;
}
