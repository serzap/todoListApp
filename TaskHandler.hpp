#ifndef TASKHANDLER_HPP
#define TASKHANDLER_HPP
#include <vector>
#include <QObject>
#include "Task.hpp"

class TaskHandler : public QObject
{
    Q_OBJECT
public:
    static TaskHandler& getInstance();

    TaskHandler(const TaskHandler&) = delete;
    void operator=(const TaskHandler&) = delete;

    const std::vector<Task>& getTaskList() const;
    void setTaskList(const std::vector<Task>& taskList);

private:
    TaskHandler(){}

public slots:
    void addNewTask(const Task &task);

signals:
    void newTaskAdded(const std::vector<Task> &list);

private:
    std::vector<Task> mTaskList;
};

#endif // TASKHANDLER_HPP
