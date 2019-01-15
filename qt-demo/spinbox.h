#ifndef STORE_SPINBOX_H
#define STORE_SPINBOX_H

#include "mystore.h"

#include <QSpinBox>


class SpinBox : public QSpinBox,
                store::Variable<int>::GetSet<MyStore::integer> {
public:
    SpinBox() {
        // Subscribe with a lambda function
        subscribe([this](int value) { setValue(value); }, true);
        connect(this, qOverload<int>(&QSpinBox::valueChanged), set);
    };
};


#endif // STORE_SPINBOX_H
