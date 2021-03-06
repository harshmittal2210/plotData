#include "plotnetworkdata.h"
#include "ui_plotnetworkdata.h"

plotNetworkData::plotNetworkData(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::plotNetworkData)
{
    ui->setupUi(this);

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot->xAxis->setLabel("X");
    ui->customPlot->yAxis->setLabel("Y");
    ui->customPlot->xAxis->setRange(-6000, 100);
    ui->customPlot->yAxis->setRange(-6000, 8000);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    ui->plotTypeComboBox->setCurrentIndex(4);
    ui->lineStyleComboBox->setCurrentIndex(1);
    ui->ipAddressEdit->setText("192.168.56.1");
    ui->portLineEdit->setText("1234");


//    MyThread m;
//    connect(&MyThread,SIGNAL(newDataRecieved(QVector<double> x,QVector<double> y)),this,SLOT(plotNewValues(QVector<double> x,QVector<double> y)));
    ServerThread *thread = new ServerThread(this);
    connect(thread,SIGNAL(newDataRecieved(QVector<double> ,QVector<double> )),this,SLOT(plotNewValues(QVector<double> ,QVector<double> )));
    thread->start();
}

plotNetworkData::~plotNetworkData()
{
    delete ui;
}

void plotNetworkData::plotNewValues(QVector<double> x, QVector<double> y)
{
//    qDebug()<< "Got data x:"<<x<<" y:"<<y;
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->rescaleAxes();
    ui->customPlot->replot();
    ui->customPlot->update();
}

void plotNetworkData::on_plotTypeComboBox_currentIndexChanged(int index)
{
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

void plotNetworkData::on_lineStyleComboBox_currentIndexChanged(int index)
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


