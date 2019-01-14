#ifndef STORE_VARIABLE_H
#define STORE_VARIABLE_H

#include <functional>
#include <type_traits>
#include <vector>


template<class T>
class Variable {
    using TBase = typename std::remove_const
                 <typename std::remove_reference<T>::type>::type;
    using Functor = std::function<void(T)>;

public:
    Variable() = delete;
    Variable(const Variable&) = delete;
    Variable& operator=(const Variable&) = delete;

    explicit Variable (T value) : _value {value} {};

    const T get() const { return _value; }

    const Functor set {[this](T value) {
        if (_value != value) {
            _value  = value;
            dispatch();
        }
    }};

    void subscribe(Functor subscriber, bool call = false) {
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
};


#endif // STORE_VARIABLE_H
