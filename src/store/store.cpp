//
// Created by fdesrich on 12/7/18.
//

#include "store/store.h"


namespace store {


Store& Store::instance() {
    static Store instance;
    return instance;
};


} // namespace store
