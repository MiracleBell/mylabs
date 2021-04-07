#include "tests/task0/TestTask0.h"
#include "tests/task1/TestTask1.h"
#include "tests/task2/TestTask2.h"


int main() {
    testTask0();
    testTask1();
    testTask2();

    tt2::Queue<int> queue(10);
    queue.isEmpty()
    return 0;
}

