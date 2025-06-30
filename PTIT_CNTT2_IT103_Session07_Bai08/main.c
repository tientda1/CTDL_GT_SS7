#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

void swapRows(int matrix[][MAX_COLS], int row1, int row2, int cols) {
    for (int i = 0; i < cols; i++) {
        int temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}

void sortColumn(int matrix[][MAX_COLS], int rows, int cols, int k) {
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < rows - i - 1; j++) {
            if (matrix[j][k] > matrix[j + 1][k]) {
                swapRows(matrix, j, j + 1, cols);
            }
        }
    }
}

void printMatrix(int matrix[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int rows, cols, k;

    // 1. Nhập vào số hàng và số cột, có kiểm tra điều kiện
    do {
        printf("Nhap vao so hang (0 < rows < %d): ", MAX_ROWS);
        scanf("%d", &rows);
    } while (rows <= 0 || rows >= MAX_ROWS);

    do {
        printf("Nhap vao so cot (0 < cols < %d): ", MAX_COLS);
        scanf("%d", &cols);
    } while (cols <= 0 || cols >= MAX_COLS);

    printf("\nNhap vao cac phan tu cua ma tran %dx%d:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Phan tu a[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    do {
        printf("\nNhap vao chi so cot can sap xep (tu 0 den %d): ", cols - 1);
        scanf("%d", &k);
        if (k < 0 || k >= cols) {
            printf("Chi so cot khong hop le. Vui long nhap lai.\n");
        }
    } while (k < 0 || k >= cols);

    sortColumn(matrix, rows, cols, k);

    printf("\nMa tran sau khi sap xep cot %d tang dan:\n", k);
    printMatrix(matrix, rows, cols);

    return 0;
}