

#include <stdio.h>

int w[10], n, m, S, x[10];
void sumofsub(int s, int k, int r)
{
    int i;
    x[k] = 1;
    if (s + w[k] == m)
    {
        printf("\nSubset = ");
        for (i = 0; i <= k; i++)
            if (x[i] == 1)
                printf("%d\t", w[i]);
    }
    else if (s + w[k] + w[k + 1] <= m)
        sumofsub(s + w[k], k + 1, r - w[k]);
    if ((s + r - w[k] >= m) && (s + w[k + 1] <= m))
    {
        x[k] = 0;
        sumofsub(s, k + 1, r - w[k]);
    }
}

void main()
{
    int i, sum = 0;
    printf("\nEnter no of elements: ");
    scanf("%d", &n);
    printf("\nEnter the elements in ascending order: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
        sum += w[i];
    }
    printf("\nEnter the sum value: ");
    scanf("%d", &m);
    printf("\nSubset combinations are:");
    sumofsub(0, 0, sum);
}
