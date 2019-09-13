#include "MainWindow.hpp"

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

QListWidgetItem *MainWindow::getListItem(const Task &task)
{
     QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(task.getDescription())+'\t'+task.getDeadline().toString("dd.MM.yyyy hh:mm"));

     item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
     item->setCheckState(Qt::Unchecked); // Creating task has unchecked state by default
     //item->setForeground(Qt::red);
     return item;
}

void MainWindow::updateTaskList(const std::vector<Task> &list)
{
    mUI->listWidget_Tasks->clear();
    for (auto task = list.begin(); task != list.end(); task++) {
        mUI->listWidget_Tasks->addItem(getListItem(*task));
    }
}
