#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
<<<<<<< HEAD
#include "server.h"
#include "testclient.h"
#include <QDateTime>
#include <QDebug>
#include <QTcpSocket>
=======
#include "testclient.h"

>>>>>>> 8e0bf03bf710e49b8dd4d040a9e8952fb22c9c2a
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
<<<<<<< HEAD
struct sensorData{
    int typeID{};
    QtProtobuf::int64 value{};
    int row{};
    QDateTime time;
};
=======
>>>>>>> 8e0bf03bf710e49b8dd4d040a9e8952fb22c9c2a

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
<<<<<<< HEAD
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

=======
    TestClient *client;
};
>>>>>>> 8e0bf03bf710e49b8dd4d040a9e8952fb22c9c2a
#endif // MAINWINDOW_H
