#include "plotdata.h"
#include "ui_plotdata.h"

plotData::plotData(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::plotData)
{
    ui->setupUi(this);
}

plotData::~plotData()
{
    delete ui;
}

