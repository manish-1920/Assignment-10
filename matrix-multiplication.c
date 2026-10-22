
#include <stdio.h>

#define MAX 10

void multiplyRecursive(int A[MAX][MAX], int B[MAX][MAX],
                       int C[MAX][MAX], int row, int col, int k,
                       int rowsA, int colsA, int colsB) {
    if (row == rowsA)
        return;

    if (col == colsB) {
        multiplyRecursive(A, B, C, row + 1, 0, 0,
                          rowsA, colsA, colsB);
        return;
    }

    if (k < colsA) {
        C[row][col] += A[row][k] * B[k][col];

        multiplyRecursive(A, B, C, row, col, k + 1,
                          rowsA, colsA, colsB);
    } else {
        multiplyRecursive(A, B, C, row, col + 1, 0,
                          rowsA, colsA, colsB);
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX] = {{0}};
    int r1, c1, r2, c2;

    printf("Enter rows and columns of A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of B: ");
    scanf("%d %d", &r2, &c2);

    if (r1 < 1 || r1 > MAX || c1 < 1 || c1 > MAX ||
        r2 < 1 || r2 > MAX || c2 < 1 || c2 > MAX) {
        printf("Invalid matrix dimensions.\n");
        return 0;
    }

    if (c1 != r2) {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    printf("Enter elements of A:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of B:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);

    multiplyRecursive(A, B, C, 0, 0, 0, r1, c1, c2);

    printf("Product matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}
