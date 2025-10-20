#include <stdio.h>

void merge(int arr[], int l, int m, int h)
{
    int i = l, j = m + 1, k = 0;
    int res[10];
    while (i <= m && j <= h)
    {
        if (arr[i] < arr[j])
            res[k++] = arr[i++];
        else
            res[k++] = arr[j++];
    }
    while (i <= m)
        res[k++] = arr[i++];
    while (j <= h)
        res[k++] = arr[j++];
    for (i = l, k = 0; i <= h; i++, k++)
        arr[i] = res[k];
}

void mergesort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[7], l = 0, h, i;
    printf("Enter 7 elements:
");
    for (i = 0; i < 7; ++i)
        scanf("%d", &arr[i]);
    h = 7 - 1;
    mergesort(arr, l, h);
    printf("
Sorted array:
");
    for (i = 0; i < 7; ++i)
        printf("%d ", arr[i]);
    return 0;
}
