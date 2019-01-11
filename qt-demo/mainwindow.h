#ifndef STORE_MAINWINDOW_H
#define STORE_MAINWINDOW_H

#include "store.h"

#include <QMainWindow>


namespace store {


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();

private:
    Store _store;
};


} // namespace store

#endif // STORE_MAINWINDOW_H
