#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QStandardItemModel>

#include "ui/sidebar.h"
#include "views/accountview.h"

#include "models/accounttree.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QWidget *m_centralWidget{};
    Sidebar *m_sideBar{};
    AccountView *m_accountView{};
};
#endif // MAINWINDOW_H
