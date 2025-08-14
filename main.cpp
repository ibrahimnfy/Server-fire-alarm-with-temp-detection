
#include <QApplication>
#include <message.qpb.h>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include "testclient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    QCommandLineParser parser;
    parser.setApplicationDescription("TestClient application using Protobuf");
    parser.addHelpOption(); // --help desteği
    parser.addVersionOption();
    parser.setSingleDashWordOptionMode(QCommandLineParser::ParseAsLongOptions);

    // --name <name>
    QCommandLineOption nameOption("name", "Client name to use.", "name");
    // --typeID <id>
    QCommandLineOption typeIDOption("typeID", "Sensor type ID to use.", "typeID");



    parser.addOption(nameOption);
    parser.addOption(typeIDOption);

    parser.process(a); // Komut satırı argümanlarını işle

    // Argümanları oku
    QString name = parser.value(nameOption);

    bool isOk = false;
    QtProtobuf::int64 typeID = parser.value(typeIDOption).toInt(&isOk);

    // Hatalı kullanım kontrolü
    if (name.isEmpty()|| !isOk)
    {
        qWarning() << "Both --name and --typeID options must be provided.";
        parser.showHelp(1); // Uygulamayı hata kodu 1 ile sonlandırır
    }

    // Terminale bilgi bastır
    qDebug() << "Client Name:" << name;
    qDebug() << "Sensor Type ID:" << typeID;

    // İstemci başlat
    TestClient client{name, typeID};
    client.connectAndSend("127.0.0.1", 12345);  // Burada parametre geçiliyor olmalı

    return a.exec();
}
