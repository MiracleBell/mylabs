//
// Created by L on 18.02.2021.
//

#ifndef UNIVER_PLUSES_DYNAMICARRAY_H
#define UNIVER_PLUSES_DYNAMICARRAY_H

#include <exception>
#include <ostream>

class DynamicArray {
private:
    static int const DEFAULT_ARRAY_SIZE = 10;
    static int const DEFAULT_ARRAY_BUFFER = 10;
    int *array;
    int size;
    int buffer;

public:
    DynamicArray();

    DynamicArray(int const size);

    DynamicArray(int const size, int const default_element);

    DynamicArray(int const size, int const buffer, int const default_element);

    DynamicArray(const DynamicArray &other);

    DynamicArray(const DynamicArray &&other);

    virtual ~DynamicArray();

    int getSize();

    void resize(int const new_size);

    void reserve(int const new_buffer);

    int capacity();

    void pushBack(int const value);

    int popBack();

    int &operator[](const int index);

    DynamicArray &operator=(const DynamicArray &other);

    bool operator==(const DynamicArray &other) const;

    bool operator!=(const DynamicArray &other) const;

    bool operator<(const DynamicArray &other) const;

    bool operator>(const DynamicArray &other) const;

    bool operator<=(const DynamicArray &other) const;

    bool operator>=(const DynamicArray &other) const;

    DynamicArray operator+(const DynamicArray &other) const;

    friend std::ostream &operator<<(std::ostream &os, const DynamicArray &obj);

    friend std::istream &operator>>(std::istream &is, const DynamicArray &obj);
};

#endif //UNIVER_PLUSES_DYNAMICARRAY_H
