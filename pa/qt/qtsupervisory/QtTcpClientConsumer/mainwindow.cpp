#include <QDateTime>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "plotter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    
    ui->setupUi(this);
    
    socket = new QTcpSocket(this);

    timing = 1;

    // IP used during development
    ui->serverIp->setText(QString("192.168.2.6:1234"));

    // Buttons 
    connect(
        ui -> connectBtn,
        SIGNAL(clicked(bool)),
        this,
        SLOT(doConnection())
    );

    connect(
        ui -> disconnectBtn,
        SIGNAL(clicked(bool)),
        this,
        SLOT(doDisconnection())
    );

    connect(
        ui -> startBtn,
        SIGNAL(clicked(bool)),
        this, 
        SLOT(start())
    );

    connect(
        ui -> stopBtn,
        SIGNAL(clicked(bool)),
        this, 
        SLOT(stop())
    );

    connect(
        ui -> updateBtn,
        SIGNAL(clicked(bool)),
        this,
        SLOT(doUpdate())
    );

    // Slider
    connect(
        ui -> timingSlider,
        SIGNAL(valueChanged(int)),
        this,
        SLOT(changeTiming(int))
    );

    // Producers List 
    connect(
        ui -> producersList,
        SIGNAL(itemClicked(QListWidgetItem*)),
        this,
        SLOT(changeProducer())
    );
}

void MainWindow::tcpConnect(QString serverIP, int serverPort) {
    
    socket->connectToHost(serverIP, serverPort);

    if (socket->waitForConnected(3000)) {
        QString str = "<i><font color=\"green\">Connected</font></i>";
        ui -> stateLabel -> setText(str);
    } else {
        QString str = "<i><font color=\"red\">Disconnected</font></i>";
        ui -> stateLabel -> setText(str);
    }
}

void MainWindow::tcpDisconnect() {

    socket -> disconnectFromHost();

    if (socket->state() == QAbstractSocket::UnconnectedState || socket->waitForDisconnected(3000)) {
        QString str = "<i><font color=\"red\">Disconnected</font></i>";
        ui -> stateLabel -> setText(str);
    } else {
        QString str = "<i><font color=\"green\">Connected</font></i>";
        ui -> stateLabel -> setText(str);
    }
}

void MainWindow::doConnection() {

    QStringList server = ui->serverIp->text().split(QRegExp("[:]"), QString::SkipEmptyParts);

    QString serverIP = server[0];
    QString serverPort = server[1];

    tcpConnect(serverIP, serverPort.toInt());
}

void MainWindow::doDisconnection() {

    tcpDisconnect();

}

void MainWindow::doUpdate() {
    QStringList producersList;
    QString producers;

    socket -> write("list\r\n");
    socket -> waitForBytesWritten();
    socket -> waitForReadyRead();

    ui -> producersList -> clear();

    while(socket -> bytesAvailable()) {
        producers = socket -> readLine().replace("\r", "").replace("\n", "");
        producersList = producers.split(" ");

        for(QString producer : producersList) {
            ui -> producersList -> addItem(producer);
        }
    }

}

void MainWindow::getData(int samples) {
    QString str;
    QStringList list;
    qint64 theTime, value;

    if (socket->state() == QAbstractSocket::ConnectedState) {
        if (socket->isOpen()) {
            QString getCmd = "get " + selectedProducer + " " + QString::number(samples) + "\r\n";
                    
            socket->write(getCmd.toStdString().c_str());
            
            socket->waitForBytesWritten();
            socket->waitForReadyRead();

            std::vector<qint64> abscissa, ordenada;
            while (socket->bytesAvailable()) {
                str = socket -> readLine().replace("\n", "").replace("\r", "");
                list = str.split(" ");

                if (list.size() == 2) {
                    bool ok;

                    str = list.at(0);
                    theTime = str.toLongLong(&ok);
                    abscissa.push_back(theTime);

                    str = list.at(1);
                    value = str.toLongLong(&ok);
                    ordenada.push_back(value);
                }
            }

            ui -> plot -> reciveData(abscissa, ordenada);
            
        }
    } else {
        QString str = "<i><font color=\"red\">Not Connected</font></i>";
        ui -> startedLabel -> setText(str);
    }

}

void MainWindow::timerEvent(QTimerEvent *event) {
    getData(30);
}

void MainWindow::start() {
    if(!temporizador) {
        killTimer(temporizador);
    }

    temporizador = startTimer(timing * 1000);

    QString str = "<i><font color=\"green\">started</font></i>";
    ui -> startedLabel -> setText(str);
}

void MainWindow::stop() {

    killTimer(temporizador);

    QString str = "<i><font color=\"red\">stoped</font></i>";
    ui -> startedLabel -> setText(str);

}

void MainWindow::changeTiming(int _timing) {
    
    timing = _timing;

}

void MainWindow::changeProducer() {
    QString item = ui -> producersList -> currentItem() -> text();

    selectedProducer = item;

    QString str = "<i><font color=\"green\">"+ item +"</font></i>";
    ui -> conectedToLabel -> setText(str);
}

MainWindow::~MainWindow() {
    delete socket;
    delete ui;
}
