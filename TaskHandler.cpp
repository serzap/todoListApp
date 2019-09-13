#include "TaskHandler.hpp"

TaskHandler *TaskHandler::theModel = nullptr;

TaskHandler::TaskHandler()
{

}

TaskHandler *TaskHandler::getInstance()
{
    if (!theModel) theModel = new TaskHandler();
    return theModel;
}

void TaskHandler::addNewTask(Task task){

    if (!theModel) theModel = new TaskHandler();
    theModel->mTaskList.push_back(task);
    emit newTaskAdded(theModel->getTaskList());
}

std::vector<Task> TaskHandler::getTaskList() const
{
    return mTaskList;
}

void TaskHandler::setTaskList(const std::vector<Task> &taskList)
{
    mTaskList = taskList;
}
