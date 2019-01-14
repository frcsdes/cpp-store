#ifndef STORE_LABEL_H
#define STORE_LABEL_H

#include "binding.h"
#include "mystore.h"

#include <QLabel>


class Label : public QLabel,
              store::Get<const QString&>::From<MyStore::string> {
public:
    Label() {
        // Subscribe via a member function binding
        subscribe(std::bind(&QLabel::setText, this, std::placeholders::_1), true);
    };
};


#endif // STORE_LABEL_H
