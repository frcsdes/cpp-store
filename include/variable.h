#ifndef STORE_VARIABLE_H
#define STORE_VARIABLE_H

#include <functional>
#include <type_traits>
#include <vector>


namespace store {


// The Variable class is essentially a proxy to a value of type T
template<class T>
class Variable {
    // Inheriting this empty struct prevents unwanted aggregate initialization
    struct NotAnAggregate {};

    // std::decay is too aggressive with arrays
    using TBase = typename std::remove_const
                 <typename std::remove_reference<T>::type>::type;
    using Functor = std::function<void(T)>;

public:
    // Prevent replacement of a defined variable
    Variable& operator=(const Variable&) = delete;

    Variable() = default;
    explicit Variable(T value) : _value {value} {};

    // This nested class grants access to the value directly or by subscription
    template<Variable<T>& V>
    class Get : NotAnAggregate {
    public:
        // Prevent copy construction on the loose
        Get(const Get&) = delete;
        Get& operator=(const Get&) = delete;

    protected:
        // Only a child class can default construct
        Get() = default;

        // Get the underlying value
        const T storeGet() const { return V._value; }

        // Call a functor on any value change; optionally, call it immediately
        void storeSubscribe(Functor subscriber, bool call = false) {
            V._subscribers.push_back(subscriber);
            if (call)
                subscriber(V._value);
        }
    };

    // This nested class allows to change the underlying value
    template<Variable<T>& V>
    class Set : NotAnAggregate {
    public:
        // Prevent copy construction on the loose
        Set(const Set&) = delete;
        Set& operator=(const Set&) = delete;

    protected:
        // Only a child class can default construct
        Set() = default;

        // Call to change the underlying value, or use as a functor
        const Functor storeSet {[this](T value) {
            if (V._value != value) {
                V._value  = value;
                V.dispatch();
            }
        }};
    };

    // Two-way interactivity
    template<Variable<T>& V>
    class GetSet : public Get<V>,
                   public Set<V> {};

private:
    // The managed value
    TBase _value;

    // Keep track of the subscribers
    std::vector<Functor> _subscribers;

    // Notify all subscribers of a value change
    void dispatch() {
        for (const auto& subscriber : _subscribers)
            subscriber(_value);
    }
};


} // namespace store

#endif // STORE_VARIABLE_H
