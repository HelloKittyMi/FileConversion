#ifndef LOGGER_H
#define LOGGER_H


#include <QFile>
#include <QString>

typedef enum
{
    LOG_LEVEL_ERR = 0,
    LOG_LEVEL_WRN = 1,
    LOG_LEVEL_INF = 2,
    LOG_LEVEL_DBG = 3
}E_LOG_LEVEL;


#define LOG_ERR(X,...) Logger::Instance()->WriteLog(__FILE__, __func__, __LINE__, LOG_LEVEL_ERR, X, ##__VA_ARGS__)
#define LOG_WRN(X,...) Logger::Instance()->WriteLog(__FILE__, __func__, __LINE__, LOG_LEVEL_WRN, X, ##__VA_ARGS__)
#define LOG_INF(X,...) Logger::Instance()->WriteLog(__FILE__, __func__, __LINE__, LOG_LEVEL_INF, X, ##__VA_ARGS__)
#define LOG_DBG(X,...) Logger::Instance()->WriteLog(__FILE__, __func__, __LINE__, LOG_LEVEL_DBG, X, ##__VA_ARGS__)
#define LOG_CAR_INF(X) Logger::Instance()->WriteDbgCarInfo(X)

//void CreateDbTbl(sqlite3 *dbPtr);

class Logger
{
public:
    ~Logger();
    static Logger* Instance();
    void WriteLog(const char* fileNamePtr, const char* funcNamePtr,
                  int lineNum, E_LOG_LEVEL level, const char* format, ...);
    void SetLogLevel(E_LOG_LEVEL level);
//    void UdpLog(char* pBuff, int len);
private:
    Logger();

private:
    static Logger *m_loggerPtr;
    char *m_buffPtr;
    QString m_logFilename;
    QFile m_logFile;
    QString m_logWrnFileName;
    QFile m_logWrnFile;
    int m_sd;
};

#endif // LOGGER_H
