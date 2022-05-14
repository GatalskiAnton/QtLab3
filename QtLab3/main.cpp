#include "mainwidget.h"
#include "widget.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
   /* MainWidget w;
    w.resize(800, 700);
    w.setWindowTitle("Function Graph");
    w.show();*/

    Widget wd;
    wd.show();
    wd.resize(1000, 600);
    wd.setWindowTitle("Hello!!!");

    return a.exec();
}