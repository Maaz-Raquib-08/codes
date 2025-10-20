#include <stdio.h>

int w[10], x[10] = {0}, flag = 0;
int n, m;

// Recursive function to find subsets
void sumofsub(int s, int k, int r)
{
    int i;

    // Include current element
    x[k] = 1;

    // Check if including this element gives the exact sum
    if (s + w[k] == m)
    {
        printf("\nSubset found: ");
        for (i = 0; i <= k; i++)
            if (x[i] == 1)
                printf("%d ", w[i]);
        flag = 1;
    }

    // If including current element doesn't exceed m, then explore further
    else if (s + w[k] + w[k + 1] <= m && k + 1 < n)
        sumofsub(s + w[k], k + 1, r - w[k]);

    // Explore the case where we exclude the current element
    if (s + r - w[k] >= m && k + 1 < n)
    {
        x[k] = 0;
        sumofsub(s, k + 1, r - w[k]);
    }

    // Backtrack
    x[k] = 0;
}

int main()
{
    int i, s = 0, r = 0;

    printf("Enter number of elements in the set: ");
    scanf("%d", &n);

    printf("\nEnter elements:\n");
    for (i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &w[i]);
        r += w[i];
    }

    printf("\nEnter the target sum (m): ");
    scanf("%d", &m);

    printf("\nAll possible subsets with sum = %d are:\n", m);

    sumofsub(s, 0, r);

    if (flag == 0)
        printf("\nNo combination exists.\n");

    return 0;
}
