#include "CurrentTaskWindow.hpp"
#include "ui_CurrentTaskWindow.h"

CurrentTaskWindow::CurrentTaskWindow(QWidget *parent) :
    QWidget(parent), mUI(new Ui::CurrentTaskWindow)
{

}

void CurrentTaskWindow::on_pushButton_toBeDeleted_clicked()
{
    emit taskToBeDeleted(this->mTask);
}
