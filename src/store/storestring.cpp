//
// Created by fdesrich on 12/8/18.
//

#include "storestring.h"


namespace store {


StoreString::View::operator const char*() const {
    return _value.c_str();
}

StoreString::View::operator const std::string&() const {
    return _value;
}

StoreString::View::operator QString() const {
    return {_value.c_str()};
}

void StoreString::bind(std::function<void(const View&)> function) {
    function(_view);
}


} // namespace store
