#include "CModel.hpp"

CModel *CModel::theModel = nullptr;

CModel::CModel()
{

}

CModel *CModel::getInstance()
{
    if (!theModel) theModel = new CModel();
    return theModel;
}

void CModel::addNewTask(CTask task){

    if (!theModel) theModel = new CModel();
    theModel->mTaskList.push_back(task);
    emit newTaskAdded(task);
}
