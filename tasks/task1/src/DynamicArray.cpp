//
// Created by L on 18.02.2021.
//

#include "../include/DynamicArray.h"


DynamicArray::DynamicArray(int const size, int const buffer, int const default_element) : size(size), buffer(buffer) {
    if (size < 1) {
        throw std::exception("Error! Field 'size' can't be smaller than 1");
    }
    if (buffer < 0) {
        throw std::exception("Error! Buffers size can't be smaller than 0");
    }

    array = new int[size + buffer];
    for (int i = 0; i < size; ++i) {
        array[i] = default_element;
    }
    for (int i = size; i < size + buffer; ++i) {
        array[i] = 0;
    }
}

DynamicArray::DynamicArray(int const size, int const default_element) : DynamicArray(size, DEFAULT_ARRAY_BUFFER,
                                                                                     default_element) {}

DynamicArray::DynamicArray(int const size) : DynamicArray(size, 0) {}

DynamicArray::DynamicArray() : DynamicArray(DEFAULT_ARRAY_SIZE) {}

DynamicArray::DynamicArray(const DynamicArray &other) : size(other.size) {
    array = new int[size];
    for (int i = 0; i < size; ++i) {
        array[i] = other.array[i];
    }
}

DynamicArray::DynamicArray(const DynamicArray &&other) {
    size = other.size;
    array = other.array;
}

DynamicArray::~DynamicArray() {
    delete array;
}

int DynamicArray::getSize() {
    return size;
}

int &DynamicArray::operator[](const int index) {
    if (index < 0 || index >= size) {
        throw std::exception("Index out of borders");
    }
    return array[index];
}

void DynamicArray::resize(int const new_size) {
    if (new_size < 1) {
        throw std::exception("Current size smaller than 1");
    }
    if (size + buffer < new_size) {
        int *support_array = new int[new_size + buffer];
        for (int i = 0; i < size; ++i) {
            support_array[i] = array[i];
        }
        for (int i = size; i < new_size; ++i) {
            support_array[i] = 0;
        }
        delete array;
        array = support_array;
        size = new_size;
        return;
    }

    if (size < new_size) {
        for (int i = size; i < new_size; ++i) {
            array[i] = 0;
        }
    }
    buffer -= new_size - size;
    size = new_size;

    /*if (new_size > size) {
        for (int i = 0; i < size; ++i) {
            support_array[i] = array[i];
        }
        for (int i = size; i < new_size; ++i) {
            support_array[i] = 0;
        }
    } else {
        for (int i = 0; i < new_size; ++i) {
            support_array[i] = array[i];
        }
    }*/
}

DynamicArray &DynamicArray::operator=(const DynamicArray &other) {
    size = other.size;
    array = other.array;
    return *this;
}

bool DynamicArray::operator==(const DynamicArray &other) const {
    if (size != other.size) {
        throw std::exception("Arrays has different size");
    }
    for (int i = 0; i < size; ++i) {
        if (array[i] != other.array[i]) {
            return false;
        }
    }
    return true;
}

bool DynamicArray::operator!=(const DynamicArray &other) const {
    if (size != other.size) {
        throw std::exception("Arrays has different size");
    }
    return !(other == *this);
}

bool DynamicArray::operator<(const DynamicArray &other) const {
    if (size != other.size) {
        throw std::exception("Arrays has different size");
    }
    return array < other.array;
}

bool DynamicArray::operator>(const DynamicArray &other) const {
    return other < *this;
}

bool DynamicArray::operator<=(const DynamicArray &other) const {
    return !(other < *this);
}

bool DynamicArray::operator>=(const DynamicArray &other) const {
    return !(*this < other);
}

DynamicArray DynamicArray::operator+(const DynamicArray &other) const {
    DynamicArray support_array(this->size + other.size);
    for (int i = 0; i < this->size; ++i) {
        support_array[i] = this->array[i];
    }
    for (int i = this->size; i < support_array.size; ++i) {
        support_array[i] = this->array[i];
    }
    return support_array;
}

std::ostream &operator<<(std::ostream &os, const DynamicArray &obj) {
    os << "size: " << obj.size << std::endl << " array: " << std::endl;
    for (int i = 0; i < obj.size; ++i) {
        os << obj.array[i] << "\t";
    }
    return os;
}

std::istream &operator>>(std::istream &is, const DynamicArray &obj) {
    is >> obj.size;
    if (obj.size < 1) {
        throw std::exception("Incorrect index");
    }

    for (int i = 0; i < obj.size; ++i) {
        is >> obj.array[i];
    }
    return is;
}

void DynamicArray::reserve(const int new_buffer) {
    if (new_buffer < 0) {
        throw std::exception("Incorrect size value");
    }
    this->buffer = new_buffer;
    int *support_array = new int[size + new_buffer];
    for (int i = 0; i < size; ++i) {
        support_array[i] = array[i];
    }
    delete array;
    array = support_array;
}

int DynamicArray::capacity() {
    return buffer;
}

void DynamicArray::pushBack(const int value) {
    if (buffer == 0) {
        throw std::exception("arrays size overflow");
    }

    if (buffer <= DEFAULT_ARRAY_BUFFER) {
        int *support_array = new int[size + 2 * buffer];

        for (int i = 0; i < size; ++i) {
            support_array[i] = array[i];
        }
        delete array;
        array = support_array;
    }

    array[size] = value;
    ++size;
    --buffer;
}

int DynamicArray::popBack() {
    if (size == 0) {
        throw std::exception("array is empty");
    }
    int value = array[--size];
    ++buffer;
    array[size] = 0;
    return value;
}
