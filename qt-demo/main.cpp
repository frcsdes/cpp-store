#include "mainwindow.h"
#include <QApplication>


int main(int argc, char* argv[])
{
    QApplication a {argc, argv};
    store::MainWindow w {};
    return a.exec();
}
