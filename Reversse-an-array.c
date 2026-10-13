#include <stdio.h>

void reverseArray(int arr[], int left, int right)
{
    if (left >= right)
        return;                   
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;

    reverseArray(arr, left + 1, right - 1);
}

int main()
{
    int arr[100], n;

    printf("Enter array size (1-100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Invalid array size.\n");
        return 0;
    }

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    reverseArray(arr, 0, n - 1);

    printf("Reversed array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}