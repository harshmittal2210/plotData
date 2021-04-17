#ifndef SOCKET_H
#define SOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
class socket : public QObject
{
    Q_OBJECT
public:
    explicit socket(QObject *parent = nullptr);

signals:

};

#endif // SOCKET_H
