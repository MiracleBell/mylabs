//
// Created by L on 24.02.2021.
//
/*
Задача 2. Кольцевой буфер.
1. Реализовать кольцевой буфер (очередь на базе массива) в виде класса. Размер буфера задается в конструкторе. Методы:
-- добавить элемент в конец очереди (при переполнении – исключение),
-- взять элемент в начале очереди (при отсутствии – исключение),
-- получить элемент в начале очереди (без его изъятия),
-- размер очереди,
-- сделать очередь пустой,
-- проверка очереди на пустоту.
2. Реализовать итератор на написанной очереди (в виде отдельного класса). Итератор представляет собой отдельный класс с методами:
void start(); -- начать перебор элементов
void next(); -- перейти к следующему элементу
bool finish(); -- проверка, все ли проитерировано
int getValue(); -- получить очередной элемент очереди
Также должен быть конструктор, который привязывает итератор к очереди.
*/

#ifndef UNIVER_PLUSES_QUEUE_H
#define UNIVER_PLUSES_QUEUE_H

#include <exception>


namespace tt2 {
    template<typename T>
    class Queue {
    private:
        static const int BUFFER_ELEMENT = 1;

        T *array;
        int size;

        int head;
        int tail;


    public:
        Queue(const int size);

        Queue(const Queue<T> &queue);

        ~Queue();

        bool isEmpty();

        void clear();

        int getSize();

        T getFirstElement();

        T popFront();

        void pushBack(const T elem);

        class Iterator {
        private:
            Queue<T> *queue;
            int current;
            int count;

        public:
            Iterator(Queue<T> &queue) {
                this->queue = &queue;
                current = -1;
                count = 0;
            }

            ~Iterator() {
                delete queue;
                queue = nullptr;
            }

            void start() {
                current = queue->head;
            }

            inline void next() {
                current = (current + 1) % queue->size;
            }

            inline bool finish() {
                return count == queue->tail;
            }

            inline int getValue() {
                return queue->arr[current];
            }
        };

        Iterator iterator() {
            return Iterator(*this);
        }
    };


//Constructor
    template<typename T>
    Queue<T>::Queue(const int size) : size(size + BUFFER_ELEMENT) {
        if (size < 1) {
            throw std::exception("Error! Buffers size can't be smaller than 1");
        }
        array = new T[size];
        head = 0;
        tail = 0;

    }

    template<typename T>
    Queue<T>::Queue(const Queue<T> &queue) {
        this->size = queue.size;
        this->head = queue.head;
        this->tail = queue.tail;
        this->array = new T[size];
        for (int i = 0; i < size; ++i) {
            array[i] = queue.array[i];
        }
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


//Show first element in queue (method did not take this element!)
    template<typename T>
    T Queue<T>::getFirstElement() {
        if (isEmpty()) {
            throw std::exception("Error! Queue is empty!");
        }
        return array[head];
    }

}

#endif //UNIVER_PLUSES_QUEUE_H
