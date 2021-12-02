/*
    Base c++ classes for I/O:
    - std::basic_ostream   (responsible for output)
    - std::basic_istream   (responsible for input)
    
    Also provided typedefs for convenience:
    - std::ostream
    - std::istream

    Console:
    - 'std::cout' is obj of 'std::ostream' for console
    - 'std::cin'  is obj of 'std::istream' for console / keyboard
    - Insertion operator '<<' for cout
    - Extraction operator '>>' for cin

    <iostream> is the header providing all this
*/

#include <iostream>

int main() {
    using namespace std;

    cout << "Nice Output #" << 1337 << " and #" << 13.37f << endl;


    char favnumber[32] = {0};
    cout << "Now, enter your fav number: ";
    // if we use cin here, it won't clear the newline (enter) at the end, and the next cin.getline() or cin will immediately return
    // cin >> favnumber; 
    cin.getline(favnumber, 32, '\n');
    cout << "Nice, your fav number is: " << favnumber << endl;


    char buffer[512] = {0};
    cout << "and yo FULL name?: ";
    // cin >> buffer; // not suitable here, cin stops reading after first space
    cin.getline(buffer, 128, '\n');
    cout << "Aight, your FUULL name is '" << buffer << "'     ...great name! :)" << endl;
    
    return 0;
}