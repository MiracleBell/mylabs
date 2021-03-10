//
// Created by L on 24.02.2021.
//

#ifndef UNIVER_PLUSES_QUEUE_H
#define UNIVER_PLUSES_QUEUE_H

#include <exception>


template<typename T>
class Queue {
    friend class Iterator;

private:
    static const int BUFFER_ELEMENT = 1;

    T *array;
    int size;

    int head;
    int tail;

//    Iterator begin;
//    Iterator end;

public:
    Queue(const int buffer);

    ~Queue();

    bool isEmpty();

    void clear();

    int getSize();

    T getFirstElement();

    T popFront();

    void pushBack(const T elem);
};


//Constructor
template<typename T>
Queue<T>::Queue(const int buffer) : size(buffer + BUFFER_ELEMENT) {
    if (buffer < 1) {
        throw std::exception("Error! Buffers size can't be smaller than 1");
    }
    array = new T[buffer];
    head = 0;
    tail = 0;

//    begin = Iterator(head);
//    end = Iterator(tail);
}

template<typename T>
Queue<T>::~Queue() {
    clear();
    delete array;
    array = nullptr;
}


//Check queue for emptiness
template<typename T>
bool Queue<T>::isEmpty() {
    return head == tail;
}


//Clear all queue
template<typename T>
void Queue<T>::clear() {
    while (!isEmpty()) {
        popFront();
    }
}

//Get queues size
template<typename T>
int Queue<T>::getSize() {
    if (head <= tail) {
        return tail - head;
    } else return size - (head - tail) - 1;
    return size;
}


//Add element in the end
template<typename T>
void Queue<T>::pushBack(const T elem) {
    if ((tail + BUFFER_ELEMENT) % size == head) {
        throw std::exception("Queue is full! You can't add elements");
    }

    array[tail] = elem;
    tail = (++tail) % size;
}


//Take first element from queue
template<typename T>
T Queue<T>::popFront() {
    if (isEmpty()) {
        throw std::exception("Queue is empty! You can't take element");
    }
    T value = array[head];
    head = (++head) % size;
    return value;
}


//Show first element in queue
template<typename T>
T Queue<T>::getFirstElement() {
    return array[head];
}


#endif //UNIVER_PLUSES_QUEUE_H
