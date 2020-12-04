#include "ClientH.h"

static inline QByteArray IntToArray(qint32 source);

Client::Client(QTcpSocket *parent) : QTcpSocket(parent)
{
    socket = new QTcpSocket(this);
}

bool Client::connectToHost(QString host)
{
    socket->connectToHost(host, 1024);
    return socket->waitForConnected();
}

bool Client::writeData(QByteArray data)
{
    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        socket->write(IntToArray(data.size()));
        socket->write(data);
        return socket->waitForBytesWritten();
    }
    else
        return false;
}

QByteArray IntToArray(qint32 source)
{
    QByteArray temp;
    QDataStream data(&temp, QIODevice::ReadWrite);
    data << source;
    return temp;
}
