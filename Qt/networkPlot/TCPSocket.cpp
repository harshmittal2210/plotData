#include "TCPSocket.h"

TCPSocket::TCPSocket(QObject *parent) : QObject(parent)
{

}
void TCPSocket::getSinglePacket(){
    QJsonObject data{
        {"Send_Data",1}
    };
    sendData(data);
}

void TCPSocket::getDataStream(){
    QJsonObject data{
        {"Send_Data",2}
    };
    sendData(data);
}

void TCPSocket::stopData(){
    QJsonObject data{
        {"Send_Data",0}
    };
    sendData(data);
}

void TCPSocket::sendData(QJsonObject data){
    QJsonArray jsarray {data};
    QJsonDocument jsDoc(jsarray);
    QString jsString = QString::fromLatin1(jsDoc.toJson());
    sock->write(jsString.toLatin1());
//    sock->waitForBytesWritten(100);

}
void TCPSocket::readData(){
    qDebug()<< "Waiting to read Data";
    sock->waitForReadyRead(3000);
    QString str =  sock->readAll();
    QJsonParseError parseError;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(str.toLatin1(), &parseError);
    if(parseError.error != QJsonParseError::NoError)
    {
        qDebug() << "Parse error: " << parseError.errorString();
        qDebug() << str.toLatin1().data();
        return;
    }
    QJsonArray jsonArray = jsonResponse.array();
    if(!jsonArray.isEmpty()){
        QJsonObject jsonObject = jsonArray.first().toObject();
//        qDebug()<< jsonObject.value("X").toArray()[0].toDouble();
//        QArrayData X = jsonObject.value("X").toArray();
        for(int i=0;i<jsonObject.value("X").toArray().size();i++){
            xCorr.push_back(jsonObject.value("X").toArray()[i].toDouble());
            yCorr.push_back(jsonObject.value("Y").toArray()[i].toDouble());
        }
    }
}
void TCPSocket::Connect(char* ip, int port)
{
    sock = new QTcpSocket(this);
//    sock->connectToHost("192.168.56.1",65040);
    sock->connectToHost(ip,port);

    if(sock->waitForConnected(3000)){
        qDebug()<<"Connected!!";

    }
    else{
        qDebug()<<"Not Connected";
    }
}

void TCPSocket::Close()
{
    sock->close();

}

void TCPSocket::ClearVar(){
    xCorr.clear();
    yCorr.clear();
}
