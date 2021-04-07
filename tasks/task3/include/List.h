//
// Created by L on 17.03.2021.
//

#ifndef UNIVER_PLUSES_LIST_H
#define UNIVER_PLUSES_LIST_H

#include <exception>
#include "AbstractList.h"

template<typename T>
class List : AbstractList<T> {
private:
    struct Node {
        T data;
        Node *next;

        Node(T data) : data(data), next(nullptr) {}
    };

//    Node *current;
    Node *start;
    Node *end;
    int size;

public:
    List(const Node *current) {
        start = current;
        end = current;
    }

    virtual ~List() {
        clear();
    }

    void insert(T data);

    void remove() override;

    void startWith() override;

    void clear() override;

    bool isEmpty() override;

    int getSize() override;

    void begin() override;
};


template<typename T>
void List<T>::insert(T data) {
    if (data == nullptr) {
        throw std::exception("Data direction to null");
    }
    if (current == nullptr) {
        current->next = new Node(data);
    } else {
        Node supportNode(data);
        supportNode.next = current->next;
        current->next = supportNode;
    }
    ++size;
}

template<typename T>
void List<T>::remove() {
    if (size == 0) {
        throw std::exception("Error! List is empty, you can't remove element from empty list.");
    }

    if (current->next == nullptr) {
        current = nullptr;
    } else {
        current = current->next;
    }
    --size;
}


#endif //UNIVER_PLUSES_LIST_H
