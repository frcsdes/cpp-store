//
// Created by fdesrich on 1/9/19.
//

#ifndef STORE_STOREVARIABLE_H
#define STORE_STOREVARIABLE_H


namespace store {


template<class T>
class StoreVariable {
public:
    explicit StoreVariable (T value) : _value {value} {};
    operator T() { return _value; }

private:
    T _value;
};


} // namespace store

#endif // STORE_STOREVARIABLE_H
