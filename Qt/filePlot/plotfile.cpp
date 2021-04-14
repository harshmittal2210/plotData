#include "plotfile.h"
#include "ui_plotfile.h"
#include <QFileDialog>
#include <QMessageBox>

plotFile::plotFile(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::plotFile)
{
    ui->setupUi(this);

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    ui->customPlot->xAxis->setRange(-6000, 100);
    ui->customPlot->yAxis->setRange(-6000, 8000);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}

plotFile::~plotFile()
{
    delete ui;
}

void plotFile::makePlot(){
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:

    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->xAxis->setRange(-1, 1);
    ui->customPlot->yAxis->setRange(0, 1);
    ui->customPlot->replot();
}

void plotFile::clearPlot(){
    ui->customPlot->graph(0)->data()->clear();
    ui->customPlot->replot();
    ui->customPlot->update();
}

void plotFile::on_plotButton_clicked()
{

    makePlot();
}

void plotFile::on_clearButton_clicked()
{
    clearPlot();
}

void plotFile::initFile(){

}
void plotFile::on_fileOpenButton_clicked()
{
    fileName = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "./",
                "All files (*.*);;Text File (*.txt)"
                );


//    QMessageBox::information(this,tr("File Name"),fileName);
    ui->fileTextEdit->setText(fileName);
}
