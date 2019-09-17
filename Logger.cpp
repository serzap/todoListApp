#include "Logger.hpp"
#include <QDateTime>

Q_LOGGING_CATEGORY(logCtrl, "Controller");
Q_LOGGING_CATEGORY(logUI, "UI");


QFile* Logger::logFile = nullptr;

Logger::Logger(QString logFilePath)
{
    logFile = new QFile(logFilePath);
    logFile->open(QFile::Append | QFile::Text);
    qInstallMessageHandler(messageHandler);
}

Logger::~Logger()
{
    delete logFile;
}

Logger& Logger::getInstance()
{
    //try to add to resources files in future
    static Logger logger("../ToDoListApp/LogFile.txt");
    return logger;
}

void Logger::messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QTextStream out(logFile);
    out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz ");
    switch (type)
    {
        case QtInfoMsg:     out << "INF "; break;
        case QtDebugMsg:    out << "DBG "; break;
        case QtWarningMsg:  out << "WRN "; break;
        case QtCriticalMsg: out << "CRT "; break;
        case QtFatalMsg:    out << "FTL "; break;
    }
    out << context.category << ": " << msg <<endl;
    out.flush();
}

