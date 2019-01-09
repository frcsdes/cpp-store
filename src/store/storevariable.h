//
// Created by fdesrich on 1/9/19.
//

#ifndef STORE_STOREVARIABLE_H
#define STORE_STOREVARIABLE_H

#include <functional>
#include <vector>


namespace store {


// @todo Manage copyable / movable differently?
template<class T>
class StoreVariable {
public:
    explicit StoreVariable (T value) : _value {value} {};
    operator T() const { return _value; }

    void set(T value) {
        if (_value != value) {
            _value = value;
            dispatch();
        }
    }

    using Subscriber = std::function<void(T)>;
    void subscribe(Subscriber subscriber, bool call = true) {
        _subscribers.push_back(subscriber);
        if (call)
            subscriber(_value);
    }

private:
    T _value;

    std::vector<Subscriber> _subscribers;
    void dispatch() {
        for (const auto& subscriber : _subscribers)
            subscriber(_value);
    }
};


} // namespace store

#endif // STORE_STOREVARIABLE_H
