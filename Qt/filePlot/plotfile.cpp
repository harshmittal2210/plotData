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
void plotFile::delay(int n)
{
    QTime dieTime= QTime::currentTime().addMSecs(n);

    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
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
            delay(ui->delaySpinBox->value());
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

void plotFile::on_plotTypeComboBox_currentIndexChanged(int index)
{
//    qDebug()<<index;
    switch (index) {
        case 0:
                ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
                break;
        case 1:
                ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssDot);
                break;
        case 2:
                ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCross);
                break;
        case 3:
                ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssPlus);
                break;
        case 4:
                ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
                break;
        case 5:
                ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssDisc);
                break;
        case 6:
                ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssSquare);
                break;
        case 7:
                ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssDiamond);
                break;
        case 8:
                ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssStar);
                break;
        case 9:
                ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssTriangle);
                break;
        case 10:
                ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssTriangleInverted);
                break;

        case 11:
                ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCrossSquare);
                break;
        case 12:
                ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssPlusSquare);
                break;
        case 13:
                ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssPlusSquare);
                break;
        case 14:
                ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCrossCircle);
                break;
        case 15:
                ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssPlusCircle);
                break;
        case 16:
                ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssPeace);
                break;
        default:
                ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCross);
                break;


    }

    ui->customPlot->replot();
    ui->customPlot->update();
}

void plotFile::on_lineStyleComboBox_currentIndexChanged(int index)
{

    switch (index) {
        case 0:
                ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
                break;
        case 1:
                ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
                break;
        case 2:
                ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsStepLeft);
                break;
        case 3:
                ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsStepRight);
                break;
        case 4:
                ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsStepCenter);
                break;
        case 5:
                ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsImpulse);
                break;
        default:
                ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
                break;

    }
    ui->customPlot->replot();
    ui->customPlot->update();
}
