#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include <QByteArray>
#include <QDateTime>
#include "message.qpb.h"
#include <QProtobufSerializer>
#include <QtConcurrent/QtConcurrentRun>
#include <QTimer>



struct ClientData{
    QString name{};
    int typeID;
    QByteArray buffer;
    int expectedsize;
    QTimer *timer;
};

class Server : public QObject
{
    Q_OBJECT

public:
    explicit Server(quint16 port, QObject *parent = nullptr);
signals:
    void loginOccured(const QString &name, const int typeID);
    void chatReceived(const QString &name,const QString &ID, const QtProtobuf::int64 value, const int typeID);
    void logoutOccured(const QString &name, const int typeID);
private:
    QTcpServer *tcpServer;
    QList<QTcpSocket*> clients;
    QMap<QTcpSocket*, ClientData> clientdatas;
    QMap<QTcpSocket*, bool> loginController;


    void handleMessage(QTcpSocket *client, const QByteArray &data);  // kopyalanabilir veri!
    void broadcastChat(const QString &sender, const QString &ID, const QtProtobuf::int64 value, const int typeID);
};

#endif // SERVER_H
