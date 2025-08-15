#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //client = new TestClient(this);
    //client->connectAndSend("127.0.0.1", 12345);  // localhost, port
    server= new Server(12345);  // PORT 12345'te dinle
    alarmSocket=new QTcpSocket(this);
    connect(alarmSocket, &QTcpSocket::disconnected, alarmSocket, [=](){
        alarmSocket->connectToHost(QHostAddress::LocalHost, 1234);
    });
    alarmSocket->connectToHost(QHostAddress::LocalHost, 1234);
    timer= new QTimer(this);

    connect(timer, &QTimer::timeout,this,[=](){
        if(alarmCounter>2){
            qDebug()<<"1111111111";
            alarmSocket->write("y");
            alarmSocket->flush();
        }
        alarmCounter=0;

        timer->start(10000);
    });
    timer->start(10000);
    //ŞİMDİ BURADA SERVER TANIMLAYIP 3 TANE SİNYALE GÖRE İŞLEME YAPMAN LAZIM
    connect(server, &Server::loginOccured,this,&MainWindow::onLoginOccured);
    connect(server, &Server::chatReceived,this,&MainWindow::onChatReceived);
    connect(server, &Server::logoutOccured,this,&MainWindow::onLogoutOccured);
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setItem(0,0, new QTableWidgetItem("Client's Name"));
    ui->tableWidget->setItem(0,1, new QTableWidgetItem("Type ID"));
    ui->tableWidget->setItem(0,2, new QTableWidgetItem("ID"));
    ui->tableWidget->setItem(0,3, new QTableWidgetItem("VALUE"));
    ui->tableWidget->setItem(0,4, new QTableWidgetItem("Login Time"));
    ui->tableWidget->setItem(0,5, new QTableWidgetItem("Last Sensor Time"));
    ui->tableWidget->setItem(0,6, new QTableWidgetItem("Second Last Sensor Time"));
    ui->tableWidget->setItem(0,7, new QTableWidgetItem("Logout Time"));


}

MainWindow::~MainWindow() {}

void MainWindow::onLoginOccured(const QString &name, const int typeID)
{
    QString time = QDateTime::currentDateTime().toString();
    int row;
    if(nameToRowMap.contains(name)){
        row= nameToRowMap[name].row;
    }
    else{
        row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,0, new QTableWidgetItem(name));
        ui->tableWidget->setItem(row,1, new QTableWidgetItem(QString::number(typeID)));
        nameToRowMap[name].typeID=typeID;
        nameToRowMap[name].row=row;

    }

    int columnCount = ui->tableWidget->columnCount();
    for (int col = 2; col < columnCount; ++col) {
        ui->tableWidget->setItem(row,col, new QTableWidgetItem(""));
    }
    ui->tableWidget->setItem(row,4, new QTableWidgetItem(time));
}

void MainWindow::onChatReceived(const QString &name, const QString &ID, const QtProtobuf::int64 value, const int typeID)
{
    QDateTime time = QDateTime::currentDateTime();
    if(!nameToRowMap.contains(name)){
        qDebug() <<"1-BÜYÜK PROBLEM BURAYA ASLA GİREMEZ LOGİN OLMADAN CHAT ATAMAZ";
        return;
    }
    int row= nameToRowMap[name].row;
    ui->tableWidget->setItem(row,6, ui->tableWidget->takeItem(row,5));
    ui->tableWidget->setItem(row,5, new QTableWidgetItem(time.toString()));
    ui->tableWidget->setItem(row,2, new QTableWidgetItem(ID));
    for(auto &&[k,v] : nameToRowMap.asKeyValueRange()){

        if(v.value>20 && value>20 && qAbs(time.toUTC().secsTo(nameToRowMap[name].time))<5 && nameToRowMap[name].typeID==2){
            alarmCounter++;
        }
    }
    nameToRowMap[name].value=value;
    nameToRowMap[name].time=time;
    // if(ui->tableWidget->takeItem(row,3)->text().toInt()>20 && value>20){
    //     qDebug()<<"1111111111";
    //     alarmSocket->write("y");
    //     alarmSocket->flush();
    // }
    ui->tableWidget->setItem(row,3, new QTableWidgetItem(QString::number(value)));


}

void MainWindow::onLogoutOccured(const QString &name, const int typeID)
{
    QString time = QDateTime::currentDateTime().toString();
    if(!nameToRowMap.contains(name)){
        qDebug() <<"2-BÜYÜK PROBLEM BURAYA ASLA GİREMEZ LOGİN OLMADAN CHAT ATAMAZ";
        return;
    }
    int row= nameToRowMap[name].row;
    ui->tableWidget->setItem(row,7, new QTableWidgetItem(time));
}
