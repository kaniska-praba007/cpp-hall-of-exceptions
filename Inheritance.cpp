//catching a base class reference allows you to handle any related error type with one block

#include <iostream>

using namespace std;

class FileError {}; // Base class
class PermissionError : public FileError {}; // Derived class

int main() {
    try {
        throw PermissionError();
    } 
    catch (const FileError& e) {
        // Because PermissionError IS A FileError, this block catches it
        cout << "Caught a file-related error using the Base class reference." << endl;
    }
    return 0;
}
/* Sample Output:
Caught a file-related error using the Base class reference.
*/
