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

    auto* spin_box = new QSpinBox;
    Store::integer.bind([spin_box](auto view) { spin_box->setValue(view); });

    auto* push_button = new QPushButton("Increment");
    connect(push_button, SIGNAL(pressed()),
            &Store::integer, SLOT(incrementValue()));

    auto* label = new QLabel;
    Store::string.bind([label](auto view) { label->setText(view); });

    auto* central_layout = new QVBoxLayout;
    central_layout->addWidget(spin_box);
    central_layout->addWidget(push_button);
    central_layout->addWidget(label);

    auto* central_widget = new QWidget;
    central_widget->setLayout(central_layout);

    setCentralWidget(central_widget);
    show();
}


} // namespace store
