#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // client = new TestClient(this);
    // client->connectAndSend("127.0.0.1", 12345);
}

MainWindow::~MainWindow()
{
    delete ui;
}
