#include "Serial.h"


#include <QtSerialPort/QSerialPort>
#include <QDebug>

Serial::Serial()
{

}

Serial::~Serial()
{
    m_serialPort->close();
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
    m_serialPort->close();
}

bool Serial::open()
{
    m_serialPort->open();
    return true;
}


SerialDummy::SerialDummy()
{

}

SerialDummy::~SerialDummy()
{

}
