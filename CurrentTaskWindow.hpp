#ifndef CURRENTTASKWINDOW_HPP
#define CURRENTTASKWINDOW_HPP

#include <QDialog>
#include "Task.hpp"

namespace Ui {
class CurrentTaskWindow;
}

class CurrentTaskWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CurrentTaskWindow(QWidget *parent = nullptr);
    ~CurrentTaskWindow();

public slots:
    void initializeWith(const Task & task);

private slots:
    void on_pushButton_Back_clicked();
    void on_pushButton_Save_clicked();
    void on_pushButton_Delete_clicked();

signals:
    void itemToBeDeleted();
    void itemToBeAdded(const Task & task);
    void returnToMain();

private:
    Ui::CurrentTaskWindow *ui;
};

#endif // CURRENTTASKWINDOW_HPP
