#include "Task.hpp"

Task::Task()
    : mDescription("")
{

}

Task::Task(QString description)
    : mDescription(description)
{

}

bool Task::getStatus() const
{
    return mStatus;
}

void Task::setStatus(bool status)
{
    mStatus = status;
}

QString Task::getDescription() const
{
    return mDescription;
}

void Task::setDescription(const QString &description)
{
    mDescription = description;
}

QDateTime Task::getDeadline() const
{
    return mDeadline;
}

void Task::setDeadline(const QDateTime &deadline)
{
    mDeadline = deadline;
}
