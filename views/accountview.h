#ifndef ACCOUNTVIEW_H
#define ACCOUNTVIEW_H

#include <QWidget>
#include <QItemSelectionModel>


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

};

#endif // ACCOUNTVIEW_H
