
# AVL Tree test task

This repository is a solution to the test task for the Tools Intern Developer position at Syntacore.

https://syntacore.com/media/files/trial_task_tools.pdf

## Problem

Keys (k v) come from the standard input. v is an integer. All keys are different.

Two types of requests are also received:
- Query (m, i) to find the i-th smallest element;
- Query (n, j) to find the number of elements smaller than the given j.
Keys can be mixed with queries.

You need to design and implement a class that stores keys and provides an interface for running queries. Both types of queries should work with logarithmic complexity.

Bonus tasks:
- Implement constructors, destructor, and iterators for the class.
- Implement error messages that could be in the input dataset.

Example:
Input: k 8 k 2 k -1 m 1 m 2 n 3
Output: -1 2 2

## Dependencies

To build project you should use Linux system and install:
- Clang version 17.0.6
- CMake version 3.28.1 (C++20 modules used)
- Ninja version 1.11.1

## Building project

To build project open project directory with consol and run this two commands:
- cmake -DCMAKE_BUILD_TYPE:STRING=Release -DCMAKE_CXX_COMPILER:FILEPATH=clang++ -B build -G Ninja
- cmake --build build --config Release --target all --

## Running executable and tests

To run programm run executable:
- ./build/AVLTree < /path/filename

To run tests run executable from project dirrectory:
- ./build/AVLTree_tests

## Adding new tests

You cad add your test file in "tests" directory and add test in "_tests.cpp" like the latest tests.
