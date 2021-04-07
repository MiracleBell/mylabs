cmake_minimum_required(VERSION 3.17)
project(univer_pluses)

set(CMAKE_CXX_STANDARD 20)

add_executable(univer_pluses main.cpp tasks/task0/include/Box.h tasks/task0/include/BoxService.h tasks/task0/src/Container.cpp tasks/task0/include/Container.h tasks/task1/src/DynamicArray.cpp tasks/task1/include/DynamicArray.h tests/task1/TestTask1.h tests/task0/TestTask0.h tasks/task2/Queue.h tests/task2/TestTask2.h tests/task1/TestTask1.cpp tests/task0/TestTask0.cpp tests/task2/TestTask2.cpp tests/task2/TestQueue.cpp tests/task2/TestQueue.h)