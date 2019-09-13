#include "Application.hpp"


Application::Application() : mainWindow(new MainWindow()),
    newTaskWindow(new NewTaskWindow()), currentTaskWindow(new CurrentTaskWindow())
{
    theHandler = TaskHandler::getInstance();
    QTimer *timer = new QTimer(mainWindow);
    QObject::connect(timer, &QTimer::timeout, mainWindow, [this]{ mainWindow->updateTaskList(theHandler->getTaskList()); });
    timer->start(10000);
    QObject::connect(newTaskWindow, &NewTaskWindow::newTaskCreated,
                     theHandler, &TaskHandler::addNewTask);
    QObject::connect(theHandler, &TaskHandler::needToBeUpdated,
                     mainWindow, &MainWindow::updateTaskList);
    QObject::connect(newTaskWindow, &NewTaskWindow::newTaskCreated,
                     mainWindow, &MainWindow::show);
    QObject::connect(mainWindow, &MainWindow::newTaskButtonClicked,
                     newTaskWindow, &NewTaskWindow::show);
    QObject::connect(mainWindow, &MainWindow::getTaskInfo, currentTaskWindow,
                     [this]{ currentTaskWindow->initializeWith(theHandler->getTask(mainWindow->currentRow())); });
    QObject::connect(mainWindow, &MainWindow::getTaskInfo, currentTaskWindow,
                     &CurrentTaskWindow::show);
    QObject::connect(currentTaskWindow, &CurrentTaskWindow::returnToMain, mainWindow, &MainWindow::show);
    QObject::connect(currentTaskWindow, &CurrentTaskWindow::itemToBeDeleted, theHandler,
                     [this]{ theHandler->deleteRow(mainWindow->currentRow()); });
    QObject::connect(currentTaskWindow, &CurrentTaskWindow::itemToBeAdded, theHandler, &TaskHandler::addNewTask);
    mainWindow->show();
}

Application::~Application()
{
    if (theHandler) delete theHandler;
    if (mainWindow) delete mainWindow;
    if (newTaskWindow) delete newTaskWindow;
    if (currentTaskWindow) delete currentTaskWindow;
}
