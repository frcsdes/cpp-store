#include "mainwindow.h"

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

    auto* widget = new QWidget;
    widget->setLayout(layout);

    setWindowTitle(tr("Store demo"));
    setCentralWidget(widget);
    show();
}
