#ifndef STORE_LABEL_H
#define STORE_LABEL_H

#include "mystore.h"

#include <QLabel>


class Label : public QLabel,
              store::Variable<const QString&>::Get<MyStore::string> {
public:
    Label() {
        // Subscribe via a member function binding
        auto&& bound = std::bind(&QLabel::setText, this, std::placeholders::_1);
        storeSubscribe(bound, true);
    }
};


#endif // STORE_LABEL_H
