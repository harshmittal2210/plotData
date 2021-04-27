#include "mythread.h"

MyThread::MyThread(qintptr ID, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = ID;
}

void MyThread::run()
{
    // thread starts here
    qDebug() << " Thread started";

    socket = new QTcpSocket();

    // set the ID
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        // something's wrong, we just emit a signal
        emit error(socket->error());
        return;
    }

    // connect socket and signal
    // note - Qt::DirectConnection is used because it's multithreaded
    //        This makes the slot to be invoked immediately, when the signal is emitted.

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    // We'll have multiple clients, we want to know which is which
    qDebug() << socketDescriptor << " Client connected";

    // make this thread a loop,
    // thread will stay alive so that signal/slot to function properly
    // not dropped out in the middle when thread dies

    exec();
}

void MyThread::readyRead()
{
    // get the information
    QByteArray Data = socket->readAll();

    // will write on server side window
    qDebug() << socketDescriptor << " Data in: " << Data;
    parseMsg(Data);
//    socket->write("Hello Client!",13);
}

void MyThread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";


    socket->deleteLater();
    exit(0);
}

void MyThread::parseMsg(QByteArray Data){
    QJsonParseError parseError;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(Data, &parseError);

    if(parseError.error != QJsonParseError::NoError)
    {
        qDebug() << "Parse error: " << parseError.errorString();
        return;
    }

    QJsonArray jsonArray = jsonResponse.array();

    xCorr.clear();
    yCorr.clear();
    if(!jsonArray.isEmpty()){
        QJsonObject jsonObject = jsonArray.first().toObject();
//        qDebug()<< jsonObject.value("X").toArray()[0].toDouble();
//        QArrayData X = jsonObject.value("X").toArray();
        for(int i=0;i<jsonObject.value("X").toArray().size();i++){
            xCorr.push_back(jsonObject.value("X").toArray()[i].toDouble());
            yCorr.push_back(jsonObject.value("Y").toArray()[i].toDouble());
        }

//        qDebug()<<xCorr;
    }
    // emit signal
    emit newDataRecieved(xCorr,yCorr);
}
