
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define ROW_1 4
#define COL_1 4

#define ROW_2 4
#define COL_2 4

void print(char* display, int matrix[ROW_1][COL_1], int start_row, int start_column, int end_row, int end_column) {
    printf("\n%s =>\n", display);
    for (int i = start_row; i <= end_row; i++) {
        for (int j = start_column; j <= end_column; j++) {
            printf("%10d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void add_matrix(int matrix_A[ROW_1][COL_1], int matrix_B[ROW_1][COL_1], int matrix_C[ROW_1][COL_1], int split_index) {
    for (int i = 0; i < split_index; i++) {
        for (int j = 0; j < split_index; j++) {
            matrix_C[i][j] = matrix_A[i][j] + matrix_B[i][j];
        }
    }
}

void multiply_matrix(int matrix_A[ROW_1][COL_1], int matrix_B[ROW_2][COL_2], int result_matrix[ROW_1][COL_2]) {
    int col_1 = COL_1;
    int row_1 = ROW_1;
    int col_2 = COL_2;
    int row_2 = ROW_2;

    if (col_1 != row_2) {
        printf("\nError: The number of columns in Matrix A must be equal to the number of rows in Matrix B\n");
        return;
    }

    for (int i = 0; i < row_1; i++) {
        for (int j = 0; j < col_2; j++) {
            int sum = 0;
            for (int k = 0; k < col_1; k++) {
                sum += matrix_A[i][k] * matrix_B[k][j];
            }
            result_matrix[i][j] = sum;
        }
    }
}



int main() {
    int matrix_A[ROW_1][COL_1] = {{1, 1, 1, 1},
                                  {2, 2, 2, 2},
                                  {3, 3, 3, 3},
                                  {2, 2, 2, 2}};

    print("Array A", matrix_A, 0, 0, ROW_1 - 1, COL_1 - 1);

    int matrix_B[ROW_2][COL_2] = {{1, 1, 1, 1},
                                  {2, 2, 2, 2},
                                  {3, 3, 3, 3},
                                  {2, 2, 2, 2}};

    print("Array B", matrix_B, 0, 0, ROW_2 - 1, COL_2 - 1);

    int result_matrix[ROW_1][COL_2];
    multiply_matrix(matrix_A, matrix_B, result_matrix);

    print("Result Array", result_matrix, 0, 0, ROW_1 - 1, COL_2 - 1);

    return 0;
}

