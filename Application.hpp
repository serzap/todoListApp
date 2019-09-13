#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "TaskHandler.hpp"
#include "MainWindow.hpp"
#include "NewTaskWindow.hpp"
#include <QObject>

class Application
{
public:
    Application();
    ~Application();
private:
    TaskHandler * theHandler;
    MainWindow * mainWindow;
    NewTaskWindow * newTaskWindow;
};

#endif // APPLICATION_HPP
