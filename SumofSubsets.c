#include <stdio.h>

int n, target, found = 0;
int w[10], x[10];

void subsetSum(int idx, int sum) {
    // Base condition
    if (sum == target) {
        printf("\nSubset found: ");
        for (int i = 0; i < idx; i++)
            if (x[i]) printf("%d ", w[i]);
        found = 1;
        return;
    }

    // If we reach end or sum exceeds target → stop
    if (idx == n || sum > target)
        return;

    // Include current element
    x[idx] = 1;
    subsetSum(idx + 1, sum + w[idx]);

    // Exclude current element
    x[idx] = 0;
    subsetSum(idx + 1, sum);
}

int main() {
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("\nSubsets with sum = %d:\n", target);
    subsetSum(0, 0);

    if (!found)
        printf("\nNo subset found.\n");

    return 0;
}


// #include <stdio.h>

// int w[10], x[10] = {0}, flag = 0;
// int n, m;

// // Recursive function to find subsets
// void sumofsub(int s, int k, int r)
// {
//     int i;

//     // Include current element
//     x[k] = 1;

//     // Check if including this element gives the exact sum
//     if (s + w[k] == m)
//     {
//         printf("\nSubset found: ");
//         for (i = 0; i <= k; i++)
//             if (x[i] == 1)
//                 printf("%d ", w[i]);
//         flag = 1;
//     }

//     if (k + 1 < n && s + w[k] + w[k + 1] <= m)
//         sumofsub(s + w[k], k + 1, r - w[k]);

//     // Explore the case where we exclude the current element
//     if (k + 1 < n && (s + r - w[k] >= m) && (s + w[k + 1] <= m))
//     {
//         x[k] = 0;
//         sumofsub(s, k + 1, r - w[k]);
//     }

//     // Backtrack
//     x[k] = 0;
// }

// int main()
// {
//     int i, s = 0, r = 0;

//     printf("Enter number of elements in the set: ");
//     scanf("%d", &n);

//     printf("\nEnter elements:\n");
//     for (i = 0; i < n; i++)
//     {
//         printf("Element %d: ", i + 1);
//         scanf("%d", &w[i]);
//         r += w[i];
//     }

//     printf("\nEnter the target sum (m): ");
//     scanf("%d", &m);

//     printf("\nAll possible subsets with sum = %d are:\n", m);

//     sumofsub(s, 0, r);

//     if (flag == 0)
//         printf("\nNo combination exists.\n");

//     return 0;
// }
