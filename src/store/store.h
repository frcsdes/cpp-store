//
// Created by fdesrich on 12/7/18.
//

#ifndef STORE_STORE_H
#define STORE_STORE_H


#include "storeinteger.h"
#include "storestring.h"


namespace store {


class Store {
public:
    Store() = delete;

public:
    static StoreInteger integer;
    static StoreString string;
};


} // namespace store

#endif // STORE_STORE_H
