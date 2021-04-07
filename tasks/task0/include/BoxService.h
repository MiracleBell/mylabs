//
// Created by L on 15.02.2021.
//

#ifndef UNIVER_PLUSES_BOXSERVICE_H
#define UNIVER_PLUSES_BOXSERVICE_H

#include "Box.h"

namespace tt0 {
    int totalSum(Box *boxesArray[], int arraySize) {
        int result = 0;
        for (int i = 0; i < arraySize; ++i) {
            result += boxesArray[i]->value;
        }
        return result;
    }

    bool checkBoxesSize(Box *boxesArray[], int arraySize, int maxValue) {
        for (int i = 0; i < arraySize; ++i) {
            if (maxValue < boxesArray[i]->length || maxValue < boxesArray[i]->height ||
                maxValue < boxesArray[i]->width) {
                return false;
            }
        }
        return true;
    }

    float maxWeight(Box *boxesArray[], int arraySize, int maxVolume) {
        float result = 0.0;
        for (int i = 0; i < arraySize; ++i) {
            if (boxesArray[i]->length * boxesArray[i]->height * boxesArray[i]->width < maxVolume &&
                boxesArray[i]->weight > result) {
                result = boxesArray[i]->weight;
            }
        }
        return result;
    }

    bool checkInner(Box *boxesArray[], int arraySize) {
        for (int i = 0; i < arraySize - 1; ++i) {
            for (int j = i + 1; j < arraySize; ++j) {
                if (!(boxesArray[i] < boxesArray[j] || boxesArray[i] > boxesArray[j])) {
                    return false;
                }
            }
        }
        return true;
    }

}

#endif //UNIVER_PLUSES_BOXSERVICE_H
