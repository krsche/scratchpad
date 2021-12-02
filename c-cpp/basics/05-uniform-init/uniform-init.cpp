#include <string>

int main() {
    // uninitialized
    int a1; 
    char d1[8];
    int *t1 = new int;          // on heap

    // copy init (this should be avoided for user def. types)
    int a2 = 0;
    char d2[8] = {'\0'};
    char d3[8] = {'a', 'b', 'c'}; // aggregate init
    char d4[8] = {"abc"};

    // direct init
    int a3(5);
    std::string s1("c++");
    // int a4() // most vexing parse

    // ---------------------------
    // Uniform init
    // ---------------------------
    int b1{};           // value init (default value of type)
    char e1[8]{};       // value init (default value of type)
    char e2[8]{"123"};  // direct init
    int b2{5};          // direct init
    
    // also works on the heap
    int *p1 = new int{};
    char *p2 = new char[8]{};

    /*
        Summary:

        1. Value initialization     --> T obj{};
        2. Direct initialization    --> T obj{v}
        3. Copy initialization      --> T obj = v;

        Benefits of uniform init:
        - Forces initialization
        - Able to directly init arrays
        - prevents narrowing conversions (float f{}; int i{f}; --> error)
        - uniform syntax for all types

        Verdict - Use uniform init everywhere?
        - 'Depends on pers. preference'
        - For primitive types assignments are fine
        - For complex/user-defined types, defo use uniform init
    */

    return 0;
}