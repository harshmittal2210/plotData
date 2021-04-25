#include "plotnetworkdata.h"

#include <QApplication>
#include "myserver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    plotNetworkData w;
    w.show();
    // Make a server and starts it
    MyServer server;
    server.startServer();
    return a.exec();
}
