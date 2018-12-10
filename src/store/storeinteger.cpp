//
// Created by fdesrich on 12/7/18.
//

#include "storeinteger.h"

#include <QDebug>


namespace store {


StoreInteger::StoreInteger(int value)
    : _value {value} {}

StoreInteger::operator int() const {
    return _value;
}

void StoreInteger::autoConnect(QSpinBox* const spin_box) {
    spin_box->setValue(_value);
    connect(this, SIGNAL(valueChanged(int)),
            spin_box, SLOT(setValue(int)));
    connect(spin_box, SIGNAL(valueChanged(int)),
            this, SLOT(setValue(int)));
}

void StoreInteger::autoDisconnect(QSpinBox* const spin_box) {
    disconnect(this, SIGNAL(valueChanged(int)),
               spin_box, SLOT(setValue(int)));
    disconnect(spin_box, SIGNAL(valueChanged(int)),
               this, SLOT(setValue(int)));
}

void StoreInteger::setValue(int value) {
    if (value != _value) {
        _value = value;
        emit valueChanged(_value);
    }
}

void StoreInteger::decrementValue() {
    setValue(_value - 1);
}

void StoreInteger::incrementValue() {
    setValue(_value + 1);
}


} // namespace store
