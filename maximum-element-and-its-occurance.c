
#include <stdio.h>

int findMaximum(int a[], int n, int i) {
    if (i == n - 1)
        return a[i];

    int maxRest = findMaximum(a, n, i + 1);

    if (a[i] > maxRest)
        return a[i];

    return maxRest;
}

int countOccurrences(int a[], int n, int i, int maximum) {
    if (i == n)
        return 0;

    return (a[i] == maximum) +
           countOccurrences(a, n, i + 1, maximum);
}

int main() {
    int a[100], n;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Invalid array size.\n");
        return 0;
    }

    printf("Enter array elements: ");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int maximum = findMaximum(a, n, 0);
    int count = countOccurrences(a, n, 0, maximum);

    printf("Maximum element = %d\n", maximum);
    printf("Number of occurrences = %d\n", count);

    return 0;
}
