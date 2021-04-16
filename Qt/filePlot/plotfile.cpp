#include "plotfile.h"
#include "ui_plotfile.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

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
    frameCount=0;
}

plotFile::~plotFile()
{
    delete ui;
}

void plotFile::makePlot(){

    int num = ui->windowSizeSpinBox->value();

    if(num+frameCount<=x_cor.size()){
        QVector<double> x(num), y(num); // initialize with entries 0..100
        for (int i=0; i<num; ++i)
        {
          x[i] = x_cor[i+frameCount];
          y[i] = y_cor[i+frameCount];
        }

        frameCount+=num;

        ui->customPlot->graph(0)->setData(x, y);
        ui->customPlot->replot();
        ui->customPlot->update();
    }
    else{
        qDebug()<<"File Ended";
        stopPlotting =1;
        QMessageBox::information(this,"Plot info","Finished plotting the file");
    }


}

void plotFile::clearPlot(){
    ui->customPlot->graph(0)->data()->clear();
    ui->customPlot->replot();
    ui->customPlot->update();
}

void plotFile::on_plotButton_clicked()
{

    if(fileName.isEmpty()){
        this->statusBar()->showMessage("Select a file first!!!");
    }
    else{

        do{
            stopPlotting = 0;
            makePlot();
        }
        while(ui->plotCheckBox->isChecked() && !stopPlotting);


    }

}

void plotFile::on_clearButton_clicked()
{
    stopPlotting =1;
    clearPlot();
    frameCount =0;
}

void plotFile::initFile(){

    QFile file(fileName);
    if(!file.open(QFile::ReadOnly)){
        QMessageBox::warning(this,"Error File Open","Not able to open the file");
    }
    QTextStream in(&file);

    double x,y;
    while(true){
        if(in.atEnd()){
            break;
        }

        in>>x>>y;
        x_cor.append(x);
        y_cor.append(y);
    }
//    qDebug()<<x_cor.size();
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
    initFile();
}
