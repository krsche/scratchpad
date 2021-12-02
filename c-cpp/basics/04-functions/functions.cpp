#include <iostream>

// declaration / prototype (would work here, but is in .hpp)
//int add(int a, int b);
#include "functions.hpp"

int main() {
    std::cout << add(917, 420) << std:: endl;

    return 0;
}

// definition
int add(int a, int b) {
    return a + b;
}