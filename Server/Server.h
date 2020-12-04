#include <QtCore>
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QFile>
#include <QDataStream>
#include <QByteArray>
#include <QDebug>
#include <QObject>
#include <QTextStream>
class Server : public QTcpServer
{
    Q_OBJECT
public:

    explicit Server(QTcpServer *parent = 0);

signals:
    void dataReceived(QByteArray);

public slots:
    void startServer();
    void newConnection();
    void disconnected();
    void readyRead();

private:
    QTcpServer *server;
    QHash<QTcpSocket*, QByteArray*> buffers;
    QHash<QTcpSocket*, qint32*> sizes;
};
