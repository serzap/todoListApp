#include "NewTaskWindow.hpp"
#include "ui_NewTaskWindow.h"
#include "Logger.hpp"

NewTaskWindow::NewTaskWindow(QWidget* parent)
    : QWidget(parent)
    , mUI(new Ui::NewTaskWindow)
    , mTaskInfo()
{
    qDebug(logUI()) << Q_FUNC_INFO;
    mUI->setupUi(this);
}

NewTaskWindow::~NewTaskWindow()
{
    qDebug(logUI()) << Q_FUNC_INFO;
    delete mUI;
}

void NewTaskWindow::on_pushButton_taskCreated_clicked()
{
    qDebug(logUI()) << Q_FUNC_INFO;
    QString description = mUI->lineEdit_TaskDescription->text();
    mTaskInfo.setDescription(description);
    mTaskInfo.setDeadline(mUI->dateTimeEdit->dateTime());
    mUI->lineEdit_TaskDescription->clear();
    this->close();
    emit newTaskCreated(mTaskInfo);
}
