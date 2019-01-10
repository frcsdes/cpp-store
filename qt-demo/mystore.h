#ifndef STORE_MYSTORE_H
#define STORE_MYSTORE_H

#include "store.h"


namespace store {


struct MyStore : Store<MyStore> {
    Variable<int> integer {4};
    Variable<const QString&> string {"Test"};
};


} // namespace store

#endif // STORE_MYSTORE_H
