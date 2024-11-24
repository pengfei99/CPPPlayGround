//
// Created by pliu on 11/24/24.
//

#include <iostream>
using namespace std;

void array_init1() {
    // this is an empty array
    int score1[5];

    cout << "score1 value before initialization" << endl;
    for (int i = 0; i < 5; i++) {
        cout << score1[i] << endl;
    }

    // init value of score
    for (int i = 0; i < 5; i++) {
        score1[i] = 0;
    }

    cout << "score1 value after 1st initialization" << endl;
    for (int i = 0; i < 5; i++) {
        cout << score1[i] << endl;
    }

    int score2[5] = {1 ,2,3,4,5 };
    cout << "score2 2nd value: " << score2[1] << endl;

    cout << "score2 value " << endl;
    for (int i = 0; i < 5; i++) {
        cout << score2[i] << endl;
    }

}
void array_init2() {
    char letters[5];
    for (int i = 0; i < 5; i++) {
        letters[i] = 'a';
    }
    for (int i = 0; i < 5; i++) {
        cout << letters[i];
    }
}

void array_function() {
    int size;
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int numbers[5]; // Assume a maximum size of 100
    cout << "Enter " << size << " elements:" << endl;

    // Input elements
    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }

    // Find the sum of elements
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }

    cout << "Sum of array elements: " << sum << endl;

    // Find the maximum element
    int maxElement = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > maxElement) {
            maxElement = numbers[i];
        }
    }
    cout << "Maximum element: " << maxElement << endl;
}
int main() {
  /*
   * An array is a data structure in C++ that stores a **fixed-size sequential collection** of elements of the **same type**.
   *
    * 1. Understand how arrays work and how memory is managed.
    * 2. Learn to use loops to process arrays efficiently.
    * 3. Practice solving simple problems like finding the sum, maximum, or reversing arrays.
    * 4. Be cautious of out-of-bounds errors.
   *
   */

     array_init1();

    // array_init2();

    //array_function();

    return 0;
}
