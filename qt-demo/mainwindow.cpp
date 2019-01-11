#include "mainwindow.h"

#include <functional>

#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QVBoxLayout>


namespace store {


MainWindow::MainWindow() {
    using namespace std::placeholders;

    setWindowTitle(tr("Store demo"));


    // Store an integer and using it with two spin boxes
    auto* spin_box_1 = new QSpinBox;
    // Subscribe to changes via bound member function
    _store.integer.subscribe(
        std::bind(&QSpinBox::setValue, spin_box_1, _1), true);
    // Set a new value when the spin box changes
    connect(spin_box_1, qOverload<int>(&QSpinBox::valueChanged),
            _store.integer.setter());

    auto* spin_box_2 = new QSpinBox;
    // Easier and more flexible lambda subscription
    _store.integer.subscribe([spin_box_2](int value) {
        spin_box_2->setValue(value);
    }, true);
    connect(spin_box_2, qOverload<int>(&QSpinBox::valueChanged),
            _store.integer.setter());


    // Store a string and using it with a line edit and a label
    auto* line_edit = new QLineEdit;
    _store.string.subscribe([line_edit](const QString& value) {
        line_edit->setText(value);
    }, true);
    connect(line_edit, &QLineEdit::textChanged,
            _store.string.setter());

    auto* label = new QLabel;
    _store.string.subscribe(
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


} // namespace store
