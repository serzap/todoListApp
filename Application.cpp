#include "Application.hpp"

Application::Application()
    : mTaskHandler(TaskHandler::getInstance())
    , mLogger(Logger::getInstance())
    , mMainWindow()
    , mNewTaskWindow()
{
    QTimer timer(&mMainWindow);
    QObject::connect(&timer, &QTimer::timeout, &mMainWindow, [this]{ mMainWindow.updateTaskList(mTaskHandler.getTaskList()); });
    timer.start(1000);
    QObject::connect(&mNewTaskWindow, &NewTaskWindow::newTaskCreated,
                     &mTaskHandler, &TaskHandler::addNewTask);
    QObject::connect(&mTaskHandler, &TaskHandler::newTaskAdded,
                     &mMainWindow, &MainWindow::updateTaskList);
    QObject::connect(&mNewTaskWindow, &NewTaskWindow::newTaskCreated,
                     &mMainWindow, &MainWindow::show);
    QObject::connect(&mMainWindow, &MainWindow::newTaskButtonClicked,
                     &mNewTaskWindow, &NewTaskWindow::show);
    mMainWindow.show();
}

Application::~Application()
{

}
