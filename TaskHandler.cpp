#include "TaskHandler.hpp"
#include "Logger.hpp"

TaskHandler& TaskHandler::getInstance()
{
    qDebug(logCtrl()) << Q_FUNC_INFO;
    static TaskHandler instance;
    return instance;
}

void TaskHandler::addNewTask(const Task& task)
{
    qDebug(logCtrl()) << Q_FUNC_INFO;
    mTaskList.push_back(task);
    emit newTaskAdded(mTaskList);
}

const std::vector<Task>& TaskHandler::getTaskList() const
{
    qDebug(logCtrl()) << Q_FUNC_INFO;
    return mTaskList;
}

void TaskHandler::setTaskList(const std::vector<Task> &taskList)
{
    qDebug(logCtrl()) << Q_FUNC_INFO;
    mTaskList = taskList;
}
