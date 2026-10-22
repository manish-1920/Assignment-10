
#include <stdio.h>

int isSymmetric(int a[10][10], int n, int row, int col) {
    if (row == n)
        return 1;

    if (a[row][col] != a[col][row])
        return 0;

    if (col + 1 < n)
        return isSymmetric(a, n, row, col + 1);

    return isSymmetric(a, n, row + 1, 0);
}

int main() {
    int a[10][10], n;

    printf("Enter matrix size: ");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("Invalid matrix size.\n");
        return 0;
    }

    printf("Enter matrix elements:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    if (isSymmetric(a, n, 0, 0))
        printf("The matrix is symmetric.\n");
    else
        printf("The matrix is not symmetric.\n");

    return 0;
}
