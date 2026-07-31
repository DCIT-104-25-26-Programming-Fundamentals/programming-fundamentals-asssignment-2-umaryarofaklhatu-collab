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

const int MAX_SIZE = 10;

// Function prototypes
void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(int mat[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int matA[MAX_SIZE][MAX_SIZE], int matB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int matA[MAX_SIZE][MAX_SIZE], int matB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int m, int n, int p);

int main() {
    // ---------------- PART A - Transpose ----------------
    int matA[MAX_SIZE][MAX_SIZE], transposed[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA;

    cout << "--- PART A: Transpose a Matrix ---" << endl;
    cout << "Enter number of rows: ";
    cin >> rowsA;
    cout << "Enter number of columns: ";
    cin >> colsA;

    if (rowsA <= 0 || colsA <= 0 || rowsA > MAX_SIZE || colsA > MAX_SIZE) {
        cout << "Error: Invalid dimensions." << endl;
        return 1;
    }

    readMatrix(matA, rowsA, colsA);
    transposeMatrix(matA, transposed, rowsA, colsA);

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matA, rowsA, colsA);
    cout << "\nTransposed Matrix:" << endl;
    printMatrix(transposed, colsA, rowsA);

    // ---------------- PART B - Addition ----------------
    int addA[MAX_SIZE][MAX_SIZE], addB[MAX_SIZE][MAX_SIZE], sumResult[MAX_SIZE][MAX_SIZE];
    int rowsB, colsB;

    cout << "\n--- PART B: Add Two Matrices ---" << endl;
    cout << "Enter number of rows: ";
    cin >> rowsB;
    cout << "Enter number of columns: ";
    cin >> colsB;

    if (rowsB <= 0 || colsB <= 0 || rowsB > MAX_SIZE || colsB > MAX_SIZE) {
        cout << "Error: Invalid dimensions." << endl;
        return 1;
    }

    cout << "\nEnter Matrix A:" << endl;
    readMatrix(addA, rowsB, colsB);
    cout << "\nEnter Matrix B:" << endl;
    readMatrix(addB, rowsB, colsB);

    addMatrices(addA, addB, sumResult, rowsB, colsB);

    cout << "\nSum Matrix:" << endl;
    printMatrix(sumResult, rowsB, colsB);

    // ---------------- PART C - Multiplication ----------------
    int mulA[MAX_SIZE][MAX_SIZE], mulB[MAX_SIZE][MAX_SIZE], productResult[MAX_SIZE][MAX_SIZE];
    int m, n, n2, p;

    cout << "\n--- PART C: Multiply Two Matrices ---" << endl;
    cout << "Enter rows of Matrix A (M): ";
    cin >> m;
    cout << "Enter columns of Matrix A (N): ";
    cin >> n;

    if (m <= 0 || n <= 0 || m > MAX_SIZE || n > MAX_SIZE) {
        cout << "Error: Invalid dimensions." << endl;
        return 1;
    }

    cout << "\nEnter Matrix A:" << endl;
    readMatrix(mulA, m, n);

    cout << "\nEnter rows of Matrix B (must equal N = " << n << "): ";
    cin >> n2;
    cout << "Enter columns of Matrix B (P): ";
    cin >> p;

    if (n2 != n) {
        cout << "Error: Number of columns in A must equal number of rows in B." << endl;
        return 1;
    }
    if (p <= 0 || p > MAX_SIZE) {
        cout << "Error: Invalid dimensions." << endl;
        return 1;
    }

    cout << "\nEnter Matrix B:" << endl;
    readMatrix(mulB, n, p);

    multiplyMatrices(mulA, mulB, productResult, m, n, p);

    cout << "\nProduct Matrix (A x B):" << endl;
    printMatrix(productResult, m, p);

    return 0;
}

void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

void printMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int mat[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

void addMatrices(int matA[MAX_SIZE][MAX_SIZE], int matB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

void multiplyMatrices(int matA[MAX_SIZE][MAX_SIZE], int matB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}


