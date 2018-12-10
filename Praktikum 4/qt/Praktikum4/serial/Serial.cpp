#include "Serial.h"


#include <QtSerialPort/QSerialPort>
#include <QDebug>

Serial::Serial()
{
    m_serialPort = new QSerialPort();
}

Serial::~Serial()
{
    close();
}

void Serial::write(char* command, int length)
{
    const qint64 bytesWritten = m_serialPort->write(command, length);
    if (bytesWritten != length){
        qDebug() << "Error while sending bytes";
    }
}

void Serial::read(char* receive, int length)
{
    m_serialPort->read(receive, length);
}

void Serial::close()
{
    if (m_serialPort->isOpen())
        m_serialPort->close();
}

bool Serial::open()
{
    m_serialPort->setPortName("COM1");
    m_serialPort->setBaudRate(QSerialPort::Baud9600);
    if (m_serialPort->open(QIODevice::ReadWrite)){
//        showStatusMessage("connected");
        return true;
    } else
        return false;
}


SerialDummy::SerialDummy()
{

}

SerialDummy::~SerialDummy()
{

}
