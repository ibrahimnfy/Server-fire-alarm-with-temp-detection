#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "server.h"
#include "testclient.h"
#include <QDateTime>
#include <QDebug>
#include <QTcpSocket>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
struct sensorData{
    int typeID{};
    QtProtobuf::int64 value{};
    int row{};
    QDateTime time;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Server *server;
    QMap<QString, sensorData> nameToRowMap;
    QTcpSocket *alarmSocket;
    int alarmCounter{};
    QTimer *timer;

private slots:
    void onLoginOccured(const QString &name, const int typeID);
    void onChatReceived(const QString &name,const QString &ID, const QtProtobuf::int64 value, const int typeID);
    void onLogoutOccured(const QString &name, const int typeID);
};

#endif // MAINWINDOW_H
