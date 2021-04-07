//
// Created by L on 09.03.2021.
//
#include "TestTask0.h"

using namespace tt0;

void testTask0() {
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|Test 0|" << std::endl;
    std::cout << "--------" << std::endl;
    std::cout << "|" << "test structure Box = " << testClassBox() << std::endl;

    std::cout << "|" << "test 1 functions from BoxService = " << testClassBoxService1() << std::endl;
    std::cout << "|" << "test 2 functions from BoxService = " << testClassBoxService2() << std::endl;

    std::cout << "|" << "test 1 class Container = " << testClassContainer1() << std::endl;
    std::cout << "|" << "test 2 class Container = " << testClassContainer2() << std::endl;
    std::cout << "|" << "test 3 class Container = " << testClassContainer3() << std::endl;
}

bool testClassBox() {
    tt0::Box box1(1, 1, 1, 1, 10);
    tt0::Box box2(2, 2, 2, 2, 20);
    tt0::Box box3(1, 1, 1, 1, 10);

    if (box1 == box2) {
        return false;
    }
    if (!(box1 == box3)) {
        return false;
    }
    if (box2 == box3) {
        return false;
    }

    return true;
}


bool testClassBoxService1() {
    int result_sum = 0;
    int const array_size = 10;
    Box *boxArray[array_size];

    for (int i = 0; i < array_size; ++i) {
        boxArray[i] = new Box(
                i,
                i,
                i,
                i,
                i * 10
        );
        result_sum += i * 10;
    }

    if (result_sum != totalSum(boxArray, array_size)) {
        return false;
    }

    int max_value = 100;
    if (!checkBoxesSize(boxArray, array_size, max_value)) {
        return false;
    }

    int max_volume = 1000;
    float max_weight = 9;
    if (max_weight != maxWeight(boxArray, array_size, max_volume)) {
        return false;
    }
    return true;
}

bool testClassBoxService2() {
    int result_sum = 0;
    int const array_size = 10;
    Box *boxArray[array_size];

    for (int i = 0; i < array_size; ++i) {
        boxArray[i] = new Box(
                i,
                i,
                i,
                i,
                i * 10
        );
        result_sum += i * 10;
    }

    if (result_sum != totalSum(boxArray, array_size)) {
        return false;
    }

    int max_value = 100;
    if (!checkBoxesSize(boxArray, array_size, max_value)) {
        return false;
    }

    int max_volume = 1000;
    float max_weight = 9;
    if (max_weight != maxWeight(boxArray, array_size, max_volume)) {
        return false;
    }

    if (!checkInner(boxArray, array_size)) {
        return false;
    }
    return true;
}


bool testClassContainer1() {
    Container container(100, 100, 100, 1000);


    Box box1(1, 1, 1, 1, 10);
    Box box2(2, 2, 2, 2, 20);
    container.addBox(box1);
    container.addBox(box2);

    return true;
}

bool testClassContainer2() {
    Container container(100, 100, 100, 1000);

    int total_sum = 30;

    Box box1(1, 1, 1, 1, 10);
    Box box2(2, 2, 2, 2, 20);
    container.addBox(box1);
    container.addBox(box2);


    container.getByIndex(0);
    if (!(box1 == container.getByIndex(0))) {
        return false;
    }
    if (!(box2 == container.getByIndex(1))) {
        return false;
    }
    if (container.getTotalSum() != total_sum) {
        return false;
    }


    return true;
}

bool testClassContainer3() {
    Container container(100, 100, 100, 1000);

    Box box1(1, 1, 1, 1, 10);
    Box box2(2, 2, 2, 2, 20);
    container.addBox(box1);
    container.addBox(box2);

    try {
        container.removeByIndex(1);
        container.getByIndex(1);
        return false;
    } catch (std::exception ex) {
        ex.what();
    }

    return true;
}

