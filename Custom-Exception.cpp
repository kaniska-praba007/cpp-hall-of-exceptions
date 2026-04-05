#include <iostream>
#include <exception>

using namespace std;

// We inherit from 'exception' to stay consistent with C++ standards
class BatteryLowException : public exception {
public:    
     // 'override' (C++11) tells the compiler we are replacing the base version.
     // 'noexcept' promises this function itself won't crash or throw errors.
    const char* what() const noexcept override {
        return "Device Alert: Battery below 5%. Please plug in.";
    }
};

int main() {
    try {
        throw BatteryLowException();
    } 
    catch (const BatteryLowException& e) {
        cout << e.what() << endl;
    }
    return 0;
}
/* Sample Output:
Device Alert: Battery below 5%. Please plug in.
*/
