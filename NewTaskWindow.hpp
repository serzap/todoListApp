#ifndef NEWTASKWINDOW_HPP
#define NEWTASKWINDOW_HPP

#include <QWidget>
#include "CTask.hpp"

namespace Ui {
class NewTaskWindow;
}

class NewTaskWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NewTaskWindow(QWidget *parent = nullptr);
    ~NewTaskWindow();

signals:
    void newTaskCreated(CTask task);

private slots:
    void on_pushButton_taskCreated_clicked();

private:
    Ui::NewTaskWindow* mUI;
    CTask mTaskInfo;
};

#endif // NEWTASKWINDOW_HPP
