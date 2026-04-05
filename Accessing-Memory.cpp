#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

int main() {
    // A dynamic array initialized with three integers
    vector<int> scores = {90, 85, 70};

    try {
        // .at(5) checks if index 5 exists; if not, it throws an exception
        cout << scores.at(5) << endl; 
    } 
    catch (const out_of_range& e) {
        // Catches the bounds-check error and prints a descriptive message
        cerr << "Access Error: " << e.what() << endl;
    }

    return 0;
}
