#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key)
{
    if (low > high)
        return -1;                    // Base condition

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid;

    if (key < arr[mid])
        return binarySearch(arr, low, mid - 1, key);

    return binarySearch(arr, mid + 1, high, key);
}

int main()
{
    int arr[100], n, key, result;

    printf("Enter sorted array size (1-100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Invalid array size.\n");
        return 0;
    }

    printf("Enter elements in ascending order: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, 0, n - 1, key);

    if (result == -1)
        printf("Element not found.\n");
    else
        printf("Element found at index %d (position %d).\n",
               result, result + 1);

    return 0;
}