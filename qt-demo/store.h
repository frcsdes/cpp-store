#ifndef STORE_STORE_H
#define STORE_STORE_H

#include "variable.h"

#include <QString>


namespace Store {

extern Variable<int> integer;
extern Variable<const QString&> string;

}


#endif // STORE_STORE_H
