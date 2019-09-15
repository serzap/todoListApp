#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QString>
#include <QDateTime>
#include <QColor>
#include <QCheckBox>
#include <NewTaskWindow.hpp>
#include "ui_MainWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

public slots:
    void updateTaskList(const std::vector<Task>& list);
    void updateTask(const Task& task);

private slots:
    void on_pushButton_NewTask_clicked();

signals:
    void newTaskButtonClicked();

private:
    QListWidgetItem* getListItem(const Task& task);
    Ui::MainWindow* mUI;
};
#endif // MAINWINDOW_HPP
