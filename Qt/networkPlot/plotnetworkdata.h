#ifndef PLOTNETWORKDATA_H
#define PLOTNETWORKDATA_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class plotNetworkData; }
QT_END_NAMESPACE

class plotNetworkData : public QMainWindow
{
    Q_OBJECT

public:
    plotNetworkData(QWidget *parent = nullptr);
    ~plotNetworkData();

private slots:
    void on_plotTypeComboBox_currentIndexChanged(int index);

    void on_lineStyleComboBox_currentIndexChanged(int index);

    void on_plotButton_clicked();

    void on_clearButton_clicked();

private:
    Ui::plotNetworkData *ui;
};
#endif // PLOTNETWORKDATA_H
