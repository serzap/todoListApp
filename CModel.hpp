#ifndef CMODEL_HPP
#define CMODEL_HPP
#include <vector>
#include <QObject>
#include "CTask.hpp"

class CModel : public QObject
{
    Q_OBJECT
public:
    CModel();
    static CModel *getInstance();

public slots:
    void addNewTask(CTask task);

signals:
    void newTaskAdded(const CTask &task);

private:
    std::vector<CTask> mTaskList;
    static CModel *theModel;  //CModel implements singleton pattern
};

#endif // CMODEL_HPP
