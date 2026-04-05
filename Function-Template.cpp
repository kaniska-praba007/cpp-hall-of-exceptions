#include <iostream>

using namespace std;

/**
 * 'template <typename T>' allows this function to work with ANY type 
 * (int, double, float, etc.) without writing a separate function for each.
 */
template <typename T>
void validateData(T input) {
    // Logic: If the value is negative, we "throw" the value itself as the error
    if (input < 0) {
        throw input; 
    }
    cout << "Data accepted: " << input << endl;
}

int main() {
    try {
        /* * When we pass -12.5, 'T' automatically becomes a 'double'.
         * The function then throws a 'double' type exception.
         */
        validateData(-12.5); 
    } 
    /* * This catch block is specifically looking for a 'double'.
     * If we threw an 'int', this block would be skipped.
     */
    catch (double e) {
        cout << "Caught generic negative value: " << e << endl;
    }
    return 0;
}

/* Sample Output:
Caught generic negative value: -12.5
*/
