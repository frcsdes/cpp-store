#ifndef STORE_VARIABLE_H
#define STORE_VARIABLE_H

#include <functional>
#include <type_traits>
#include <vector>


namespace store {


struct NotAnAggregate {};

template<class T>
class Variable {
    using TBase = typename std::remove_const
                 <typename std::remove_reference<T>::type>::type;
    using Functor = std::function<void(T)>;

public:
    Variable() = delete;
    Variable(const Variable&) = delete;
    Variable& operator=(const Variable&) = delete;

    explicit Variable(T value) : _value {value} {};

    template<Variable<T>& V>
    class Get : NotAnAggregate {
    public:
        Get(const Get&) = delete;
        Get& operator=(const Get&) = delete;

    protected:
        Get() = default;

        const T getValue() const { return V._value; }

        void subscribe(Functor subscriber, bool call = false) {
            V._subscribers.push_back(subscriber);
            if (call)
                subscriber(V._value);
        }
    };

    template<Variable<T>& V>
    class Set : NotAnAggregate {
    public:
        Set(const Set&) = delete;
        Set& operator=(const Set&) = delete;

    protected:
        Set() = default;

        const Functor set {[this](T value) {
            if (V._value != value) {
                V._value  = value;
                V.dispatch();
            }
        }};
    };

    template<Variable<T>& V>
    struct GetSet : Get<V>, Set<V> {};

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
