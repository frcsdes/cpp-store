//
// Created by fdesrich on 12/7/18.
//

#include "mainwindow.h"

#include "store/store.h"

#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>


namespace store {


MainWindow::MainWindow() {
    setWindowTitle(tr("Store demo"));

    auto* spin_box = new QSpinBox;
    auto* push_button = new QPushButton("Increment");

    auto* central_layout = new QVBoxLayout;
    central_layout->addWidget(spin_box);
    central_layout->addWidget(push_button);

    auto* central_widget = new QWidget;
    central_widget->setLayout(central_layout);

    setCentralWidget(central_widget);
    show();
}


} // namespace store
