#include <stdio.h>

// Define macros for matrix dimensions
#define ROWS 2
#define COLUMNS 2

// Function to perform matrix addition
void addMatrices(int a[ROWS][COLUMNS], int b[ROWS][COLUMNS], int sum[ROWS][COLUMNS]) {
    // Loop through each row
    for (int i = 0; i < ROWS; i++) {
        // Loop through each column
        for (int j = 0; j < COLUMNS; j++) {
            // Perform addition
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to perform matrix multiplication
void multiplyMatrices(int a[ROWS][COLUMNS], int b[COLUMNS][ROWS], int product[ROWS][ROWS]) {
    // Loop through each row of the first matrix
    for (int i = 0; i < ROWS; i++) {
        // Loop through each column of the second matrix
        for (int j = 0; j < ROWS; j++) {
            // Initialize the product value
            product[i][j] = 0;

            // Loop through each element along the row/column
            for (int k = 0; k < COLUMNS; k++) {
                // Perform multiplication and accumulate the result
                product[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[ROWS][COLUMNS]) {
    // Loop through each row
    for (int i = 0; i < ROWS; i++) {
        // Loop through each column
        for (int j = 0; j < COLUMNS; j++) {
            // Print the element followed by a space
            printf("%d ", matrix[i][j]);
        }
        // Move to the next line after printing a row
        printf("\n");
    }
}

int main(int argc, char **argv) {
    // Initialize matrices
    int matrix1[ROWS][COLUMNS] = {{1, 2}, {3, 4}};
    int matrix2[ROWS][COLUMNS] = {{5, 6}, {7, 8}};

    // Declare result matrices
    int sum[ROWS][COLUMNS];
    int product[ROWS][ROWS];

    // Perform matrix addition and multiplication
    addMatrices(matrix1, matrix2, sum);
    multiplyMatrices(matrix1, matrix2, product);

    // Display the results
    printf("Matrix Addition:\n");
    printMatrix(sum);

    printf("Matrix Multiplication:\n");
    printMatrix(product);

}
