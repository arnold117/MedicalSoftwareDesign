#include "myserialport.h"

MySerialPort::MySerialPort(QObject *parent)
    : QObject{parent}
{
    m_serial = new QSerialPort;
}

bool MySerialPort::serialConnect(QString port, QString baudrate,
                                 QString databits, QString parity,
                                 QString stopbits)
{
    m_serial->setPortName(port);
    if(!m_serial->open(QIODevice::ReadWrite))
    {
        printf("Open Error");
        return false;
    }

    switch(baudrate.toInt())
    {
    case 1200:
        m_serial->setBaudRate(QSerialPort::Baud1200);
        break;
    case 2400:
        m_serial->setBaudRate(QSerialPort::Baud2400);
        break;
    case 4800:
        m_serial->setBaudRate(QSerialPort::Baud4800);
        break;
    case 9600:
        m_serial->setBaudRate(QSerialPort::Baud9600);
        break;
    case 19200:
        m_serial->setBaudRate(QSerialPort::Baud19200);
        break;
    case 38400:
        m_serial->setBaudRate(QSerialPort::Baud38400);
        break;
    case 57600:
        m_serial->setBaudRate(QSerialPort::Baud57600);
        break;
    case 115200:
        m_serial->setBaudRate(QSerialPort::Baud115200);
        break;
    default:
        printf("BaudRate Error");
        return false;
    }

    switch(databits.toInt())
    {
    case 5:
        m_serial->setDataBits(QSerialPort::Data5);
        break;
    case 6:
        m_serial->setDataBits(QSerialPort::Data6);
        break;
    case 7:
        m_serial->setDataBits(QSerialPort::Data7);
        break;
    case 8:
        m_serial->setDataBits(QSerialPort::Data8);
        break;
    default:
        printf("DataBits Error");
        return false;
    }

    switch(parity.toInt())
    {
    case 0:
        m_serial->setParity(QSerialPort::NoParity);
        break;
    case 2:
        m_serial->setParity(QSerialPort::EvenParity);
        break;
    case 3:
        m_serial->setParity(QSerialPort::OddParity);
        break;
    default:
        printf("Parity Error");
        return false;
    }

    switch(stopbits.toInt())
    {
    case 1:
        m_serial->setStopBits(QSerialPort::OneStop);
        break;
    case 2:
        m_serial->setStopBits(QSerialPort::TwoStop);
        break;
    case 3:
        m_serial->setStopBits(QSerialPort::OneAndHalfStop);
        break;
    default:
        printf("StopBits Error");
        return false;
    }

    m_serial->setFlowControl(QSerialPort::NoFlowControl);
    return true;
}

QString MySerialPort::serialRead()
{
    return m_serial->readAll();
}

bool MySerialPort::serialWrite(QString sendStr)
{
    if(m_serial->write(sendStr.toLatin1().data(), strlen(sendStr.toLatin1().data())))
    {
        return true;
    }

    return false;
}

MySerialPort::~MySerialPort()
{
    if(m_serial->isOpen())
    {
        m_serial->clear();
        m_serial->close();
    }
    m_serial->deleteLater();
}
