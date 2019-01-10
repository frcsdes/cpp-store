//
// Created by fdesrich on 12/7/18.
//

#ifndef STORE_STORE_H
#define STORE_STORE_H

#include "storevariable.h"

#include <QString>


namespace store {


template<class CustomStore>
class Store {
public:
    static CustomStore& instance() {
        static CustomStore instance;
        return instance;
    }

    Store(const Store&) = delete;
    Store& operator=(const Store&) = delete;

protected:
    Store() = default;
};


} // namespace store

#endif // STORE_STORE_H
