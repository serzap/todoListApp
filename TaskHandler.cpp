#include "TaskHandler.hpp"

TaskHandler& TaskHandler::getInstance()
{
    static TaskHandler instance;
    return instance;
}

void TaskHandler::addNewTask(const Task& task)
{
    mTaskList.push_back(task);
    emit newTaskAdded(mTaskList);
}

const std::vector<Task>& TaskHandler::getTaskList() const
{
    return mTaskList;
}

void TaskHandler::setTaskList(const std::vector<Task> &taskList)
{
    mTaskList = taskList;
}
