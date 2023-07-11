/*
 * TODO
 *	un-hardcode column numbers for data so that different subclasses of accountmodel could place the columns at different positions
 *		** pOlYmOrPhIsM fUn**
 */


#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
