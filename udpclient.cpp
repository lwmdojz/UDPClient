#include "udpclient.h"
#include "ui_udpclient.h"

UDPClient::UDPClient(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UDPClient)
{
    // 1. Creat QUdpSocket object
    mSocket = new QUdpSocket(this);

    QObject::connect(mSocket, &QUdpSocket::readyRead, this, [&]()
    {
        QHostAddress addr;
        quint16 port;

        // Data buffer
        QByteArray arr;
        // Adjust array size to data received
        arr.resize(mSocket->bytesAvailable());

        // receive data
        mSocket->readDatagram(arr.data(), arr.size(), &addr, &port);
        // show data
        ui->textBrowser->setPlainText(addr.toString() + ':' + QString(arr) + '\n');
        // connect Enter key pressed signal and slot
    });

    ui->setupUi(this);

    QObject::connect(ui->lineEdit_SendMessage, &QLineEdit::returnPressed, this, &UDPClient::on_pushButton_Send_clicked);
}

UDPClient::~UDPClient()
{
    delete ui;
}


void UDPClient::on_pushButton_Send_clicked()
{
    // get data that to be sent
    QByteArray arr = ui->lineEdit_SendMessage->text().toUtf8();

    // send data
    mSocket->writeDatagram(arr, QHostAddress(ui->lineEdit_ip->text()), ui->spinBox_Port->value());
    // show send content
    ui->textBrowser->insertPlainText("Send: " + QString(arr) + "\n");
    // clear send lineEdit
    ui->lineEdit_SendMessage->clear();

}

