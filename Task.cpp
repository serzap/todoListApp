#include "Task.hpp"
#include "Logger.hpp"

int Task::ID = 0;

Task::Task()
    : mCurrentId(ID++)
    , mDescription("")
{
    qDebug(logCtrl()) << Q_FUNC_INFO;
}

Task::Task(const QString& description)
    : mCurrentId(ID++)
    , mDescription(description)
{
    qDebug(logCtrl()) << Q_FUNC_INFO;
}

bool Task::getStatus() const
{
    qDebug(logCtrl()) << Q_FUNC_INFO;
    return mStatus;
}

void Task::setStatus(bool status)
{
    qDebug(logCtrl()) << Q_FUNC_INFO;
    mStatus = status;
}

const QString& Task::getDescription() const
{
    qDebug(logCtrl()) << Q_FUNC_INFO;
    return mDescription;
}

void Task::setDescription(const QString &description)
{
    qDebug(logCtrl()) << Q_FUNC_INFO;
    mDescription = description;
}

const QDateTime& Task::getDeadline() const
{
    qDebug(logCtrl()) << Q_FUNC_INFO;
    return mDeadline;
}

void Task::setDeadline(const QDateTime& deadline)
{
    qDebug(logCtrl()) << Q_FUNC_INFO;
    mDeadline = deadline;
}
