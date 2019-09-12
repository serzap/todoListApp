#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , mUI(new Ui::MainWindow)
{
    mUI->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete mUI;
    delete mNewTaskWindow;
}

void MainWindow::addRelatedWindow(NewTaskWindow* related)
{
    mNewTaskWindow = related;
    QObject::connect(mNewTaskWindow, &NewTaskWindow::newTaskCreated,
                     this, &MainWindow::show);
}

void MainWindow::on_pushButton_NewTask_clicked()
{
    mNewTaskWindow->show();
}

void MainWindow::addNewTask(TaskInfo taskInfo)
{
    mUI->listWidget_Tasks->addItem(taskInfo.getDescription());
}
