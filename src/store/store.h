//
// Created by fdesrich on 12/7/18.
//

#ifndef STORE_STORE_H
#define STORE_STORE_H

#include "storevariable.h"


namespace store {


class Store {
public:
    Store() = delete;

public:
    static StoreVariable<int> integer;
};


} // namespace store

#endif // STORE_STORE_H
