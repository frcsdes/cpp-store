//
// Created by fdesrich on 1/9/19.
//

#ifndef STORE_VARIABLE_H
#define STORE_VARIABLE_H

#include <functional>
#include <type_traits>
#include <vector>


namespace store {


template<class T>
class Variable {
    using TConst = typename std::add_const<T>::type;
    using TBase = typename std::remove_const
                 <typename std::remove_reference<T>::type>::type;
    using Functor = std::function<void(T)>;

public:
    explicit Variable (T value) : _value {value} {};

    operator TConst() const { return _value; }
    const Functor& setter() const { return _setter; }

    void subscribe(Functor subscriber, bool call = true) {
        _subscribers.push_back(subscriber);
        if (call)
            subscriber(_value);
    }

private:
    TBase _value;
    std::vector<Functor> _subscribers;

    void dispatch() {
        for (const auto& subscriber : _subscribers)
            subscriber(_value);
    }

    Functor _setter {[this](T value) {
        if (_value != value) {
            _value  = value;
            dispatch();
        }
    }};
};


} // namespace store

#endif // STORE_VARIABLE_H
