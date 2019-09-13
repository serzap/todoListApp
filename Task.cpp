#include "Task.hpp"

Task::Task()
    : mDescription("")
{

}

Task::Task(std::string description)
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

std::string Task::getDescription() const
{
    return mDescription;
}

void Task::setDescription(const std::string &description)
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
