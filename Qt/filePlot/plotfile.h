#ifndef PLOTFILE_H
#define PLOTFILE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class plotFile; }
QT_END_NAMESPACE

class plotFile : public QMainWindow
{
    Q_OBJECT

public:
    plotFile(QWidget *parent = nullptr);
    ~plotFile();

private:
    Ui::plotFile *ui;
};
#endif // PLOTFILE_H
