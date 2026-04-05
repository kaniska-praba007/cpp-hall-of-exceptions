#include <iostream>

using namespace std;

int main() {
    try {
        throw 404; // Throwing a simple int
    } 
    catch (const char* e) {
        cout << "Caught a string." << endl;
    }
    catch (...) {
        // This is the safety net for any type not listed above
        cout << "Caught an unknown exception type!" << endl;
    }
    return 0;
}
/* Sample Output:
Caught an unknown exception type!
*/
