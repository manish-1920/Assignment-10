
#include <stdio.h>

#define MAX 10

int columnSum(int a[MAX][MAX], int rows, int col, int row) {
    if (row == rows)
        return 0;

    return a[row][col] + columnSum(a, rows, col, row + 1);
}

void findMinimumColumn(int a[MAX][MAX], int rows, int cols,
                       int col, int *minCol, int *minSum) {
    if (col == cols)
        return;

    int sum = columnSum(a, rows, col, 0);

    if (col == 0 || sum < *minSum) {
        *minSum = sum;
        *minCol = col;
    }

    findMinimumColumn(a, rows, cols, col + 1, minCol, minSum);
}

int main() {
    int a[MAX][MAX], rows, cols;
    int minCol = 0, minSum = 0;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    if (rows < 1 || rows > MAX || cols < 1 || cols > MAX) {
        printf("Invalid matrix dimensions.\n");
        return 0;
    }

    printf("Enter matrix elements:\n");

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &a[i][j]);

    findMinimumColumn(a, rows, cols, 0, &minCol, &minSum);

    printf("Column with minimum sum = %d\n", minCol + 1);
    printf("Minimum column sum = %d\n", minSum);

    return 0;
}
