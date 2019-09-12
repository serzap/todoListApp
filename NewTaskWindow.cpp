#include "NewTaskWindow.hpp"
#include "ui_NewTaskWindow.h"

NewTaskWindow::NewTaskWindow(QWidget* parent) :
    QWidget(parent),
    mUI(new Ui::NewTaskWindow)
{
    mUI->setupUi(this);
}

NewTaskWindow::~NewTaskWindow()
{
    delete mUI;
}

void NewTaskWindow::on_pushButton_taskCreated_clicked()
{
    QString description = mUI->lineEdit_TaskDescription->text();
    mTaskInfo.setDescription(description);
    this->close();
    emit newTaskCreated(mTaskInfo);
}
