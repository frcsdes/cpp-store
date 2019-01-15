#ifndef STORE_BINDING_H
#define STORE_BINDING_H

#include <functional>


namespace store {


struct NotAnAggregate {};

template<class T>
class Variable;

template<class T>
struct Get final : NotAnAggregate {
    Get() = delete;
    Get(const Get&) = delete;
    Get& operator=(const Get&) = delete;

    template<Variable<T>& V>
    class From : NotAnAggregate {
        using Functor = std::function<void(T)>;

    public:
        From(const From&) = delete;
        From& operator=(const From&) = delete;

        const T getValue() const { return V._value; }

        void subscribe(Functor subscriber, bool call = false) {
            V._subscribers.push_back(subscriber);
            if (call)
                subscriber(V._value);
        }

    protected:
        From() = default;
    };
};

template<class T>
struct Set final : NotAnAggregate {
    Set() = delete;
    Set(const Set&) = delete;
    Set& operator=(const Set&) = delete;

    template<Variable<T>& V>
    class Into : NotAnAggregate {
        using Functor = std::function<void(T)>;

    public:
        Into(const Into&) = delete;
        Into& operator=(const Into&) = delete;

        const Functor set {[this](T value) {
            if (V._value != value) {
                V._value  = value;
                V.dispatch();
            }
        }};

    protected:
        Into() = default;
    };
};


} // namespace store

#endif // STORE_BINDING_H
