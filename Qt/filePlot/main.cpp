#include "plotfile.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    plotFile w;
    w.show();
    return a.exec();
}
