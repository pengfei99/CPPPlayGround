//
// Created by pliu on 11/23/24.
//

// The exercise is to write a function which takes two integers m and n as inputs, builds an m*n matrix, and then
// rotates the matrix 90 degrees clockwise.

#include <iostream>
using namespace std;


void bool_data_type1() {
    // A boolean type variable in C++ is of type bool. It can hold one of two values: true or false.
    bool isEven = false; // Correct declaration and initialization

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
void char_data_type1() {
    /*
     * The character (char) data type in C++ stands for alphanumeric values, which can be a wide range of characters.
     * These may include alphabets like 'a', 'b', and 'c', numeric values like '1', '2', and '3', symbols like
     * '#', '$', and '&', and many more.
     */
    char ch,ch1,ch2;
    ch='a';     //this is an alphabet
    ch1='&';    //this is a symbol
    ch2='123';   //this is a number
    cout<<ch<<endl<<ch1<<endl<<ch2<<endl;
}

void char_data_type2() {
    char c = '$';
    int asciiCode = 97;
    cout << "The Corresponding ASCII value of '$' : ";
    cout << int(c) << endl;

    cout << "The Corresponding  character value of asciiCode 97 : ";
    cout << char(asciiCode) << endl;
}

void str_data_type1() {
    // Declare and initialize a string
    string inputStr = "Hello, world!";

    // Find a substring starting from a specific position
    int startIndex = 0;       // Starting index of substring
    int length = 5;           // Length of the substring
    string subString = inputStr.substr(startIndex, length);

    // Output the results
    cout << "Main string: " << inputStr << endl;
    cout << "Substring: " << subString << endl;
}

void str_data_type2() {
    string txt1 = "Hey, where are you \"vikas\"? ";
    string txt2 = "A: hello, how are you?\nB: I'm fin, and you? \nA: Great. ";

    cout<<txt1<<endl;

    cout<<txt2<<endl;
}

void num_data_type1() {
    int x=1,y=2,z=3;
    int sum = x+y+z;
    int product = x*y*z;

    cout<< "sum of x, y,z: "<< sum<<endl;
    cout<< "product of x, y,z: "<< product <<endl;
}

int main() {
     /*
      * boolean type, In C++, true is internally represented as 1, and false as 0.
      *
      */
    // bool_data_type1();

    bool_data_type2();

    /*
     * Char type
     */
     // char_data_type1();

    // char_data_type2();
     /*
      *string type
      *
      */
    //str_data_type1();
    // str_data_type2();

    /*
     * numeric type
     */
    // num_data_type1();
    return 0;
}