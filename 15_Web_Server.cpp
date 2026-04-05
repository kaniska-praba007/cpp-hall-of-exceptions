#include <iostream>
#include <stdexcept>

using namespace std;

void startServer() {
    try {
        cout << "Server: Attempting to connect to Database..." << endl;
        
        // Inner Try Block: Handling a specific sub-task
        try {
            throw runtime_error("Database Timeout");
        } 
        catch (const runtime_error& e) {
            cout << "Inner Handler: " << e.what() << ". Attempting reconnection..." << endl;
            
            // If reconnection fails, we throw a more serious error to the outer block
            throw logic_error("Critical System Failure: Database unreachable.");
        }
    } 
    catch (const logic_error& e) {
        // Outer Handler: Catching the escalated error
        cerr << "Outer Handler: " << e.what() << " Shutting down server safely." << endl;
    }
}

int main() {
    startServer();
    return 0;
}

/* Sample Output:
Server: Attempting to connect to Database...
Inner Handler: Database Timeout. Attempting reconnection...
Outer Handler: Critical System Failure: Database unreachable. Shutting down server safely.
*/
