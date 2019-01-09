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
    connect(spin_box_1, qOverload<int>(&QSpinBox::valueChanged), [](int value) { Store::instance()._integer.set(value); });
    //Store::instance()._integer.subscribe(std::bind(&QSpinBox::setValue, *spin_box_1));
    Store::instance()._integer.subscribe([spin_box_1](int value) { spin_box_1->setValue(value); });

    auto* spin_box_2 = new QSpinBox;
    connect(spin_box_2, qOverload<int>(&QSpinBox::valueChanged), [](int value) { Store::instance()._integer.set(value); });
    Store::instance()._integer.subscribe([spin_box_2](int value) { spin_box_2->setValue(value); });

    // StoreString
    auto* label = new QLabel;
    label->setText(Store::instance()._string);

    auto* line_edit = new QLineEdit;
    line_edit->setText(Store::instance()._string);

    auto* central_layout = new QVBoxLayout;
    central_layout->addWidget(spin_box_1);
    central_layout->addWidget(spin_box_2);
    central_layout->addWidget(line_edit);
    central_layout->addWidget(label);

    auto* central_widget = new QWidget;
    central_widget->setLayout(central_layout);

    setCentralWidget(central_widget);
    show();
}


} // namespace store
