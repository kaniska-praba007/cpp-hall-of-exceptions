#include <iostream>

using namespace std;

/**
 * 'noexcept' is a promise to the compiler.
 * It means: "This function will never throw an error."
 * This allows the program to run slightly faster and more safely.
 */

void printStatus() noexcept {
    cout << "System Status: Green" << endl;
}

int main() {
    // We can call this safely without a try-catch block
    printStatus();
    
    return 0;
}

/* Sample Output:
System Status: Green
*/
