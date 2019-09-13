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

void TaskHandler::addNewTask(const Task &task){

    if (!theModel) theModel = new TaskHandler();
    theModel->mTaskList.push_back(task);
    emit needToBeUpdated(theModel->getTaskList());
}

void TaskHandler::deleteRow(int row)
{
   theModel->mTaskList.erase(mTaskList.begin()+row);
   emit needToBeUpdated(theModel->getTaskList());
}

std::vector<Task> TaskHandler::getTaskList() const
{
    return mTaskList;
}

const Task & TaskHandler::getTask(int row){
    return mTaskList[row];
}

void TaskHandler::setTaskList(const std::vector<Task> &taskList)
{
    mTaskList = taskList;
}
