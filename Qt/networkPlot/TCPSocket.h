#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QObject>
#include <QtNetwork>
#include <QTcpSocket>
#include <QDebug>

class TCPSocket : public QObject
{
    Q_OBJECT
public:
    explicit TCPSocket(QObject *parent = nullptr);
    void Connect();
    void Close();
    void sendData(QJsonObject data);

    void getSinglePacket();
    void readData();

    QVector<double> xCorr,yCorr;
    void ClearVar();
    void getDataStream();
    void stopData();
private:
    QTcpSocket *sock;
};

#endif // TCPSOCKET_H
