cmake_minimum_required(VERSION 3.10)

project(scratchpad-c-cpp-cmake-02-library)

add_subdirectory(lib/my_math)

add_executable(main 
    main.cpp)
target_link_libraries(main PRIVATE 
    my_math)