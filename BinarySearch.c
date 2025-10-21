#include <stdio.h>

int bsh(int arr[], int l, int h, int n) // n = key
{
    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (arr[mid] == n)
            return 1; // found

        if (arr[mid] < n)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return -1; // not found
}

int main()
{
    int a[8], l, h, key, res, i;

    printf("Enter 8 sorted elements:\n");
    for (i = 0; i < 8; ++i)
        scanf("%d", &a[i]);

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    l = 0;
    h = 7;

    res = bsh(a, l, h, key);

    if (res == 1)
        printf("Element found\n");
    else
        printf("Element not found\n");

    return 0;
}



// #include <stdio.h>
// using recursion
// int bsh(int arr[], int l, int h, int n) // n = key
// {
//     int mid = (l + h) / 2;
//     if (l > h)
//         return -1;
//     else
//     {
//         if (arr[mid] > n)
//             h = mid - 1;
//         else if (arr[mid] < n)
//             l = mid + 1;
//         else
//             return 1;
//     }
//     return bsh(arr, l, h, n);
// }

// int main()
// {
//     int a[8], l, h, key, res, i;
//     printf("Enter 8 sorted Elements:
// ");
//     for (i = 0; i < 8; ++i)
//         scanf("%d", &a[i]);
//     printf("
// Enter element to search:");
//     scanf("%d", &key);
//     l = 0;
//     h = 7;

//     res = bsh(a, l, h, key);
//     if (res == 1)
//         printf("Element found");
//     else
//         printf("Element not found");

//     return 0;
// }
