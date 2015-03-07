#include <iostream>
#include <string>
#include "methods.hpp"

using namespace std;

int main(int argc, char * argv[]) {

    if(argc < 2) {
        cout << "Possible arguments:\n" <<
                 "-f translates the number into the factorial num system\n" <<
                 "-d translates it to the decimal\n\n" << 
                 "If your number is incorrect, program returns -1.\n";
        return 1;
    }

    methods f;
    if (argv[1][0] == '-') {
        switch (argv[1][1]) {
         case 'f':
            cout << f.d2f() << "\n";
            break;
         case 'd': 
            cout << f.f2d() << "\n";
            break;
         default:
            cout << "Incorrect argument\n";
            break;
        }
    }
    else {
        cout << "Incorrect argument\n";
    }
}
