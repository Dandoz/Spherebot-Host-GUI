#include "rxthread.h"

rxThread::rxThread(spherebot *uibot)
{
    bot = uibot;
}

rxThread::~rxThread()
{

}
void rxThread::receiveData()
{
    if(bot->port->canReadLine())
    {
        line = bot->port->readLine(1024);
        line.chop(1);
        qDebug()<<"receiving: " << line << endl;/////////////////////////////
        emit lineReceived(line);
    }
}

void rxThread::run()
{
    qDebug()<<"start Receiver";
    line = "";
}
