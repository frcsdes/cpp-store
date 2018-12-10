//
// Created by fdesrich on 12/7/18.
//

#include "mainwindow.h"

#include "store/store.h"

#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>


namespace store {


MainWindow::MainWindow() {
    setWindowTitle(tr("Store demo"));

    auto* spin_box_1 = new QSpinBox;
    Store::integer.autoConnect(spin_box_1);

    auto* spin_box_2 = new QSpinBox;
    Store::integer.autoConnect(spin_box_2);

    auto* label = new QLabel;

    auto* central_layout = new QVBoxLayout;
    central_layout->addWidget(spin_box_1);
    central_layout->addWidget(spin_box_2);
    central_layout->addWidget(label);

    auto* central_widget = new QWidget;
    central_widget->setLayout(central_layout);

    setCentralWidget(central_widget);
    show();
}


} // namespace store
