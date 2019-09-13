#include "Application.hpp"


Application::Application() : mainWindow(new MainWindow()),
    newTaskWindow(new NewTaskWindow())
{
    theHandler = TaskHandler::getInstance();

    QObject::connect(newTaskWindow, &NewTaskWindow::newTaskCreated,
                     theHandler, &TaskHandler::addNewTask);
    QObject::connect(theHandler, &TaskHandler::newTaskAdded,
                     mainWindow, &MainWindow::updateTaskList);
    QObject::connect(newTaskWindow, &NewTaskWindow::newTaskCreated,
                     mainWindow, &MainWindow::show);
    QObject::connect(mainWindow, &MainWindow::newTaskButtonClicked,
                     newTaskWindow, &NewTaskWindow::show);
    mainWindow->show();
}

Application::~Application()
{
    if (theHandler) delete theHandler;
    if (mainWindow) delete mainWindow;
    if (newTaskWindow) delete newTaskWindow;
}
