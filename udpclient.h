#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QWidget>
#include "QtNetwork"

QT_BEGIN_NAMESPACE
namespace Ui { class UDPClient; }
QT_END_NAMESPACE

class UDPClient : public QWidget
{
    Q_OBJECT

public:
    UDPClient(QWidget *parent = nullptr);
    ~UDPClient();

private slots:
    void on_pushButton_Send_clicked();

private:
    Ui::UDPClient *ui;

    // UDP Client
    QUdpSocket *mSocket;
};
#endif // UDPCLIENT_H
