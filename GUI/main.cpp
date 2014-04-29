#include <QApplication>
#include <QIcon>
#include "mainwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QIcon ic(":/ic.ico");
    QApplication::setWindowIcon(ic);
    MainWidget mainWidget;
    mainWidget.show();

    return a.exec();
}
