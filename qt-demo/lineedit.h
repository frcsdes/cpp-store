#ifndef STORE_LINEEDIT_H
#define STORE_LINEEDIT_H

#include "mystore.h"

#include <QLineEdit>


class LineEdit : public QLineEdit,
                 store::Variable<const QString&>::GetSet<MyStore::string> {
public:
    LineEdit() {
        // Subscribe with a lambda function
        subscribe([this](const QString& value) { setText(value); }, true);
        connect(this, &QLineEdit::textChanged, set);
    }
};

#endif // STORE_LINEEDIT_H
