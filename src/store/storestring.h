//
// Created by fdesrich on 12/8/18.
//

#ifndef STORE_STORESTRING_H
#define STORE_STORESTRING_H

#include <functional>
#include <string>

#include <QString>


namespace store {


class StoreString {
public:
    class View {
    public:
        explicit View(const char* value) : _value {value} {};

        operator const char*() const;
        operator const std::string&() const;
        operator QString() const;

    private:
        std::string _value;
    };

    explicit StoreString(const char* value) : _view {value} {};
    void bind(std::function<void(const View&)> function);

private:
    View _view;
};


} // namespace store

#endif // STORE_STORESTRING_H
