//
// Created by L on 15.02.2021.
//

#ifndef UNIVER_PLUSES_CONTAINER_H
#define UNIVER_PLUSES_CONTAINER_H

#include <vector>
#include <iostream>
#include <exception>
#include "Box.h"

namespace tt0 {
    class Container {
    private:
        std::vector<Box> boxes;
        int length;
        int width;
        int height;
        float maxWeight;

    public:
        Container(int length, int width, int height, float maxWeight);

        int getCountOfBoxes() const;

        float getTotalWeight() const;

        int getTotalSum() const;

        Box getByIndex(int) const;

        void addBox(Box box);

        void removeByIndex(int);

        friend std::ostream &operator<<(std::ostream &out, const Container &container);

        friend std::istream &operator>>(std::istream &in, Container &container);

        Box &operator[](const int index);
    };

}

#endif //UNIVER_PLUSES_CONTAINER_H
