#include "CurrentTaskWindow.hpp"
#include "ui_CurrentTaskWindow.h"

CurrentTaskWindow::CurrentTaskWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CurrentTaskWindow)
{
    ui->setupUi(this);
}

CurrentTaskWindow::~CurrentTaskWindow()
{
    delete ui;
}

void CurrentTaskWindow::initializeWith(const Task &task)
{
    ui->lineEdit_name->setText(task.getDescription());
    ui->dateTimeEdit->setDateTime(task.getDeadline());
}

void CurrentTaskWindow::on_pushButton_Back_clicked()
{
    this->close();
    emit returnToMain();
}

void CurrentTaskWindow::on_pushButton_Save_clicked()
{
    this->close();
    emit itemToBeDeleted();
    Task item;
    item.setDescription(ui->lineEdit_name->text());
    item.setDeadline(ui->dateTimeEdit->dateTime());
    emit itemToBeAdded(item);
    emit returnToMain();
}

void CurrentTaskWindow::on_pushButton_Delete_clicked()
{
    this->close();
    emit itemToBeDeleted();
    emit returnToMain();
}
