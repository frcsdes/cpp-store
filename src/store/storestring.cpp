//
// Created by fdesrich on 12/8/18.
//

#include "storestring.h"


namespace store {


StoreString::StoreString(const QString& text)
    : _text {text} {}

StoreString::operator const QString&() const {
    return _text;
}

void StoreString::autoConnect(QLabel* const label) {
    label->setText(_text);
    connect(this, SIGNAL(textChanged(const QString&)),
            label, SLOT(setText(const QString&)));
}

void StoreString::autoDisconnect(QLabel* const label) {
    disconnect(this, SIGNAL(textChanged(const QString&)),
               label, SLOT(setText(const QString&)));
}

void StoreString::autoConnect(QLineEdit* const line_edit) {
    line_edit->setText(_text);
    connect(this, SIGNAL(textChanged(const QString&)),
            line_edit, SLOT(setText(const QString&)));
    connect(line_edit, SIGNAL(textChanged(const QString&)),
            this, SLOT(setText(const QString&)));
}

void StoreString::autoDisconnect(QLineEdit* const line_edit) {
    disconnect(this, SIGNAL(textChanged(const QString&)),
               line_edit, SLOT(setText(const QString&)));
    disconnect(line_edit, SIGNAL(textChanged(const QString&)),
               this, SLOT(setText(const QString&)));
}

void StoreString::setText(const QString& text) {
    if (_text != text) {
        _text = text;
        emit textChanged(_text);
    }
}


} // namespace store
