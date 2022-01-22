cmake_minimum_required(VERSION 3.14)
project(scratchpad-c-cpp-cmake-03-library-with-gtest)

# --- GoogleTest
# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)
# --- GoogleTest

set(TARGET_LIB my_math)
add_library(${TARGET_LIB}
    src/add.cpp 
    src/subtract.cpp)
target_include_directories(${TARGET_LIB} PUBLIC include)

# --- GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(TARGET_TEST ${CMAKE_PROJECT_NAME}--test)
add_executable(${TARGET_TEST}
    test/main.cpp)
target_link_libraries(${TARGET_TEST}
    my_math
    gtest_main)
    
include(GoogleTest)
gtest_discover_tests(${TARGET_TEST})
# --- GoogleTest
