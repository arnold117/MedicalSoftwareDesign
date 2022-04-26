#ifndef MYSERIALPORT_H
#define MYSERIALPORT_H

#include <QObject>
#include <QtSerialPort/QSerialPort>

class MySerialPort : public QObject
{
    Q_OBJECT
public:
    explicit MySerialPort(QObject *parent = nullptr);
    ~MySerialPort();

    Q_INVOKABLE bool serialConnect(QString port, QString baudrate,
                                   QString databits, QString parity,
                                   QString stopbits);
    Q_INVOKABLE QString serialRead();
    Q_INVOKABLE bool serialWrite(QString sendStr);

signals:

public slots:

private:
    QSerialPort *m_serial;

};

#endif // MYSERIALPORT_H
