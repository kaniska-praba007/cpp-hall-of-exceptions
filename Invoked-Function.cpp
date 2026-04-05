#include <iostream>

using namespace std;

// This function simulates a failure
void databaseQuery() {
    /* * We are throwing a 'string literal' (const char*).
     * This immediately stops this function and looks for a 'catch' block.
     */
    throw "Connection Timeout"; 
}

// This function calls the one that throws an error
void loadUserProfile() {
    /* * This function does NOT handle the error. 
     * Because it lacks a try-catch, the exception 'propagates' upward 
     * to whoever called loadUserProfile().
     */
    databaseQuery(); 
}

int main() {
    try {
        // We call the chain of functions here
        loadUserProfile();
    } 
    /* * This is the 'catch' block that finally stops the error.
     * It matches the type (const char*) that was thrown originally.
     */
    catch (const char* msg) {
        // The program skips the rest of the try block and runs this instead
        cout << "System recovered from: " << msg << endl;
    }
    
    return 0;
}

/* Sample Output:
System recovered from: Connection Timeout
*/
