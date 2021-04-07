//
// Created by L on 17.03.2021.
//

#ifndef UNIVER_PLUSES_ABSTRACTLIST_H
#define UNIVER_PLUSES_ABSTRACTLIST_H


template<typename T>
class AbstractList {
public:
    virtual void insert(T data) = 0;

    virtual void remove() = 0;

    virtual void startWith() = 0;

    virtual void clear() = 0;

    virtual bool isEmpty() = 0;

    virtual int getSize() = 0;

    virtual void begin() = 0;
};


#endif //UNIVER_PLUSES_ABSTRACTLIST_H
