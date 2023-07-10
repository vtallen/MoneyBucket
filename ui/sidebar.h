#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <QWidget>
#include <QStandardItemModel>

#include "../models/accounttree.h"

namespace Ui {
class Sidebar;
}

class Sidebar : public QWidget
{
    Q_OBJECT

public:
    explicit Sidebar(QWidget *parent = nullptr);
    ~Sidebar();

private:
    Ui::Sidebar *ui;
};

#endif // SIDEBAR_H
