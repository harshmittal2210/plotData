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
private slots:
    void on_plotButton_clicked();

    void on_clearButton_clicked();

    void on_fileOpenButton_clicked();

private:
    Ui::plotFile *ui;
    QString fileName;
    QVector<double> x_cor,y_cor;
    bool stopPlotting;
    int frameCount;
};
#endif // PLOTFILE_H
