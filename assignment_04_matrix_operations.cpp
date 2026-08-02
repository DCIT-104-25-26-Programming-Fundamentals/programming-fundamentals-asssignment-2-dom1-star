// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void readMatrix(int matrix[10][10], int& rows, int& cols) {
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[10][10], int rows, int cols) {
    int transposed[10][10];
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    
    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(transposed, cols, rows);
}

void addMatrices(int matrixA[10][10], int matrixB[10][10], int rows, int cols) {
    int result[10][10];
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    
    cout << "\nMatrix Sum:" << endl;
    displayMatrix(result, rows, cols);
}

void multiplyMatrices(int matrixA[10][10], int matrixB[10][10], int rowsA, int colsA, int rowsB, int colsB) {
    if (colsA != rowsB) {
        cout << "Error: Number of columns in A must equal number of rows in B." << endl;
        return;
    }
    
    int result[10][10];
    
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    
    cout << "\nMatrix Product (A x B):" << endl;
    displayMatrix(result, rowsA, colsB);
}

int main() {
    int matrixA[10][10], matrixB[10][10];
    int rowsA, colsA, rowsB, colsB;
    int choice;
    
    do {
        cout << "\n========================================" << endl;
        cout << "       MATRIX OPERATIONS MENU" << endl;
        cout << "========================================" << endl;
        cout << "1. Transpose a Matrix" << endl;
        cout << "2. Add Two Matrices" << endl;
        cout << "3. Multiply Two Matrices" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "\n--- TRANSPOSE MATRIX ---" << endl;
                readMatrix(matrixA, rowsA, colsA);
                transposeMatrix(matrixA, rowsA, colsA);
                break;
            
            case 2:
                cout << "\n--- ADD TWO MATRICES ---" << endl;
                cout << "\nEnter Matrix A:" << endl;
                readMatrix(matrixA, rowsA, colsA);
                cout << "\nEnter Matrix B (same dimensions):" << endl;
                readMatrix(matrixB, rowsB, colsB);
                
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(matrixA, matrixB, rowsA, colsA);
                } else {
                    cout << "Error: Matrices must have the same dimensions." << endl;
                }
                break;
            
            case 3:
                cout << "\n--- MULTIPLY TWO MATRICES ---" << endl;
                cout << "\nEnter Matrix A:" << endl;
                readMatrix(matrixA, rowsA, colsA);
                cout << "\nEnter Matrix B:" << endl;
                readMatrix(matrixB, rowsB, colsB);
                multiplyMatrices(matrixA, matrixB, rowsA, colsA, rowsB, colsB);
                break;
            
            case 4:
                cout << "Goodbye!" << endl;
                break;
            
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
    
    return 0;
}