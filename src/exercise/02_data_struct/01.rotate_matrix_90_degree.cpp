//
// Created by pliu on 11/23/24.
//

// The exercise is to write a function which takes two integers m and n as inputs, builds an m*n matrix, and then
// rotates the matrix 90 degrees clockwise.

#include <iostream>
using namespace std;

// Function to rotate the matrix 90 degrees clockwise
// 这个函数将矩阵顺时针旋转90度
void rotateMatrixNinetyDegree(int matrix[10][10], int m, int n, int rotated[10][10]) {
    // Fill the rotated matrix
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // the most important logic of the exercise is here
            rotated[j][m - 1 - i] = matrix[i][j];
        }
    }
}

int main() {
    int m, n;
    int matrix[10][10], rotatedMatrix[10][10];

    // Input number of rows and columns
    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;

    // Ensure the dimensions are within bounds
    if (m > 10 || n > 10) {
        cout << "Error: Matrix dimensions exceed 10x10 limit." << endl;
        return 1;
    }

    // Input the matrix
    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Rotate the matrix
    rotateMatrixNinetyDegree(matrix, m, n, rotatedMatrix);

    // Output the rotated matrix
    cout << "Rotated matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << rotatedMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}