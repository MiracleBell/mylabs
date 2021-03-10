//
// Created by L on 15.02.2021.
//

#ifndef UNIVER_PLUSES_BOX_H
#define UNIVER_PLUSES_BOX_H

#include <ostream>
#include <exception>

struct Box {
    int length;
    int width;
    int height;
    float weight;
    int value;

    Box(int length, int width, int height, float weight, int value) : length(length), width(width), height(height),
                                                                      weight(weight), value(value) {

    }

    bool operator==(const Box &other) const {
        return length == other.length &&
               width == other.width &&
               height == other.height &&
               weight == other.weight &&
               value == other.value;
    }

    bool operator<(const Box &other) const {
        if (length < other.length)
            return true;
        if (other.length < length)
            return false;
        if (width < other.width)
            return true;
        if (other.width < width)
            return false;
        if (height < other.height)
            return true;
        if (other.height < height)
            return false;
        if (weight < other.weight)
            return true;
        if (other.weight < weight)
            return false;
        return value < other.value;
    }

    bool operator>(const Box &other) const {
        return other < *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Box &box) {
        os << "length: " << box.length << std::endl << " width: " << box.width << std::endl
           << " height: " << box.height << std::endl << " weight: " << box.weight << std::endl
           << " value: " << box.value;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Box &box) {
        is >> box.length;
        is >> box.height;
        is >> box.width;
        is >> box.weight;
        is >> box.value;
        return is;
    }
};

#endif //UNIVER_PLUSES_BOX_H
