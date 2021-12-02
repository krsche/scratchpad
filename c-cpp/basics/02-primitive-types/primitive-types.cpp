#include "limits.h"
#include "float.h"
#include <iostream>

int main() {
    int myint = INT_MIN;
    short myshort = SHRT_MIN;

    float myfloat = FLT_MAX;
    double mydouble = DBL_MAX;

    bool mybool = true;
    char mychar = 'a';
    
    unsigned char myuchar = 0x13;
    int myarr[6] = {1,2,3,4,5,6};
    int myarr2[6] {1,2,3,4,5,6};

    std::cout << "MyInt:         " << myint << std::endl;
    std::cout << "MyShort:       " << myshort << std::endl;
    std::cout << "MyFloat:       " << myfloat << std::endl;
    std::cout << "MyDouble:      " << mydouble << std::endl;
    std::cout << "MyBool:        " << mybool << std::endl;
    std::cout << "MyChar:        " << mychar << std::endl;
    std::cout << "MyUChar:       " << myuchar << std::endl;
    std::cout << std::endl;

    // sizeof(myarr)  --> total number of bytes held by array
    // sizeof(*myarr) --> number of bytes of first array element
    int myarrsize = sizeof(myarr) / sizeof(*myarr);
    std::cout << "MyArr (size):  " << sizeof(*myarr) << std::endl;
    std::cout << "MyArr (Addr):  " << myarr << std::endl;
    std::cout << "MyArr (Val.):  ";
    for(int i=0; i < myarrsize; ++i) {
        std::cout << myarr[i] << ',';
    }
    std::cout << std::endl << std::endl;
    
    int myarr2size = sizeof(myarr2) / sizeof(*myarr2);
    std::cout << "MyArr (size):  " << myarr2size << std::endl;
    std::cout << "MyArr2 (Addr): " << myarr2 << std::endl;
    std::cout << "MyArr2 (Val.): ";
    for(int i=0; i < myarr2size; ++i) {
        std::cout << myarr2[i] << ',';
    }
    std::cout << std::endl << std::endl;
    

    return 0;
}