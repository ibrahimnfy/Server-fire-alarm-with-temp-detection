#include "server.h"


Server::Server(quint16 port, QObject *parent)
{
    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::LocalHost, port);
    connect(tcpServer,&QTcpServer::newConnection,this,[=](){
        while(tcpServer->hasPendingConnections()){
            QTcpSocket * client= tcpServer->nextPendingConnection();
            clients.append(client);
            clientdatas[client].buffer= QByteArray();
            clientdatas[client].expectedsize=0;
            clientdatas[client].timer = new QTimer(this);
            clientdatas[client].timer->setSingleShot(true);
            connect(clientdatas[client].timer, &QTimer::timeout, this, [=]() {
                qDebug() << "[Server] Timeout! Client mesaj atmadı, logout.";
                loginController[client] = false;
                emit logoutOccured(clientdatas[client].name, clientdatas[client].typeID);// EN SON BURADA KALDDNNNNNN
                client->disconnectFromHost();
            });

            connect(client, &QTcpSocket::readyRead,this,[=](){
                clientdatas[client].buffer.append(client->readAll());
                while(clientdatas[client].buffer.size()>0){
                qDebug() << "1";
                while(clientdatas[client].expectedsize==0){
                    qDebug() << "2";
                    if(clientdatas[client].buffer.size()<4){
                        return;
                    }
                    QDataStream stream(clientdatas[client].buffer);
                    stream.setByteOrder(QDataStream::BigEndian);
                    quint32 size = 0;
                    stream >> size;
                    clientdatas[client].expectedsize = size;

                    clientdatas[client].buffer.remove(0,4);
                }
                while(clientdatas[client].buffer.size()<clientdatas[client].expectedsize){
                    return;
                }
                QByteArray message = clientdatas[client].buffer.left(clientdatas[client].expectedsize);
                clientdatas[client].buffer.remove(0, clientdatas[client].expectedsize);
                clientdatas[client].expectedsize = 0;

                qDebug() << "3";
                QByteArray copy = message; // capture by value (thread-safe olacak şekilde kopyala)
                handleMessage(client, copy);


                }
            });

            connect(client, &QTcpSocket::disconnected, this, [=]() {

                qDebug() << "[Server] Bağlantı koptu:" << clientdatas[client].name;
                clients.removeAll(client);
                clientdatas.remove(client);
                client->deleteLater();
            });
        }

    });
}

void Server::handleMessage(QTcpSocket *client, const QByteArray &data)
{
    chat::Wrapper wrapper{};
    QProtobufSerializer* m_serializer = new QProtobufSerializer();
    Q_ASSERT(m_serializer != nullptr);
    qDebug() << "Payload:" << data.toHex(' ');
    if (!wrapper.deserialize(m_serializer, data)) {
        qDebug() << "Deserialize failed!" << m_serializer;
    }

    // clientdatas[client].timer= new QTimer(this);
    // clientdatas[client].timer->setInterval(10000);
    // clientdatas[client].timer->setSingleShot(true);
    // connect(clientdatas[client].timer, &QTimer::timeout, this,[=](){
    //     loginController[client]=false;
    //     client->disconnectFromHost();
    // });
    if(wrapper.hasLogin() && !loginController[client]){


        qDebug() << "4";
        QString name = wrapper.login().name();
        clientdatas[client].timer->setInterval(wrapper.login().time());// burayı düzenleme yapman lazım timerlar böyle güvende değil galiba
        clientdatas[client].name = name;
        clientdatas[client].typeID = wrapper.login().typeID();
        emit loginOccured(clientdatas[client].name, clientdatas[client].typeID);
        loginController[client]=true;
        clientdatas[client].timer->start();

        chat::Wrapper response{};
        qDebug() << "7";
        response.setChat({});
        auto chatMsg = response.chat();
        qDebug() << "8";
        chatMsg.setSender("Server");
        // chatMsg.setText("Hoş geldin mesaj atmak için 10 saniyen var, " + name.toUtf8());
        // chatMsg.setTimestamp(QDateTime::currentSecsSinceEpoch());
        response.setChat(chatMsg);
        qDebug() << "9";
        QByteArray payload = response.serialize(m_serializer);
        quint32 size = payload.size();

        QByteArray packet;
        QDataStream stream(&packet, QIODevice::WriteOnly);
        stream.setByteOrder(QDataStream::BigEndian); // Uyum için
        stream << size; // 4-byte header
        packet.append(payload); // ardından verinin kendisi
        qDebug() << "9"<< packet.toHex(' ');

        client->write(packet);
        client->flush();
    }
    else if(wrapper.hasChat() && loginController[client]){
        clientdatas[client].timer->start();
        qDebug() << "5";
        QString sender = wrapper.chat().sender();
        auto &sensor = wrapper.chat().sensors();
        emit chatReceived(sender, sensor.iD(), sensor.value(), sensor.typeID());

        // if(wrapper.chat().hasHumi()){
        //     QString ID = wrapper.chat().humi().iD();
        //     QtProtobuf::int64 value = wrapper.chat().humi().value();
        //     emit chatReceived(sender, ID, value, clientdatas[client].typeID);

        // }
        // else if(wrapper.chat().hasTemp()){
        //     QString ID = wrapper.chat().temp().iD();
        //     QtProtobuf::int64 value = wrapper.chat().temp().value();
        //     emit chatReceived(sender, ID, value, clientdatas[client].typeID);
        // }
        // else if(wrapper.chat().hasTemp()){
        //     QString ID = wrapper.chat().temp().iD();
        //     QtProtobuf::int64 value = wrapper.chat().temp().value();
        //     emit chatReceived(sender, ID, value, clientdatas[client].typeID);
        // }
        //qDebug() << "[Server] Chat mesajı:" << sender << ":" << text;

        // Yayınla
        // broadcastChat(sender, text);
    }
}

// void Server::broadcastChat(const QString &sender, const QString &text)
// {
//     chat::Wrapper wrapper{};
//     QProtobufSerializer* serializer = new QProtobufSerializer();
//     Q_ASSERT(serializer != nullptr);

//     chat::Chat chatMsg;
//     chatMsg.setSender(sender);
//     chatMsg.setText(text);
//     chatMsg.setTimestamp(QDateTime::currentSecsSinceEpoch());

//     wrapper.setChat(chatMsg);

//     QByteArray out = wrapper.serialize(serializer);
//     quint32 len = out.size();

//     QByteArray framed;
//     QDataStream stream(&framed, QIODevice::WriteOnly);
//     stream.setByteOrder(QDataStream::BigEndian);
//     stream << len;
//     framed.append(out);

//     for (QTcpSocket *client : clients) {
//         if (client->state() == QAbstractSocket::ConnectedState) {
//             qDebug()<< "100";
//             client->write(framed);
//             client->flush();
//         }
//     }
// }
