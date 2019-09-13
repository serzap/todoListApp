#include "CTask.hpp"

CTask::CTask()
    : mDescription("")
{

}

CTask::CTask(std::string description)
    : mDescription(description)
{

}

bool CTask::getStatus() const
{
    return mStatus;
}

void CTask::setStatus(bool status)
{
    mStatus = status;
}

std::string CTask::getDescription() const
{
    return mDescription;
}

void CTask::setDescription(const std::string &description)
{
    mDescription = description;
}
