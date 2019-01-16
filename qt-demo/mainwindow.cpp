#include "mainwindow.h"

#include "button.h"
#include "label.h"
#include "lineedit.h"
#include "spinbox.h"

#include <QVBoxLayout>


MainWindow::MainWindow() {
    auto* layout = new QVBoxLayout;
    layout->addWidget(new SpinBox);
    layout->addWidget(new SpinBox);
    layout->addWidget(new LineEdit);
    layout->addWidget(new Label);
    layout->addWidget(new Button);

    auto* widget = new QWidget;
    widget->setLayout(layout);

    setWindowTitle("Store demo");
    setCentralWidget(widget);
    show();
}
