#ifndef STORE_SPINBOX_H
#define STORE_SPINBOX_H

#include "binding.h"
#include "mystore.h"

#include <QSpinBox>


class SpinBox : public QSpinBox,
                store::Get<int>::From<MyStore::integer>,
                store::Set<int>::Into<MyStore::integer> {
public:
    SpinBox() {
        // Subscribe with a lambda function
        subscribe([this](int value) { setValue(value); }, true);
        connect(this, qOverload<int>(&QSpinBox::valueChanged), set);
    };
};


#endif // STORE_SPINBOX_H
