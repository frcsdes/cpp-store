#ifndef STORE_BUTTON_H
#define STORE_BUTTON_H

#include "mystore.h"

#include <QPushButton>


class Button : public QPushButton,
               store::Variable<int>::GetSet<MyStore::integer>,
               store::Variable<const QString&>::GetSet<MyStore::string> {
    using MyInteger = store::Variable<int>::GetSet<MyStore::integer>;
    using MyString = store::Variable<const QString&>::GetSet<MyStore::string>;

public:
    Button() {
        setText("Increment");
        connect(this, &QPushButton::clicked, [this]() {
            MyInteger::storeSet(MyInteger::storeGet() + 1);
            MyString::storeSet(MyString::storeGet() + '!');
        });
    }
};


#endif // STORE_BUTTON_H
