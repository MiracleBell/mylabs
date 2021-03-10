//
// Created by L on 24.02.2021.
//

#ifndef UNIVER_PLUSES_ITERATOR_H
#define UNIVER_PLUSES_ITERATOR_H


template<typename T>
class Iterator {
private:
    friend class Queue;

    T *elem;

    Iterator(const T *elem);

public:
    Iterator();

    Iterator(const Iterator &iter);

    void start();

    void next();

    bool finish();

    T getValue();

    bool operator==(const Iterator &iter) const;
};


template<typename T>
Iterator<T>::Iterator() {
    elem = nullptr;
}

template<typename T>
Iterator<T>::Iterator(const T *elem) :elem(elem) {

}

template<typename T>
Iterator<T>::Iterator(const Iterator &iter) {
    elem = iter.elem;
}

template<typename T>
void Iterator<T>::start() {

}

template<typename T>
void Iterator<T>::next() {

}

template<typename T>
bool Iterator<T>::finish() {

}

template<typename T>
T Iterator<T>::getValue() {
    return elem;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T> &iter) const {
    return elem == iter.elem;
}

#endif //UNIVER_PLUSES_ITERATOR_H
