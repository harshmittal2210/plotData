#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QObject>
#include <QtNetwork>
#include <QTcpSocket>
#include <QDebug>
#include <QThread>

class TCPSocket : public QObject
{
    Q_OBJECT
public:
    explicit TCPSocket(QObject *parent = nullptr);
    void Connect(char* ip, int port);
    void Close();
    void sendData(QJsonObject data);

    void getSinglePacket();


    QVector<double> xCorr,yCorr;

    void getDataStream();
    void stopData();

public slots:
    void readData();
    void ClearVar();

private:
    QTcpSocket *sock;
};

#endif // TCPSOCKET_H
