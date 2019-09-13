#ifndef CURRENTTASKWINDOW_HPP
#define CURRENTTASKWINDOW_HPP

#include <QObject>
#include <QWidget>
#include "CTask.hpp"

namespace Ui {
class CurrentTaskWindow;
}

class CurrentTaskWindow : public QWidget
{
    Q_OBJECT
public:
    explicit CurrentTaskWindow(QWidget *parent = nullptr);
    ~CurrentTaskWindow();

signals:
    void taskToBeDeleted(CTask task);

private slots:
    void on_pushButton_toBeDeleted_clicked();

private:
    Ui::CurrentTaskWindow* mUI;
    CTask mTask;
};

#endif // CURRENTTASKWINDOW_HPP
