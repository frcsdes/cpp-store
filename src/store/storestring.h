//
// Created by fdesrich on 12/8/18.
//

#ifndef STORE_STORESTRING_H
#define STORE_STORESTRING_H

#include <QObject>
#include <QLabel>
#include <QLineEdit>
#include <QString>


namespace store {


class StoreString : public QObject {
    Q_OBJECT

public:
    explicit StoreString(const QString& text);
    operator const QString&() const;

    void autoConnect(QLabel* const label);
    void autoDisconnect(QLabel* const label);

    void autoConnect(QLineEdit* const line_edit);
    void autoDisconnect(QLineEdit* const line_edit);

signals:
    void textChanged(const QString& text);

public slots:
    void setText(const QString& text);

private:
    QString _text;
};


} // namespace store

#endif // STORE_STORESTRING_H
