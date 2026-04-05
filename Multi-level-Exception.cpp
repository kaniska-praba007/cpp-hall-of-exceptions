#include <iostream>

using namespace std;

void logError() {
    try {
        throw "Disk Write Failure";
    } 
    catch (const char* e) {
        cout << "Local Log: Writing error to file..." << endl;
        throw; // Rethrow the exact same exception to the caller
    }
}

int main() {
    try {
        logError();
    } 
    catch (const char* e) {
        cout << "Main: Notifying user of " << e << endl;
    }
    return 0;
}
/* Sample Output:
Local Log: Writing error to file...
Main: Notifying user of Disk Write Failure
*/
