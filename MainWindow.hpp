#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <NewTaskWindow.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void addRelatedWindow(NewTaskWindow* related);

public slots:
    void addNewTask(TaskInfo taskInfo);
    void deleteSelected();
private slots:
    void on_pushButton_NewTask_clicked();
    void on_pushButton_DeleteTask_clicked();
signals:
    void newTaskButtonClicked();

private:
    Ui::MainWindow* mUI;
    NewTaskWindow* mNewTaskWindow;
};
#endif // MAINWINDOW_HPP
