#include "methods.hpp"
#include <iostream>
#include <string>
using namespace std;

long long int methods::fact(int number) {
    long long int r = 1;
    for(int i = 1; i <= number; ++i) {
        r *= (long long int)i;
    }   
    return r;
}  

template <typename Type> Type methods::get_num() {
    Type number;
    cout << "Enter your number (btw, letters must be uppercase): ";
    cin >> number;
    return number;
}

long long int methods::f2d() {
    string number_string = get_num <string> ();

    int number[number_string.size()];
    for(int i = 0; i < number_string.size(); ++i) {
        if(isdigit(number_string[i])) number[i] = (int)number_string[i] - 48;
        else number[i] = (int)number_string[i] - 55;
                //'A' & 'a' have different ANCII codes
                //the uppercase 'A' is used
    }

    for(int i = 1; i <= number_string.size(); ++i) {
        int t = number_string.size() - i;
        if (number[t] > fact(i)) return -1;
    }

    long long int result = 0;
    for(int i = 1; i <= number_string.size(); ++i) {
        int t = number_string.size() - i;
        result += number[t] * fact(i);
    }
    return result;
}

int methods::d2f() {
    long long int number = get_num <long long int> ();

    if(number == 0) {
        cout << 0 << '\n';
        return 0;
    }

    int closest_f = 0;
    while (fact (++closest_f) <= number);
    --closest_f;

    int *number_unconverted = new int[closest_f];
    for (int i = 0; i < closest_f; ++i) {
        number_unconverted[i] = number / fact (closest_f - i);
        number %= fact (closest_f - i);
    }

    char *number_converted = new char[closest_f];
    for (int i = 0; i < closest_f; ++i) {
        if (isdigit ((char)(number_unconverted[i] + 48))) {
            number_converted[i] = (char)(number_unconverted[i] + 48);
        }
        else {
            number_converted[i] = (char)(number_unconverted[i] + 55);
                //like in the similar situation in the f2d(), i used 'A' not 'a' here.
        }
    }
    
    for (int i = 0; i < closest_f; ++i) {
        cout << number_converted[i];
    }
    cout << '\n';

    delete[] number_converted;
    delete[] number_unconverted;

    return 0;
}
