#include "mainwindow.h"

#include "store.h"

#include <functional>

#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QVBoxLayout>


MainWindow::MainWindow() {
    using namespace std::placeholders;

    setWindowTitle(tr("Store demo"));


    // Store an integer and use it with two spin boxes
    auto* spin_box_1 = new QSpinBox;
    // Subscribe to changes via bound member function
    Store::integer.subscribe(
        std::bind(&QSpinBox::setValue, spin_box_1, _1), true);
    // Set a new value when the spin box changes
    connect(spin_box_1, qOverload<int>(&QSpinBox::valueChanged),
            Store::integer.set);

    auto* spin_box_2 = new QSpinBox;
    // Easier and more flexible lambda subscription
    Store::integer.subscribe([spin_box_2](int value) {
        spin_box_2->setValue(value);
    }, true);
    connect(spin_box_2, qOverload<int>(&QSpinBox::valueChanged),
            Store::integer.set);


    // Store a string and use it with a line edit and a label
    auto* line_edit = new QLineEdit;
    Store::string.subscribe([line_edit](const QString& value) {
        line_edit->setText(value);
    }, true);
    connect(line_edit, &QLineEdit::textChanged, Store::string.set);

    auto* label = new QLabel;
    Store::string.subscribe(
        std::bind(&QLabel::setText, label, _1), true);


    // Setup and show the window (no connect!)
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
