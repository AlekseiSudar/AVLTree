cmake_minimum_required(VERSION 3.28.1)
project(SyntacoreTestProject CXX)

set(CMAKE_CXX_STANDARD 20)


add_executable(AVLTree source/main.cpp)
target_sources(AVLTree
  PUBLIC
    FILE_SET CXX_MODULES FILES
    source/interface.cpp
    source/AVL.cpp
)


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(
  AVLTree_tests
  tests/_tests.cpp
)
target_sources(
  AVLTree_tests
  PUBLIC
    FILE_SET CXX_MODULES FILES
    source/AVL.cpp
    source/interface.cpp
    tests/_SetInterface.cpp
)
target_link_libraries(
  AVLTree_tests
  GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(AVLTree_tests)
