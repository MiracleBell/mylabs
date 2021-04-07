//
// Created by L on 10.03.2021.
//

#include "TestQueue.h"


using namespace tt2;

bool testConstructorsAndGetters1() {
    try {
        Queue<int> queue1(10);
        Queue<float> queue2(10);
        Queue<char> queue3(10);
        Queue<bool> queue4(10);
        Queue<std::string> queue5(10);
        return true;
    } catch (std::exception e) {
        return false;
    }
}

bool testConstructorsAndGetters2() {
    try {
        Queue<int> queue1(1);
        Queue<float> queue2(7);
        Queue<char> queue3(18);
        Queue<bool> queue4(200);
        Queue<std::string> queue5(1000);
        return true;
    } catch (std::exception e) {
        return false;
    }
}

bool testConstructorsAndGetters3() {
    try {
        Queue<int> queue(0);
        return false;
    } catch (std::exception e) {
        return true;
    }
}

bool testConstructorsAndGetters4() {
    try {
        Queue<int> queue(-12);
        return false;
    } catch (std::exception e) {
        return true;
    }
}

bool testPushBack1() {
    Queue<int> queue(1);
    queue.pushBack(99);
    return queue.getFirstElement() == 99;
}

bool testPushBack2() {
    Queue<double> queue(1);
    queue.pushBack(2.0);
    return queue.getFirstElement() == 2.0;
}

bool testPushBack3() {
    Queue<char> queue(1);
    queue.pushBack('Q');
    return queue.getFirstElement() == 'Q';
}

bool testPushBack4() {
    Queue<std::string> queue(1);
    queue.pushBack("test");
    return queue.getFirstElement() == "test";
}

bool testPushBack5() {
    Queue<int> queue(10);
    queue.pushBack(99);
    return queue.getFirstElement() == 99;
}

bool testPushBackException1() {
    Queue<int> queue(1);
    queue.pushBack(99);
    try {
        queue.pushBack(99);
        return false;
    } catch (std::exception e) {
        return true;
    }
}

bool testPushBackException2() {
    try {
        Queue<int> queue(1);
        queue.pushBack(99);
        queue.pushBack(0);
        return false;
    } catch (std::exception e) {
        return true;
    }
}

bool testPushBackException3() {
    try {
        Queue<double> queue(1);
        queue.pushBack(1.0);
        queue.pushBack(1.0);
        return false;
    } catch (std::exception e) {
        return true;
    }
}

bool testPushbackException4() {
    try {
        Queue<char> queue(1);
        queue.pushBack('R');
        queue.pushBack('J');
        return false;
    } catch (std::exception e) {
        return true;
    }
}

bool testPushBackException5() {
    Queue<int> queue(10);
    for (int i = 0; i < 9; ++i) {
        queue.pushBack(i);
    }
    try {
        queue.pushBack(10);
        return false;
    } catch (std::exception e) {
        return true;
    }
}

bool testPopFront1() {
    Queue<int> queue(10);
    queue.pushBack(11);
    queue.pushBack(55);
    return queue.popFront() == 11 &&
           queue.getFirstElement() == 55;
}

bool testPopFront2() {
    Queue<int> queue(10);
    for (int i = 0; i < 10; ++i) {
        queue.pushBack(i * 10);
    }
    return queue.popFront() == 0 &&
           queue.getFirstElement() == 1;
}

bool testPopFront3() {
    Queue<char> queue(10);
    queue.pushBack('R');
    queue.pushBack('Z');
    return queue.popFront() == 'R' &&
           queue.getFirstElement() == 'Z';
}

bool testPopFront4() {
    return false;
}

bool testPopFrontException1() {
    Queue<int> queue(1);
    try {
        queue.popFront();
        return false;
    } catch (std::exception e) {
        return true;
    }
}

bool testPopFrontException2() {
    Queue<int> queue(10);
    for (int i = 0; i < 5; ++i) {
        queue.pushBack(11 * i);
    }
    try {
        for (int i = 0; i < 6; ++i) {
            queue.popFront();
        }
        return false;
    } catch (std::exception e) {
        return true;
    }
}

bool testPopFrontException3() {
    Queue<int> queue(10);
    for (int i = 0; i < 5; ++i) {
        queue.pushBack(11 * i);
        queue.popFront();
    }
    try {
        queue.popFront();
        return false;
    } catch (std::exception e) {
        return true;
    }
}

bool testPopFrontException4() {
    Queue<char> queue(1);
    try {
        queue.popFront();
        return false;
    } catch (std::exception e) {
        return true;
    }
}

bool testPopFrontException5() {
    Queue<char> queue(10);
    for (int i = 0; i < 5; ++i) {
        queue.pushBack('Y');
    }
    try {
        for (int i = 0; i < 6; ++i) {
            queue.popFront();
        }
        return false;
    } catch (std::exception e) {
        return true;
    }
}

bool testPopFrontException6() {
    Queue<int> queue(10);
    for (int i = 0; i < 5; ++i) {
        queue.pushBack('L');
        queue.popFront();
    }
    try {
        queue.popFront();
        return false;
    } catch (std::exception e) {
        return true;
    }
}

bool testIsEmpty1() {
    Queue<int> queue(1);
    return queue.isEmpty();
}

bool testIsEmpty2() {
    Queue<int> queue(10);
    return queue.isEmpty();
}

bool testIsEmpty3() {
    Queue<char> queue(1);
    return queue.isEmpty();
}

bool testIsEmpty4() {
    Queue<char> queue(10);
    return queue.isEmpty();
}

bool testIsEmpty5() {
    Queue<double> queue(1);
    return queue.isEmpty();
}

bool testIsEmpty6() {
    Queue<double> queue(10);
    return queue.isEmpty();
}

bool testIsEmpty7() {
    Queue<std::string> queue(1);
    return queue.isEmpty();
}

bool testIsEmpty8() {
    Queue<std::string> queue(10);
    return queue.isEmpty();
}

bool testIsEmpty9() {
    Queue<int> queue(1);
    queue.pushBack(10);
    return !queue.isEmpty();
}

bool testIsEmpty10() {
    Queue<int> queue(10);
    queue.pushBack(10);
    queue.popFront();
    return queue.isEmpty();
}

bool testGetSize1() {
    Queue<int> queue(10);
    return queue.getSize() == 0;
}

bool testGetSize2() {
    Queue<int> queue(10);
    int len = 5;
    for (int i = 0; i < len; ++i) {
        queue.pushBack(i);
    }
    return queue.getSize() == len;
}

bool testGetSize3() {
    Queue<char> queue(10);
    int len = 7;
    for (int i = 0; i < 7; ++i) {
        queue.pushBack('N');
    }
    return queue.getSize() == 7;
}

bool testGetSize4() {
    Queue<double> queue(10);
    int len = 10;
    for (int i = 0; i < 10; ++i) {
        queue.pushBack(i);
    }
    return queue.getSize() == len;
}

bool testClear1() {
    Queue<int> queue(10);
    queue.clear();
    return queue.isEmpty();
}

bool testClear2() {
    Queue<char> queue(10);
    queue.clear();
    return queue.isEmpty();
}

bool testClear3() {
    Queue<int> queue(10);
    for (int i = 0; i < 10; ++i) {
        queue.pushBack(i);
    }
    queue.clear();
    return queue.isEmpty() &&
           queue.getSize() == 0;
}

bool testClear4() {
    Queue<char> queue(10);
    for (int i = 0; i < 10; ++i) {
        queue.pushBack('J');
    }
    queue.clear();
    return queue.isEmpty() &&
           queue.getSize() == 0;
}