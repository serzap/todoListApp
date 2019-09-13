#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "TaskHandler.hpp"
#include "MainWindow.hpp"
#include "NewTaskWindow.hpp"
#include "CurrentTaskWindow.hpp"
#include <QObject>
#include <QTimer>

class Application
{
public:
    Application();
    ~Application();
private:
    TaskHandler * theHandler;
    MainWindow * mainWindow;
    NewTaskWindow * newTaskWindow;
    CurrentTaskWindow * currentTaskWindow;
};

#endif // APPLICATION_HPP
