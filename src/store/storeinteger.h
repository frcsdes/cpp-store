//
// Created by fdesrich on 12/7/18.
//

#ifndef STORE_STOREINTEGER_H
#define STORE_STOREINTEGER_H

#include <functional>
#include <vector>

#include <QObject>
#include <QSpinBox>


namespace store {


class StoreInteger : public QObject {
    Q_OBJECT

public:
    explicit StoreInteger(int value);
    operator int() const;

    void autoConnect(QSpinBox* const spin_box);
    void autoDisconnect(QSpinBox* const spin_box);

private:
    int _value;

signals:
    void valueChanged(int);

public slots:
    void setValue(int value);
    void decrementValue();
    void incrementValue();
};


} // namespace store

#endif // STORE_STOREINTEGER_H
