#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    try {
        // Trying to allocate an impossible amount of memory
        long long* data = new long long[999999999999];
        delete[] data;
    } 
    catch (const bad_alloc& e) {
        cerr << "Hardware Limit: " << e.what() << " - Not enough RAM." << endl;
    }
    return 0;
}
/* Sample Output:
Hardware Limit: std::bad_alloc - Not enough RAM.
*/
