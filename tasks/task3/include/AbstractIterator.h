//
// Created by L on 17.03.2021.
//

#ifndef UNIVER_PLUSES_ABSTRACTITERATOR_H
#define UNIVER_PLUSES_ABSTRACTITERATOR_H


template<typename T>
class AbstractIterator {
public:
    virtual void start() = 0;

    virtual T getElem() = 0;

    virtual void next() = 0;

    virtual bool hasNext() = 0;
};


#endif //UNIVER_PLUSES_ABSTRACTITERATOR_H
