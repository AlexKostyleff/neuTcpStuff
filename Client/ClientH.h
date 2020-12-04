#include <QtCore>
#include <QtNetwork>
#include <QCoreApplication>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QString>
#include <QFile>
#include <QDataStream>
#include <QTextStream>

class Client : public QTcpSocket
{
    Q_OBJECT
public:
    explicit Client(QTcpSocket *parent = 0);

public slots:
    bool connectToHost(QString host);
    bool writeData(QByteArray data);

private:
    QTcpSocket *socket;
};
