//
// Created by fdesrich on 12/7/18.
//

#ifndef STORE_STORE_H
#define STORE_STORE_H

#include "storevariable.h"

#include <QString>


namespace store {


class Store {
public:
    static Store& instance();

    Store(const Store&) = delete;
    void operator=(const Store&) = delete;

    StoreVariable<int> _integer {4};
    StoreVariable<QString> _string {"Test"};

private:
    Store() = default;
};


} // namespace store

#endif // STORE_STORE_H
