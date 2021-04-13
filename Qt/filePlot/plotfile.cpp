#include "plotfile.h"
#include "ui_plotfile.h"

plotFile::plotFile(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::plotFile)
{
    ui->setupUi(this);
}

plotFile::~plotFile()
{
    delete ui;
}

