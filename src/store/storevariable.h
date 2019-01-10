//
// Created by fdesrich on 1/9/19.
//

#ifndef STORE_STOREVARIABLE_H
#define STORE_STOREVARIABLE_H

#include <functional>
#include <vector>


namespace store {


template<class T>
class StoreVariable {
public:
    using Functor = std::function<void(T)>;
    using Base = typename std::remove_cv
                <typename std::remove_reference<T>::type>::type;

    explicit StoreVariable (T value) : _value {value} {};
    operator T() const { return _value; }

    const Functor& setter() { return _setter; }

    void subscribe(Functor subscriber, bool call = true) {
        _subscribers.push_back(subscriber);
        if (call)
            subscriber(_value);
    }

private:
    Base _value;

    Functor _setter {[this](T value) {
        if (_value != value) {
            _value  = value;
            dispatch();
        }
    }};

    std::vector<Functor> _subscribers;
    void dispatch() {
        for (const auto& subscriber : _subscribers)
            subscriber(_value);
    }
};


} // namespace store

#endif // STORE_STOREVARIABLE_H
