//If an exception is thrown but no catch block is found, terminate() is called. 
//we can also customise this behaviour using set_terminate()

#include <iostream>
#include <exception>

using namespace std;

void myEmergencyHandler() {
    cout << "EMERGENCY: An unhandled exception occurred. Closing files safely..." << endl;
    exit(1); // Force close the program
}

int main() {
    // Telling C++ to use our function if a catch block is missing
    set_terminate(myEmergencyHandler);

    throw 55.5; // No 'catch (double)' exists, so it triggers the emergency handler
    return 0;
}
/* Sample Output:
EMERGENCY: An unhandled exception occurred. Closing files safely...
*/
