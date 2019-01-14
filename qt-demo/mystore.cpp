#include "mystore.h"


namespace MyStore {

store::Variable<int> integer {4};
store::Variable<const QString&> string {"Test"};

}
