#include "MainWindow.hpp"
#include <QDebug>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , mUI(new Ui::MainWindow)
{
    mUI->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete mUI;
}

void MainWindow::on_pushButton_NewTask_clicked()
{
    emit newTaskButtonClicked();
}

void MainWindow::updateTaskList(const std::vector<Task>& list)
{
    mUI->listWidget_Tasks->clear();
    for (auto task = list.begin(); task != list.end(); task++)
    {
        qDebug() << "update task " << task->getDescription();
        updateTask(*task);
    }
}

void MainWindow::updateTask(const Task& task)
{
    QString itemInfo = QString(task.getDescription()+'\t' + task.getDeadline().toString("dd.MM.yyyy hh:mm"));
    QListWidgetItem* item = new QListWidgetItem(itemInfo);
    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
    item->setCheckState(Qt::Unchecked);
    if (QDateTime::currentDateTime() > task.getDeadline())
    {
        item->setForeground(Qt::red);
    }
    mUI->listWidget_Tasks->addItem(item);
}
