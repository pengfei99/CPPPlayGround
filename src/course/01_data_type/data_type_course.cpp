//
// Created by pliu on 11/23/24.
//

// The exercise is to write a function which takes two integers m and n as inputs, builds an m*n matrix, and then
// rotates the matrix 90 degrees clockwise.

#include <iostream>
using namespace std;


void bool_data_type1() {
    // A boolean type variable in C++ is of type bool. It can hold one of two values: true or false.
    bool isEven = true; // Correct declaration and initialization

    if (isEven) {
        cout << "isEven is true." << endl;
    } else {
        cout << "isEven is false." << endl;
    }
}

void bool_data_type2() {
    bool isEven; // Boolean variable declaration
    int number;

    // Input a number
    cout << "Enter a number: ";
    cin >> number;

    // Check if the number is even
    isEven = (number % 2 == 0); // Assign true if even, false otherwise

    // Output the result
    if (isEven) {
        cout << "The number is even." << endl;
    } else {
        cout << "The number is odd." << endl;
    }
}

int main() {
     // boolean type, In C++, true is internally represented as 1, and false as 0.
    // bool_data_type1();

    // bool_data_type2();

    return 0;
}