#include <iostream>

using namespace std;

class Calculator {
    int value;
public:
    // Constructor to initialize the starting value
    Calculator(int v) : value(v) {}

    // Overloading the '/' operator to work with Calculator objects
    int operator/(int d) {
        // Logic check: Division by zero is undefined in mathematics
        if (d == 0) {
            // We throw a string literal as the exception
            throw "Illegal Division by zero!";
        }
        return value / d;
    }
};

int main() {
    Calculator calc(100);
    try {
        /* * Using the overloaded '/' operator.
         * Since we pass 0, the code inside 'operator/' will throw an error.
         */
        cout << (calc / 0) << endl;
    } 
    // We catch the 'const char*' (the string literal) thrown above
    catch (const char* msg) {
        cout << "Operator Error: " << msg << endl;
    }
    return 0;
}
