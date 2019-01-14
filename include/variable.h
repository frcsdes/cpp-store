#ifndef STORE_VARIABLE_H
#define STORE_VARIABLE_H

#include "binding.h"

#include <functional>
#include <type_traits>
#include <vector>


namespace store {


template<class T>
class Variable {
    using TBase = typename std::remove_const
                 <typename std::remove_reference<T>::type>::type;
    using Functor = std::function<void(T)>;

public:
    Variable() = delete;
    Variable(const Variable&) = delete;
    Variable& operator=(const Variable&) = delete;

    explicit Variable(T value) : _value{value} {};

    friend class Get<T>;
    friend class Set<T>;

private:
    TBase _value;
    std::vector<Functor> _subscribers;

    void dispatch() {
        for (const auto& subscriber : _subscribers)
            subscriber(_value);
    }
};


} // namespace store

#endif // STORE_VARIABLE_H
