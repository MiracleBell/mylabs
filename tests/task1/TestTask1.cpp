//
// Created by L on 09.03.2021.
//
#include "TestTask1.h"


using namespace tt1;

void testTask1() {
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|Test 1|" << std::endl;
    std::cout << "--------" << std::endl;

    std::cout << "|" << "test 1 DynamicArray constructors = " << testConstructorAndGetters1() << std::endl;
    std::cout << "|" << "test 2 DynamicArray constructors = " << testConstructorAndGetters2() << std::endl;
    std::cout << "|" << "test 3 DynamicArray constructors = " << testConstructorAndGetters3() << std::endl;
    std::cout << "|" << "test 4 DynamicArray constructors = " << testConstructorAndGetters4() << std::endl;
    std::cout << "|" << "test 5 DynamicArray constructors = " << testConstructorAndGetters5() << std::endl;
    std::cout << "|" << "test 6 DynamicArray constructors = " << testConstructorAndGetters6() << std::endl;

    std::cout << "|" << "test 1 function resize() from DynamicArray = " << testResize1() << std::endl;
    std::cout << "|" << "test 2 function resize() from DynamicArray = " << testResize2() << std::endl;
    std::cout << "|" << "test 3 function resize() from DynamicArray = " << testResize3() << std::endl;
    std::cout << "|" << "test 4 function resize() from DynamicArray = " << testResize4() << std::endl;
    std::cout << "|" << "test 5 function resize() from DynamicArray = " << testResize5() << std::endl;

    std::cout << "|" << "test 1 function reserve() from DynamicArray = " << testReserve1() << std::endl;
    std::cout << "|" << "test 2 function reserve() from DynamicArray = " << testReserve2() << std::endl;
    std::cout << "|" << "test 3 function reserve() from DynamicArray = " << testReserve3() << std::endl;

    std::cout << "|" << "test 1 function pushBack() from DynamicArray = " << testPushBack1() << std::endl;
    std::cout << "|" << "test 2 function pushBack() from DynamicArray = " << testPushBack2() << std::endl;

    std::cout << "|" << "test1 function popBack() from DynamicArray = " << testPopBack1() << std::endl;
    std::cout << "|" << "test2 function popBack() from DynamicArray = " << testPopBack2() << std::endl;
}

bool testConstructorAndGetters1() {
    const int size = 10;
    const int capacity = 10;
    DynamicArray array1;
    DynamicArray array2;

    if (array1.getSize() != size) {
        return false;
    }
    if (array1.capacity() != capacity) {
        return false;
    }

    for (int i = 0; i < array1.getSize(); ++i) {
        if (array1[i] != 0) {
            return false;
        }
    }
    if (array1 != array2) {
        return false;
    }
    return true;
}

bool testConstructorAndGetters2() {
    const int size = 5;
    const int capacity = 10;

    DynamicArray array1(size);

    if (array1.getSize() != size) {
        return false;
    }
    if (array1.capacity() != capacity) {
        return false;
    }

    for (int i = 0; i < array1.getSize(); ++i) {
        if (array1[i] != 0) {
            return false;
        }
    }
    return true;
}

bool testConstructorAndGetters3() {
    try {
        const int size = -5;
        const int capacity = 0;

        DynamicArray array1(size);
        return false;
    } catch (std::exception e) {
        return true;
    }
}

bool testConstructorAndGetters4() {
    const int size = 10;
    const int default_elem = 76;
    const int capacity = 10;
    DynamicArray array1(size, default_elem);

    if (array1.getSize() != size) {
        return false;
    }
    if (array1.capacity() != capacity) {
        return false;
    }

    for (int i = 0; i < array1.getSize(); ++i) {
        if (array1[i] != default_elem) {
            return false;
        }
    }
    return true;
}

bool testConstructorAndGetters5() {
    const int size = 10;
    const int default_elem = 76;
    const int capacity = 17;
    DynamicArray array1(size, capacity, default_elem);

    if (array1.getSize() != size) {
        return false;
    }
    if (array1.capacity() != capacity) {
        return false;
    }

    for (int i = 0; i < array1.getSize(); ++i) {
        if (array1[i] != default_elem) {
            return false;
        }
    }
    return true;
}

bool testConstructorAndGetters6() {
    try {
        const int size = 10;
        const int default_elem = 76;
        const int capacity = -13;
        DynamicArray array1(size, capacity, default_elem);
        return false;
    } catch (std::exception e) {
        return true;
    }
}

bool testResize1() {
    const int size = 10;
    const int default_elem = 76;
    const int buffer = 10;
    DynamicArray array(size, default_elem);

    int new_size = 5;
    array.resize(new_size);
    if (array.getSize() != new_size) {
        return false;
    }
    if (array.capacity() != new_size + buffer) {
        return false;
    }
    return true;
}

bool testResize2() {
    const int size = 10;
    const int default_elem = 76;
    const int buffer = 2;
    DynamicArray array(size, default_elem);

    int new_size = 18;
    array.resize(new_size);
    if (array.getSize() != new_size) {
        return false;
    }
    if (array.capacity() != buffer) {
        return false;
    }
    return true;
}

bool testResize3() {
    const int size = 10;
    const int default_elem = 76;
    const int buffer = 10;
    DynamicArray array(size, default_elem);

    int new_size = 25;
    array.resize(new_size);
    if (array.getSize() != new_size) {
        return false;
    }
    if (array.capacity() != buffer) {
        return false;
    }
    return true;
}

bool testResize4() {
    const int size = 10;
    const int default_elem = 76;
    const int buffer = 2;
    DynamicArray array(size, default_elem);

    int new_size = 18;
    array.resize(new_size);
    if (array.getSize() != new_size) {
        return false;
    }
    if (array.capacity() != buffer) {
        return false;
    }
    return true;
}

bool testResize5() {
    const int size = 10;
    const int default_elem = 76;
    const int buffer = 17;
    DynamicArray array(size, default_elem);

    int new_size = 3;
    array.resize(new_size);
    if (array.getSize() != new_size) {
        return false;
    }
    if (array.capacity() != buffer) {
        return false;
    }
    return true;
}


bool testReserve1() {
    const int size = 13;
    const int default_elem = 76;
    const int buffer = 10;
    DynamicArray array(size, default_elem, buffer);

    int new_buffer = buffer + 5;
    array.reserve(new_buffer);
    if (array.getSize() != size) {
        return false;
    }
    if (array.capacity() != new_buffer) {
        return false;
    }
    return true;
}

bool testReserve2() {
    const int size = 13;
    const int default_elem = 76;
    const int buffer = 10;
    DynamicArray array(size, default_elem, buffer);

    int new_buffer = buffer - 5;
    array.reserve(new_buffer);
    if (array.getSize() != size) {
        return false;
    }
    if (array.capacity() != new_buffer) {
        return false;
    }
    return true;
}

bool testReserve3() {
    try {
        const int size = 13;
        const int default_elem = 76;
        const int buffer = 10;
        DynamicArray array(size, default_elem, buffer);

        int new_buffer = -10;
        array.reserve(new_buffer);

        return false;
    } catch (std::exception e) {
        return true;
    }
}

bool testPushBack1() {
    const int size = 13;
    const int default_elem = 76;
    const int buffer = 10;
    DynamicArray array(size, buffer, default_elem);

    array.pushBack(999);
    array.pushBack(1111);

    if (array.getSize() != size + 2) {
        return false;
    }
    if (array.capacity() != buffer - 2) {
        return false;
    }
    if (array[13] != 999 || array[14] != 1111) {
        return false;
    }
    return true;
}

bool testPushBack2() {
    try {
        const int size = 13;
        const int default_elem = 76;
        const int buffer = 0;
        DynamicArray array(size, buffer, default_elem);

        array.pushBack(999);
        return false;
    } catch (std::exception e) {
        return true;
    }
}

bool testPopBack1() {
    const int size = 13;
    const int default_elem = 76;
    const int buffer = 10;
    DynamicArray array(size, buffer, default_elem);

    array.popBack();
    array.popBack();
    int new_size = 11;
    int new_buffer = 12;

    if (array.getSize() != new_size) {
        return false;
    }
    if (array.capacity() != new_buffer) {
        return false;
    }

    return true;
}


bool testPopBack2() {
    try {
        const int size = 1;
        const int default_elem = 76;
        const int buffer = 10;
        DynamicArray array(size, buffer, default_elem);

        array.popBack();
        array.popBack();

        return false;
    } catch (std::exception e) {
        return true;
    }
}


