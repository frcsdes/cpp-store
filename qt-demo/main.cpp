#include "mainwindow.h"

#include <QApplication>


int main(int argc, char* argv[]) {
    QApplication application {argc, argv};
    store::MainWindow window {};
    return application.exec();
}
