#include "include/plotnetworkdata.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    plotNetworkData w;
    w.show();
    return a.exec();
}
