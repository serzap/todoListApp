#ifndef TASKHANDLER_HPP
#define TASKHANDLER_HPP
#include <vector>
#include <QObject>
#include "Task.hpp"

class TaskHandler : public QObject
{
    Q_OBJECT
public:
    TaskHandler();
    static TaskHandler *getInstance();

    std::vector<Task> getTaskList() const;
    void setTaskList(const std::vector<Task> &taskList);

public slots:
    void addNewTask(const Task &task);


signals:
    void newTaskAdded(const std::vector<Task> &list);


private:
    std::vector<Task> mTaskList;
    static TaskHandler *theModel;  //TaskHandler implements singleton pattern
};

#endif // TASKHANDLER_HPP
