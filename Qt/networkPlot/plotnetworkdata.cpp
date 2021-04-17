#include "plotnetworkdata.h"
#include "ui_plotnetworkdata.h"

plotNetworkData::plotNetworkData(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::plotNetworkData)
{
    ui->setupUi(this);
}

plotNetworkData::~plotNetworkData()
{
    delete ui;
}

