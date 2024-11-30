#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Function to sort digits in descending order
string sortDescending(string num) {
    sort(num.rbegin(), num.rend());
    return num;
}

// Function to sort digits in ascending order
string sortAscending(string num) {
    sort(num.begin(), num.end());
    return num;
}

// Function to perform the Kaprekar routine
void kaprekarRoutine(int num) {
    if (num < 1000 || num > 9999) {
        cout << "Please enter a four-digit number with at least two different digits!" << endl;
        return;
    }

    int steps = 0;

    cout << "Starting Kaprekar routine for number: " << num << endl;

    while (num != 6174) {
        // Convert the number to a string
        string numStr = to_string(num);
        
        // Add leading zeros if needed
        while (numStr.length() < 4) {
            numStr = "0" + numStr;
        }

        // Sort digits in ascending and descending order
        string desc = sortDescending(numStr);
        string asc = sortAscending(numStr);

        // Convert the sorted strings back to integers
        int numDesc = stoi(desc);
        int numAsc = stoi(asc);

        // Subtract the smaller number from the larger
        num = numDesc - numAsc;
        steps++;

        // Output the step details
        cout << "Step " << steps << ": Descending = " << desc 
             << ", Ascending = " << asc 
             << ", Difference = " << num << endl;
    }

    cout << "Kaprekar constant (6174) reached in " << steps << " steps." << endl;
}

int main() {
    int number;

    cout << "Enter a four-digit number: ";
    cin >> number;

    kaprekarRoutine(number);

    return 0;
}
