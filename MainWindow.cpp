#include "MainWindow.hpp"
#include <QDebug>
#include "Logger.hpp"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , mUI(new Ui::MainWindow)
{
    qDebug(logUI()) << Q_FUNC_INFO;

    mUI->setupUi(this);
}

MainWindow::~MainWindow()
{
    qDebug(logUI()) << Q_FUNC_INFO;

    delete mUI;
}

void MainWindow::on_pushButton_NewTask_clicked()
{
    qDebug(logUI()) << Q_FUNC_INFO;

    emit newTaskButtonClicked();
}

void MainWindow::updateTaskList(const std::vector<Task>& list)
{
    qDebug(logUI()) << Q_FUNC_INFO;

    mUI->listWidget_Tasks->clear();
    for (auto task = list.begin(); task != list.end(); task++)
    {
        updateTask(*task);
    }
}

void MainWindow::updateTask(const Task& task)
{
    qDebug(logUI()) << Q_FUNC_INFO;

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
