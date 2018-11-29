#include "mainwindow.h"
#include <QDateTime>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) 
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    
    ui->setupUi(this);
    
    socket = new QTcpSocket(this);

    min = 0;
    max = 1;

    timing = 1;

    // IP used during development
    ui->server->setText(QString("10.6.4.109:1234"));
    
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

    // Sliders
    connect(
        ui -> minSlider,
        SIGNAL(valueChanged(int)),
        this, 
        SLOT(changeMin(int))
    );

    connect(
        ui -> maxSlider,
        SIGNAL(valueChanged(int)),
        this, 
        SLOT(changeMax(int))
    );

    connect(
        ui -> timingSlider,
        SIGNAL(valueChanged(int)),
        this, 
        SLOT(changeTiming(int))
    );

}

void MainWindow::tcpConnect(QString serverIP, int serverPort) {

    socket->connectToHost(serverIP, serverPort);
    
    if (socket->waitForConnected(3000)) {
        QString str = "<i><font color=\"green\">Successfully Connected</font></i>";
        ui->logScreen->append(str);
    } else {
        QString str = "<i><font color=\"red\">Connection Refused</font></i>";
        ui->logScreen->append(str);
    }
    
}

void MainWindow::tcpDisconnect() {

    socket->disconnectFromHost();

    if (socket->state() == QAbstractSocket::UnconnectedState || socket->waitForDisconnected(3000)) {
        QString str = "<i><font color=\"green\">Successfully Disconnected</font></i>";
        ui->logScreen->append(str);
    } else {
        QString str = "<i><font color=\"red\">Disconnection Refused</font></i>";
        ui->logScreen->append(str);
    }

}

void MainWindow::doConnection() {

    QStringList server = ui->server->text().split(QRegExp("[:]"), QString::SkipEmptyParts);

    QString serverIP = server[0];
    QString serverPort = server[1];

    tcpConnect(serverIP, serverPort.toInt());
}

void MainWindow::doDisconnection() {

    tcpDisconnect();
}

void MainWindow::setRandonNumber() {
    QDateTime datetime;
    QString str;
    qint64 msecdate;
    
    msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();
    str = "set " + 
        QString::number(msecdate) + " " +
        QString::number((qrand() % max) + min)
    ;

    ui->logScreen->append(str);

    socket->write(str.toStdString().c_str());
        
    if(socket->waitForBytesWritten(3000)) {
        qDebug() << "Data Written";
    } else {
        //qDebug() << "Error Writing Data";
        QString str = "<i><font color=\"red\">Error Writing Data</font></i>";

        ui->logScreen->append(str);
    }
}

void MainWindow::timerEvent(QTimerEvent *event) {

    if(socket->isOpen()) {
        setRandonNumber();
    } else {
        QString str = "<i><font color=\"red\">Server not connected</font></i>";
        ui->logScreen->append(str);
    }
    
}

void MainWindow::start() {
    killTimer(temporizador);

    QString str = "<i><font color=\"green\">Starting ...</font></i>";
    ui->logScreen->append(str);

    temporizador = startTimer(timing * 1000);
}

void MainWindow::stop() {

    QString str = "<i><font color=\"red\">Stopping ...</font></i>";
    ui->logScreen->append(str);

    killTimer(temporizador);

}

void MainWindow::changeMin(int _min) {
    min = _min;
}

void MainWindow::changeMax(int _max) {
    max = _max;
}

void MainWindow::changeTiming(int _timing) {
    timing = _timing;
}

MainWindow::~MainWindow() {
    delete socket;
    delete ui;
}
