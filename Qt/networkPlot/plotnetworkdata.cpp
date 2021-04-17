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


void plotNetworkData::on_plotTypeComboBox_currentIndexChanged(int index)
{

}

void plotNetworkData::on_lineStyleComboBox_currentIndexChanged(int index)
{

}
