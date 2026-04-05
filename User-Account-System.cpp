/**
 * --- EXCEPTION FLOW DIAGRAM ---
 * * [ START ] 
 * |
 * v
 * +---------------------------------------+
 * | while (!signUpComplete)               | <-----------+
 * | {                                     |             |
 * |    try {                              |             |
 * |       1. Get Username                 |             |
 * |          IF "admin" -> THROW ---------|-----+       |
 * |                                       |     |       |
 * |       2. Get Password                 |     |       |
 * |          validatePassword()           |     |       |
 * |          IF too short -> THROW -------|-----+       |
 * |                                       |     |       |
 * |       3. Check Database               |     |       |
 * |          IF exists -> THROW ----------|-----+       |
 * |                                       |     |       |
 * |       4. SUCCESS!                     |     |       |
 * |          signUpComplete = true;       |     |       |
 * |    }                                  |     |       |
 * |                                       |     |       |
 * |    catch (ValidationError) <----------|-----+       |
 * |    catch (invalid_argument) <---------|-----+       | (The "Jump")
 * |    catch (exception) <----------------|-----+       |
 * |    catch (...) <----------------------|-----+       |
 * |                                       |             |
 * |    5. cin.clear() / ignore()          |             |
 * | }                                     | ------------+ (Loop Back)
 * +---------------------------------------+
 * |
 * v
 * [ ACCESS GRANTED ]
 */


#include <iostream>
#include <string>
#include <stdexcept>
#include <limits> // For clearing the input buffer

using namespace std;

// We define a custom exception for specific business logic errors
class ValidationError : public runtime_error {
public:
    ValidationError(const string& msg) : runtime_error(msg) {}
};

void validatePassword(string pass) {
    if (pass.length() < 6) {
        throw ValidationError("Password too short! Must be at least 6 characters.");
    }
    
    bool hasDigit = false;
    for (size_t i = 0; i < pass.length(); i++) {
        if (isdigit(pass[i])) hasDigit = true;
    }
    
    if (!hasDigit) {
        throw ValidationError("Password must contain at least one number.");
    }
}

int main() {
    string username;
    string password;
    bool signUpComplete = false;

    cout << "--- SECURE ACCOUNT GATEWAY ---" << endl;

    // This loop ensures the program "runs at all costs" until success
    while (!signUpComplete) {
        try {
            cout << "\nEnter Username: ";
            cin >> username;

            if (username == "admin") {
                throw invalid_argument("Username 'admin' is reserved and forbidden.");
            }

            cout << "Enter Password: ";
            cin >> password;

            // Step 1: Validate Password Logic
            validatePassword(password);

            // Step 2: Simulate a Database "Constraint" Error
            if (username == "guest") {
                throw runtime_error("Database Error: User 'guest' already exists.");
            }

            // If we reach here, no exceptions were thrown
            signUpComplete = true;
            cout << "\nSUCCESS: Account created for " << username << "!" << endl;
        }
        catch (const ValidationError& e) {
            // Catches our specific password requirement errors
            cerr << "POLICY ALERT: " << e.what() << " Try again." << endl;
        }
        catch (const invalid_argument& e) {
            // Catches the reserved username error
            cerr << "INPUT ERROR: " << e.what() << endl;
        }
        catch (const exception& e) {
            // Generic safety net for database or system errors
            cerr << "SYSTEM ERROR: " << e.what() << " Please resolve and retry." << endl;
        }
        catch (...) {
            // The ultimate fallback to prevent a crash from unknown types
            cerr << "UNKNOWN CRITICAL ERROR: Restarting registration process..." << endl;
        }

        // Clean up the input stream in case of weird characters/errors
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "Welcome to the system, " << username << ". Access Granted." << endl;
    return 0;
}

/* Sample Output:
--- SECURE ACCOUNT GATEWAY ---

Enter Username: admin
INPUT ERROR: Username 'admin' is reserved and forbidden.

Enter Username: bob
Enter Password: abc
POLICY ALERT: Password too short! Must be at least 6 characters. Try again.

Enter Username: guest
Enter Password: password123
SYSTEM ERROR: Database Error: User 'guest' already exists. Please resolve and retry.

Enter Username: dev_user
Enter Password: securePass1
SUCCESS: Account created for dev_user!
Welcome to the system, dev_user. Access Granted.
*/
