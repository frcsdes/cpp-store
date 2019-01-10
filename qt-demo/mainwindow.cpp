#include "mainwindow.h"

#include "mystore.h"

#include <functional>

#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QVBoxLayout>


namespace store {


MainWindow::MainWindow() {
    setWindowTitle(tr("Store demo"));

    using namespace std::placeholders;

    // StoreInteger
    auto* spin_box_1 = new QSpinBox;
    // Subscribing via bound member function
    MyStore::instance().integer.subscribe(
        std::bind(&QSpinBox::setValue, spin_box_1, _1));
    connect(spin_box_1, qOverload<int>(&QSpinBox::valueChanged),
            MyStore::instance().integer.setter());

    auto* spin_box_2 = new QSpinBox;
    // Easier and flexible lambda subscription
    MyStore::instance().integer.subscribe(
        [spin_box_2](int value) { spin_box_2->setValue(value); });
    connect(spin_box_2, qOverload<int>(&QSpinBox::valueChanged),
            MyStore::instance().integer.setter());

    // StoreString
    auto* label = new QLabel;
    MyStore::instance().string.subscribe(
        std::bind(&QLabel::setText, label, _1));

    auto* line_edit = new QLineEdit;
    MyStore::instance().string.subscribe(
        [line_edit](const QString& value) { line_edit->setText(value); });
    connect(line_edit, &QLineEdit::textChanged,
            MyStore::instance().string.setter());

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
