#include <QObject>
#include <CModel.hpp>
#include "MainWindow.hpp"
#include "NewTaskWindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NewTaskWindow newTaskWindow;
    MainWindow mainWindow;
    CModel * myModel = CModel::getInstance();

    mainWindow.addRelatedWindow(&newTaskWindow);

    QObject::connect(&newTaskWindow, SIGNAL(newTaskCreated(CTask)),
                     myModel, SLOT(addNewTask(CTask)));
    QObject::connect(myModel, SIGNAL(newTaskAdded(const CTask&)),
                     &mainWindow, SLOT(addNewTask(const CTask&)));

    mainWindow.show();
    return a.exec();
}
