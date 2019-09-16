#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "TaskHandler.hpp"
#include "Logger.hpp"
#include "MainWindow.hpp"
#include "NewTaskWindow.hpp"
#include <QObject>
#include <QTimer>

class Application
{
public:
    Application();
    ~Application();
private:
    TaskHandler& mTaskHandler;
    Logger& mLogger;
    MainWindow mMainWindow;
    NewTaskWindow mNewTaskWindow;
};

#endif // APPLICATION_HPP
