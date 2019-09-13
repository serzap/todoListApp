#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , mUI(new Ui::MainWindow)
{
    mUI->setupUi(this);
    QObject::connect(mUI->listWidget_Tasks, &QListWidget::itemClicked, this, &MainWindow::taskInfoClicked);
}

MainWindow::~MainWindow()
{
    delete mUI;
}

int MainWindow::currentRow()
{
    return mUI->listWidget_Tasks->currentRow();
}

void MainWindow::on_pushButton_NewTask_clicked()
{
    emit newTaskButtonClicked();
}

void MainWindow::taskInfoClicked()
{
    emit getTaskInfo();
}


QListWidgetItem *MainWindow::getListItem(const Task &task)
{
     QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(task.getDescription().toStdString())+'\t'+task.getDeadline().toString("dd.MM.yyyy hh:mm"));

     item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
     item->setCheckState(Qt::Unchecked); // Creating task has unchecked state by default
     if (QDateTime::currentDateTime()>task.getDeadline()) item->setForeground(Qt::red);
     return item;
}

void MainWindow::updateTaskList(const std::vector<Task> &list)
{
    mUI->listWidget_Tasks->clear();
    for (auto task = list.begin(); task != list.end(); task++) {
        mUI->listWidget_Tasks->addItem(getListItem(*task));
    }
}
