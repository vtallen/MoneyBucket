#ifndef ACCOUNTVIEW_H
#define ACCOUNTVIEW_H

#include <QWidget>
#include "accountmodel.h"

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
    void transactionAdded();

private:
    Ui::AccountView *ui;

    AccountModel *m_model{};
};

#endif // ACCOUNTVIEW_H
