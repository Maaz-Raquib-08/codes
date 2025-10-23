#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;
    while (i < j)
    {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int loc = partition(arr, low, high);
        quicksort(arr, low, loc - 1);
        quicksort(arr, loc + 1, high);
    }
}

int main()
{
    int arr[7] = {2, 8, 89, 34, 87, 1, 39};
    quicksort(arr, 0, 6);
    printf("Sorted numbers:");
    for (int i = 0; i < 7; ++i)
        printf("%d ", arr[i]);
    return 0;
}
