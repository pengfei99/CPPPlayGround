#include <iostream>
#include <sstream> // For stringstream
#include <cctype>  // For isdigit()
using namespace std;

int main() {
    string input;
    int numbers[80]; // Array to store numbers (max size 80)
    int size = 0;     // Variable to count the size of the array

    // Input the string
    cout << "Enter the string containing numbers and spaces: ";
    getline(cin, input);

    // Check if the input string exceeds 80 bytes
    if (input.size() >= 80) {
        cout << "Error: Input string exceeds 80 bytes!" << endl;
        return 1; // Exit the program with an error code
    }

    // Use stringstream to parse tokens
    stringstream ss(input);
    string token;

    while (ss >> token) {
        // Check if the token is a valid number
        bool isNumber = true;
        for (char c : token) {
            if (!isdigit(c) && c != '-') { // Allow digits and optional negative sign
                isNumber = false;
                break;
            }
        }

        if (isNumber) {
            numbers[size++] = stoi(token); // Convert valid number to integer and store
        }
    }


    cout << "Size of the array: " << size << endl;
    // Output the numbers and the size of the array
    cout << "Extracted numbers: ";
    for (int i = 0; i < size; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
