cmake_minimum_required(VERSION 3.17)
project(univer_pluses)

set(CMAKE_CXX_STANDARD 20)

add_executable(univer_pluses main.cpp tasks/task0/include/Box.h tasks/task0/include/BoxService.h tasks/task0/src/Container.cpp tasks/task0/include/Container.h tasks/task1/src/DynamicArray.cpp tasks/task1/include/DynamicArray.h tests/include/TestTask1.h tests/include/TestTask0.h tasks/task2/include/Queue.h tasks/task2/src/Iterator.cpp tasks/task2/include/Iterator.h tests/include/task2/TestTask2.h tests/src/TestTask1.cpp tests/src/TestTask0.cpp tests/src/task2/TestTask2.cpp tests/src/task2/TestIterator.cpp tests/include/task2/TestIterator.h tests/src/task2/TestQueue.cpp tests/include/task2/TestQueue.h)