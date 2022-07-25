#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// Checks if the string typed in by user is a number
bool isNumber (const string& s) {

    int len = s.length();

    for (int i = 0; i < len; i++) {

        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }
    
    return true;

}

int main() {

    string ccNumber; 
    bool validCheck; 

    cout << "Please enter a credit card number to check if it is valid." << endl;
    cout << "If you want to exit, type 'exit' anytime." << endl;

    while (true) {

        cout << "Enter a Credit Card Number: "; cin >> ccNumber; 

        // Exit if user types in exit
        if (ccNumber == "exit") {
            break;
        }

        // Retry if the user enters something other than a number
        else if (!isNumber(ccNumber)){
            cout << "Please put in a number." << endl;
            continue;
        }

        int len = ccNumber.length(); 
        int doubleEvenSum = 0; 

        // 1. Double every other number of the ccNumber
        for (int i = len - 2; i >= 0; i = i - 2) {

            int dbl = ((ccNumber[i] - 48) * 2);

            if (dbl > 9) {
                dbl = (dbl / 10) + (dbl % 10);
            }

            doubleEvenSum += dbl;

        }

        // 2. Add all the digits up and find the sum of the new number
        for (int i = len - 1; i >= 0; i = i - 2) {

            doubleEvenSum += (ccNumber[i] - 48);

        }

        // 3. Check if the sum is a multiple of 10
        cout << (doubleEvenSum % 10 == 0 ? "Valid!": "Invalid!") << endl;

        continue; 
    }

    return 0;
}
