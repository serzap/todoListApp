#include <QObject>
#include "MainWindow.hpp"
#include "NewTaskWindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NewTaskWindow newTaskWindow;
    MainWindow mainWindow;
    mainWindow.addRelatedWindow(&newTaskWindow);

    QObject::connect(&newTaskWindow, &NewTaskWindow::newTaskCreated,
                     &mainWindow, &MainWindow::addNewTask);
    mainWindow.show();
    return a.exec();
}
