#include <stdio.h>
#include <limits.h>

void findLargest(int arr[], int n, int index,
                 int *largest, int *second, int *count)
{
    if (index == n)
        return;                      

    int x = arr[index];

    if (*count == 0)
    {
        *largest = x;
        *count = 1;
    }
    else if (x > *largest)
    {
        *second = *largest;
        *largest = x;
        *count = 2;
    }
    else if (x < *largest &&
             (*count < 2 || x > *second))
    {
        *second = x;
        *count = 2;
    }

    findLargest(arr, n, index + 1, largest, second, count);
}

int main()
{
    int arr[100], n;
    int largest = 0, second = 0, count = 0;

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

    findLargest(arr, n, 0, &largest, &second, &count);

    if (count < 2)
        printf("Second-largest distinct element does not exist.\n");
    else
        printf("Second-largest distinct element = %d\n", second);

    return 0;
}
