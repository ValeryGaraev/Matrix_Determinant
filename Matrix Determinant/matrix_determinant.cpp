//
//  matrix_determinant.cpp
//  Matrix Determinant
//
//  Created by Valery Garaev on 02.06.2020.
//  Copyright © 2020 Valery Garaev. All rights reserved.
//

#include<iostream>
#include<math.h>

using namespace std;

int determinant(int matrix[10][10], int n);

int main() {
    int n, i, j;
    int matrix[10][10];
    cout << "\nEnter the size of the matrix: ";
    cin >> n; cout << endl;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << "Enter the " << i << "x" << j << " element of the matrix: ";
            cin >> matrix[i][j];
        }
    }
    
    cout << "\nThe entered matrix is:\n";
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nDeterminant of the matrix is " << determinant(matrix, n) << endl << endl;
    
    return 0;
}

int determinant(int matrix[10][10], int n) {
    int _determinant = 0;
    int submatrix[10][10];
    
    if (n == 1) {
        return matrix[0][0];
    } else if (n == 2) {
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    } else {
        for (int x = 0; x < n; x++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
                int subj = 0;
                for (int j = 0; j < n; j++) {
                    if (j == x)
                        continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            int _pow = pow(-1, x);
            
            _determinant = _determinant + (_pow * matrix[0][x] * determinant(submatrix, n - 1));
        }
    }
    return _determinant;
}
