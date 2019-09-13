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

void MainWindow::on_pushButton_DeleteTask_clicked()
{
    this->deleteSelected();
}

void MainWindow::deleteSelected()
{
    QListWidgetItem *it = mUI->listWidget_Tasks->takeItem(mUI->listWidget_Tasks->currentRow());
    delete it;
}

void MainWindow::addNewTask(const CTask &task)
{

    QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(task.getDescription()));
    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
    item->setCheckState(Qt::Unchecked); // Creating task has unchecked state by default
    mUI->listWidget_Tasks->addItem(item);
}
