#include <iostream>

#include "my_math/add.h"
#include "my_math/subtract.h"

int main(void) {
    if(add(1,3) == 4) {
        std::cout << "TEST: add(1,3) == 4  {SUCCESSFUL}" << std::endl;
    }
    else {
        std::cout << "TEST: add(1,3) == 4  {FAILED}" << std::endl;
    }
    
    if(subtract(1,3) == -2) {
        std::cout << "TEST: subtract(1,3) == -2  {SUCCESSFUL}" << std::endl;
    }
    else {
        std::cout << "TEST: subtract(1,3) == -2  {FAILED}" << std::endl;
    }
    
    return 0;
}