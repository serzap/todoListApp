#include <QObject>
#include <QApplication>
#include "Application.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Application myApp;
    return a.exec();
}
