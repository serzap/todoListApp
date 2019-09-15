#include "Task.hpp"


int Task::ID = 0;

Task::Task()
    : mCurrentId(ID++)
    , mDescription("")
{

}

Task::Task(const QString& description)
    : mCurrentId(ID++)
    , mDescription(description)
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

const QString& Task::getDescription() const
{
    return mDescription;
}

void Task::setDescription(const QString &description)
{
    mDescription = description;
}

const QDateTime& Task::getDeadline() const
{
    return mDeadline;
}

void Task::setDeadline(const QDateTime& deadline)
{
    mDeadline = deadline;
}
