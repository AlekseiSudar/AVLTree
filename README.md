
# AVL Tree test task

## Dependencies
To build project you should use Linux system and install:
* Clang vertion 17.0.6
* CMake vertion 3.28.1 (C++20 modules used)
* Ninja version 1.11.1

## Building project
To build project open project directory with consol and run this two commands:
* cmake -DCMAKE_BUILD_TYPE:STRING=Release -DCMAKE_CXX_COMPILER:FILEPATH=clang++ -B build -G Ninja
* cmake --build build --config Release --target all --

## Running executable and tests
To run programm run executable:
* ./build/AVLTree < /path/filename
To run tests run executable from project dirrectory:
* ./build/AVLTree_tests

## Adding new tests
You cad add your test file in "tests" directory and add test in "_tests.cpp" like the latest tests.
