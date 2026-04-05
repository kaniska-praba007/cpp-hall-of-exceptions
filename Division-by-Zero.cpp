/*Division by zero is undefined (since it fails inverse multiplication property)*/

#include <iostream>
using namespace std;

int main()
{
    int numerator = 10, denominator = 0;
    try
    {
        if (denominator == 0)
            throw "Division by zero error!";
        cout << numerator / denominator << endl;
    }
    catch (const char *msg)
    {
        // We catch a string literal to inform the user why the math failed.
        cerr << "Error: " << msg << endl;
    }
    return 0;
}

/* Sample Output:
Error: Division by zero error!
*/
