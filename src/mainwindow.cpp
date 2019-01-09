//
// Created by fdesrich on 12/7/18.
//

#include "mainwindow.h"

#include "store/store.h"

#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QVBoxLayout>


namespace store {


MainWindow::MainWindow() {
    setWindowTitle(tr("Store demo"));

    // StoreInteger
    auto* spin_box_1 = new QSpinBox;
    spin_box_1->setValue(Store::instance()._integer);

    auto* spin_box_2 = new QSpinBox;
    spin_box_2->setValue(Store::instance()._integer);

    // StoreString
    auto* label_1 = new QLabel;

    auto* label_2 = new QLabel;

    auto* line_edit = new QLineEdit;

    auto* central_layout = new QVBoxLayout;
    central_layout->addWidget(spin_box_1);
    central_layout->addWidget(spin_box_2);
    central_layout->addWidget(label_1);
    central_layout->addWidget(line_edit);
    central_layout->addWidget(label_2);

    auto* central_widget = new QWidget;
    central_widget->setLayout(central_layout);

    setCentralWidget(central_widget);
    show();
}


} // namespace store
