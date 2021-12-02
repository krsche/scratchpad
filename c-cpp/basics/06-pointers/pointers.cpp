#include <iostream>

int main() {
    using namespace std;

    // First things first
    int a{10};          // variable
    int *b = &a;        // pointer to address of 'a'
    int c = *b;         // *b = value stored in memory at address held by b
                        // (* = dereferencing operator)

    cout << "a      = " << a << endl;    // prints value
    cout << "b (&a) = " << b << endl;    // prints address
    cout << "c (*b) = " << *b << endl;   // prints value stored in memory at address b


    // Secondly
    float x{13.37};
    //int *y = &x;                // won't compile
    //float *y = &x;              // works, but already shown above
    void *y = &x;               // this also works - a pointer with no type info
    float z = *((float*) y);    // first cast y to be of type float-pointer, then dereference it

    cout << "x                 = " << x << endl;
    cout << "y (&x)            = " << y << endl;    // void pointer!
    cout << "z (*((float*) y)) = " << z << endl;    // void pointer casted back to float and de-referenced`

    
    /* NULL or nullptr
       - NULL is macro in C & pre-C++11
       - defined as 0 in most compilers
       - used to init pointer types
       - nullptr is introduced in C++11 and typesafe
       - suggestion is to use nullptr over NULL, but tbh I'm not yet sure why...
    */

    void *mynullpointer = nullptr;
    // cout << *mynullpointer << endl;     // this won't work ^^ can't access a null pointer

    return 0;
}