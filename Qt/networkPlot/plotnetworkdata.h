#ifndef PLOTNETWORKDATA_H
#define PLOTNETWORKDATA_H

#include <QMainWindow>
#include "TCPSocket.h"

QT_BEGIN_NAMESPACE
namespace Ui { class plotNetworkData; }
QT_END_NAMESPACE

class plotNetworkData : public QMainWindow
{
    Q_OBJECT

public:
    plotNetworkData(QWidget *parent = nullptr);
    ~plotNetworkData();

    void clearPlot();
    void plotData();
private slots:
    void on_plotTypeComboBox_currentIndexChanged(int index);

    void on_lineStyleComboBox_currentIndexChanged(int index);

    void on_plotButton_clicked();

    void on_clearButton_clicked();

    void on_connectButton_clicked();

    void on_disconnectButton_clicked();

private:
    Ui::plotNetworkData *ui;
    TCPSocket tcpConnection;
    bool stopPlotting;
};
#endif // PLOTNETWORKDATA_H
