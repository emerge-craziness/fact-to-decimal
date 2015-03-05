#include <iostream>
#include <string>
using namespace std;

class Methods {
	    private:
		    long long int fact(int number) {
		        long long int r = 1;
		        for(int i = 1; i <= number; ++i) {
		            r *= (long long int)i;
		        }   
	        return r;
        }  

        public:
			long long int f2d() {
				string number_string;
                cout << "Enter your number (letters must be uppercase): ";
				cin >> number_string;
				int number[number_string.size()];
				for(int i = 0; i < number_string.size(); ++i) {
                    if(isdigit(number_string[i])) number[i] = (int)number_string[i] - 48;
                    else number[i] = (int)number_string[i] - 55;
                            //'A' & 'a' have different ANCII codes!
                            //I've used the uppercase 'A' here.
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

            int d2f() {
                long long int number;
                cout << "Enter your number: ";
                cin >> number;

                if(number == 0) {
                    cout << 0 << '\n';
                    return 0;
                }

                int closest_f = 0;
                while(fact(closest_f + 1) <= number) ++closest_f;

                int number_unconverted[closest_f];
                for(int i = 0; i < closest_f; ++i) {
                    number_unconverted[i] = number / fact(closest_f - i);
                    number %= fact(closest_f - i);
                }

                char number_converted[closest_f];
                for(int i = 0; i < closest_f; ++i) {
                    if(isdigit((char)(number_unconverted[i] + 48))) {
                        number_converted[i] = (char)(number_unconverted[i] + 48);
                    }
                    else {
                        number_converted[i] = (char)(number_unconverted[i] + 55);
                            //like in the similar situation in the f2d(), i used 'A' not 'a' here.
                    }
                }
                
                for(int i = 0; i < closest_f; ++i) cout << number_converted[i];
                cout << '\n';
            }
};

int main(int argc, char * argv[]) {
    if(argc < 2) {
        cout << "Possible arguments:\n" <<
                 "-f translates the number into the factorial num system\n" <<
                 "-d translates it to the decimal\n\n" << 
                 "If your number is incorrect, program returns -1.\n";
        return 1;
    }

    Methods f;
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
