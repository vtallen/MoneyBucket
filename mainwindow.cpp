#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_centralWidget = new QWidget(this);
    QHBoxLayout *HBox = new QHBoxLayout(m_centralWidget);

    m_sideBar = new Sidebar(this);
    HBox->addWidget(m_sideBar);

    m_accountView = new AccountView(this);
    HBox->addWidget(m_accountView);

    setCentralWidget(m_centralWidget);
    HBox->children();




}

MainWindow::~MainWindow()
{
    delete ui;
}

