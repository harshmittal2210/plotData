#ifndef PLOTFILE_H
#define PLOTFILE_H

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class plotFile; }
QT_END_NAMESPACE

class plotFile : public QMainWindow
{
    Q_OBJECT

public:
    plotFile(QWidget *parent = nullptr);
    ~plotFile();

public slots:
    void clearPlot();
    void makePlot();
    void initFile();
    void delay(int n);
private slots:
    void on_plotButton_clicked();

    void on_clearButton_clicked();

    void on_fileOpenButton_clicked();



    void on_plotTypeComboBox_currentIndexChanged(int index);

    void on_lineStyleComboBox_currentIndexChanged(int index);

private:
    Ui::plotFile *ui;
    QString fileName;
    QVector<double> x_cor,y_cor;
    bool stopPlotting;
    int frameCount;
};
#endif // PLOTFILE_H
