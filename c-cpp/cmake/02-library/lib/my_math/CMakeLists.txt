cmake_minimum_required(VERSION 3.10)
project(scratchpad-c-cpp-cmake-02-library-my-math)

set(TARGET_LIB my_math)
add_library(${TARGET_LIB}
    src/add.cpp 
    src/subtract.cpp)
target_include_directories(${TARGET_LIB} PUBLIC include)

set(TARGET_TEST ${CMAKE_PROJECT_NAME}--test)
add_executable(${TARGET_TEST}
    test/main.cpp)
target_link_libraries(${TARGET_TEST}
    my_math)