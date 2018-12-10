//
// Created by fdesrich on 12/7/18.
//

#include "storeinteger.h"


namespace store {


StoreInteger::View::operator int() const {
    return _value;
}

void StoreInteger::bind(Binding function) {
    function(_view);
    _bindings.push_back(std::move(function));
}

void StoreInteger::setValue(int value) {
    _view._value = value;
    dispatch();
}

void StoreInteger::incrementValue() {
    setValue(_view + 1);
}

void StoreInteger::dispatch() const {
    for (const auto& function : _bindings)
        function(_view);
}


} // namespace store
