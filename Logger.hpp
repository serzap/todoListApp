#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <QLoggingCategory>
#include <QFile>

Q_DECLARE_LOGGING_CATEGORY(logCtrl);
Q_DECLARE_LOGGING_CATEGORY(logUI);


class Logger
{
public:
    static Logger& getInstance();

    Logger(const Logger&) = delete;
    void operator=(const Logger&) = delete;

    static void messageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg);
    static QFile* logFile;
private:
    Logger(QString logFilePath);
    ~Logger();
};

#endif // LOGGER_HPP
