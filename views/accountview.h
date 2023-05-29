#ifndef ACCOUNTVIEW_H
#define ACCOUNTVIEW_H

#include <QWidget>
#include <QItemSelectionModel>

#include "../models/accountmodel.h"

namespace Ui {
class AccountView;
}

class AccountView : public QWidget
{
    Q_OBJECT

public:
    explicit AccountView(QWidget *parent = nullptr);
    ~AccountView();

private slots:
    void modelDataChanged();
    void addButtonClicked();
    void removeButtonClicked();

private:
    Ui::AccountView *ui;

    AccountModel *m_model{};
    QItemSelectionModel *m_selectionModel{};
};

#endif // ACCOUNTVIEW_H
