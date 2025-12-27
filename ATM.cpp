#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isDigits(const string &s) {
    if (s.empty()) return false;
    for (char c : s) if (!isdigit((unsigned char)c)) return false;
    return true;
}

int main() {
    string correctPin, confirmPin, attemptPin;
    const int maxAttempts = 3;

    // Set the correct PIN once (with confirmation)
    while (true) {
        cout << "Set your new 4-digit PIN: ";
        cin >> correctPin;

        if (!isDigits(correctPin) || correctPin.length() != 4) {
            cout << "Invalid PIN. PIN must be exactly 4 digits.\n";
            continue;
        }

        cout << "Confirm your new PIN: ";
        cin >> confirmPin;

        if (correctPin != confirmPin) {
            cout << "PINs do not match. Please try again.\n\n";
            continue;
        }
        break;
    }

    // Allow up to maxAttempts to enter the PIN
    int attempts = 0;
    while (attempts < maxAttempts) {
        cout << "Enter your PIN: ";
        cin >> attemptPin;

        if (attemptPin == correctPin) {
            cout << "Access granted. Process continue..." << endl;
            return 0;
        } else {
            attempts++;
            int left = maxAttempts - attempts;
            if (left > 0)
                cout << "Incorrect PIN. Attempts left: " << left << endl;
        }
    }

    cout << "Too many wrong attempts. Your account is blocked!" << endl;
    return 0;
}
