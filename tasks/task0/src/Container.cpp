//
// Created by L on 15.02.2021.
//
#include <ostream>
#include "../include/Container.h"

namespace tt0 {
    Container::Container(int length, int width, int height, float maxWeight) : length(length), width(width),
                                                                               height(height),
                                                                               maxWeight(maxWeight) {}

    int Container::getCountOfBoxes() const {
        return boxes.size();
    }

    float Container::getTotalWeight() const {
        float total = 0.0;
        for (auto &item:boxes) {
            total += item.weight;
        }
        return total;
    }

    int Container::getTotalSum() const {
        int total = 0;
        for (auto &item:boxes) {
            total += item.value;
        }
        return total;
    }

    Box Container::getByIndex(int index) const {
        if (index < 0 || index > boxes.size() - 1) {
            throw std::exception("Index out bond of boarders");
        }
        return boxes[index];
    }

    void Container::addBox(Box box) {
        if (box.weight > maxWeight - getTotalWeight()) {
            throw std::exception("OverWeight");
        }
        boxes.push_back(box);
    }

    void Container::removeByIndex(int index) {
        if (index < 0 || index > boxes.size() - 1) {
            throw std::exception("Incorrect index");
        }
        boxes.erase(boxes.begin() + index);
    }

    std::ostream &operator<<(std::ostream &out, const Container &container) {
        out << " length: " << container.length << "\n" << " width: " << container.width << "\n"
            << " height: " << container.height << "\n" << " maxWeight: " << container.maxWeight << "\n";
        return out;
    }

    std::istream &operator>>(std::istream &in, Container &container) {
        in >> container.length;
        in >> container.width;
        in >> container.height;
        in >> container.maxWeight;

        return in;
    }

    Box &Container::operator[](const int index) {
        return boxes.at(index);
    }

}

