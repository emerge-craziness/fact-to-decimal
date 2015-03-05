#ifndef METHODS_HPP
#define METHODS_HPP

#include <iostream>
#include <string>

class methods {
        private:
            template <typename Type> Type get_num();
            /* It gets the number from the std input stream */

		    long long int fact(int number);
            /* This function calculates the factorial of the _number_ */

        public:
            long long int f2d();
            /* Translates a number from the factorial numsys to the decimal */

            int d2f();
            /* Vice versa:
             * It translates a number from the decimal numsys to the factorial */
};

#endif
