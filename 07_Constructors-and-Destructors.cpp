//If an exception occurs, C++ runs destructors for all local objects to prevent memory leaks.
#include <iostream>

using namespace std;

class Resource {
public:
    Resource() { cout << "Resource Acquired." << endl; }
    ~Resource() { cout << "Resource Cleaned Up (Destructor)." << endl; }
};

int main() {
    try {
        Resource r; // Object is created on the stack
        throw "Critical Failure";
    } 
    catch (...) {
        // Notice that the destructor runs BEFORE we reach this line
        cout << "Handling error now." << endl;
    }
    return 0;
}

/* Sample Output:
Resource Acquired.
Resource Cleaned Up (Destructor).
Handling error now.
*/
