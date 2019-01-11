#ifndef STORE_MYSTORE_H
#define STORE_MYSTORE_H

#include "variable.h"

#include <QString>


namespace store {


struct Store {
    Variable<int> integer {4};
    Variable<const QString&> string {"Test"};
};


} // namespace store

#endif // STORE_MYSTORE_H
