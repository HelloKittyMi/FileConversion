#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//#include <netdb.h>
#include <iostream>
#include <QString>
#include <QDateTime>
#include "stdio.h"
#include "Logger.h"
#include <unistd.h>

#define LOG_BUFF_SIZE 4096
#define LOG_DB_VERSION "1.1.0"


E_LOG_LEVEL gLogLevel = LOG_LEVEL_DBG;
int gCarInfoLogEnable = 0;
int gUdpLogEnable = 0;
QString gUdpLogDstIp("192.168.62.17");
int gUdpLogDstPort = 30000;

Logger *Logger::m_loggerPtr = NULL;

Logger::Logger()
{
    m_buffPtr = new char[LOG_BUFF_SIZE];
#ifdef Q_OS_WIN32
    m_logFilename = "E:/log.txt";
    m_logWrnFileName = "logWarning.txt";
#else
    m_logFilename = "/DCM/parking/log.txt";
    m_logWrnFileName = "/DCM/parking/logWarning.txt";
#endif
    m_logFile.setFileName(m_logFilename);
    m_logWrnFile.setFileName(m_logWrnFileName);
}

Logger::~Logger()
{
    delete [] m_buffPtr;
    close(m_sd);
}

Logger* Logger::Instance()
{
    if(NULL == m_loggerPtr)
    {
        m_loggerPtr = new Logger();
    }
    return m_loggerPtr;
}

void Logger::WriteLog(const char* fileNamePtr, const char* funcNamePtr,
                      int lineNum, E_LOG_LEVEL level, const char* format, ...)
{
    if(level > gLogLevel)
    {
        return;
    }

    QString logLevelStr;
    switch(level)
    {
        case LOG_LEVEL_ERR:
            logLevelStr.append("ERR");
            break;
        case LOG_LEVEL_WRN:
            logLevelStr.append("WRN");
            break;
        case LOG_LEVEL_INF:
            logLevelStr.append("INF");
            break;
        case LOG_LEVEL_DBG:
            logLevelStr.append("DBG");
            break;
        default:
            logLevelStr.append("DBG");
    }

    QDateTime dateTime = QDateTime::currentDateTime();
    QString dateTimeStr = dateTime.toString("yyyy/MM/dd hh:mm:ss:zzz");

    /* 组调试信息头 */
    int logLength = sprintf(m_buffPtr, "[%s][%s][%s]: [%s] ",
                            dateTimeStr.toUtf8().data(),fileNamePtr, funcNamePtr,logLevelStr.toUtf8().data());

    va_list valst;
    va_start(valst, format);
    logLength += vsprintf(&m_buffPtr[logLength], format, valst);
    m_buffPtr[logLength] = 0x00;
    printf("%s", m_buffPtr);

    /* log to file */
    va_end(valst);
    m_logFile.open(QIODevice::Append|QIODevice::WriteOnly);
    m_logFile.write(m_buffPtr);
    m_logFile.flush();
    m_logFile.close();
    if(level <= LOG_LEVEL_WRN){
        m_logWrnFile.open(QIODevice::Append|QIODevice::WriteOnly);
        m_logWrnFile.write(m_buffPtr);
        m_logWrnFile.flush();
        m_logWrnFile.close();
    }
    /* log to udp */
    if(0 != gUdpLogEnable)
    {
//        UdpLog(m_buffPtr, logLength);
    }
}


void Logger::SetLogLevel(E_LOG_LEVEL level)
{
    gLogLevel = level;
}

//void Logger::UdpLog(char* pBuff, int len)
//{
//    sendto(m_sd, pBuff, len, 0, (struct sockaddr *)&m_address, sizeof(m_address));
//}

/* END OF FILE */
