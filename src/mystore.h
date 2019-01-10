//
// Created by fdesrich on 1/10/19.
//

#ifndef STORE_MYSTORE_H
#define STORE_MYSTORE_H

#include "store/store.h"


namespace store {


struct MyStore : Store<MyStore> {
    StoreVariable<int> integer {4};
    StoreVariable<const QString&> string {"Test"};
};


} // namespace store

#endif // STORE_MYSTORE_H
