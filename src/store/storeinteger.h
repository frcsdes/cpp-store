//
// Created by fdesrich on 12/7/18.
//

#ifndef STORE_STOREINTEGER_H
#define STORE_STOREINTEGER_H

#include <functional>
#include <vector>

#include <QObject>


namespace store {


class StoreInteger : public QObject {
    Q_OBJECT

public:
    class View {
    public:
        View(int value) : _value {value} {};
        operator int() const;

        friend class StoreInteger;

    private:
        int _value;
    };

    using Binding = std::function<void(const View&)>;
    using Setter = std::function<int(const View&)>;

    explicit StoreInteger(int value) : _view {value} {};
    void bind(Binding function);

    void dispatch() const;

public slots:
    void setValue(int value);
    void incrementValue();

private:
    View _view;
    std::vector<Binding> _bindings;
};


} // namespace store

#endif // STORE_STOREINTEGER_H
