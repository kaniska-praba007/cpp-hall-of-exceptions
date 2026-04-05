#include <iostream>   
#include <stdexcept>  // For standard exception classes (invalid_argument)

using namespace std;

// Function to validate and process a withdrawal
void setWithdrawal(int amount) {
    // Logic check: amounts must be positive for a withdrawal
    if (amount < 0) {
        throw invalid_argument("Withdrawal amount cannot be negative.");
    }
    cout << "Processing: $" << amount << endl;
}

int main() {
    try {
        // calling the function with an invalid value
        setWithdrawal(-50);
    } 
      
    //We use 'const invalid_argument& e' to catch the exception by  reference, which is efficient and prevents 'slicing' the object.
    catch (const invalid_argument& e) {
        // 'e.what()' retrieves the string passed during the 'throw'
        cerr << "Bank Error: " << e.what() << endl;
    }
    return 0;
}


/* Sample Output:
Bank Error: Withdrawal amount cannot be negative.
*/
