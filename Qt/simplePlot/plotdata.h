#ifndef PLOTDATA_H
#define PLOTDATA_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class plotData; }
QT_END_NAMESPACE

class plotData : public QMainWindow
{
    Q_OBJECT

public:
    plotData(QWidget *parent = nullptr);
    ~plotData();

private:
    Ui::plotData *ui;
};
#endif // PLOTDATA_H
