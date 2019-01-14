#ifndef STORE_STORE_H
#define STORE_STORE_H

#include "variable.h"

#include <QString>


namespace MyStore {

extern store::Variable<int> integer;
extern store::Variable<const QString&> string;

}


#endif // STORE_STORE_H
