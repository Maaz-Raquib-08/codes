#include <stdio.h>
#include <conio.h>

void prims(int n, int cost[10][10])

{
    int i, j, u, v, min, minCost = 0, visited[10] = {0};
    visited[0] = 1;
    for (i = 0; i < n; ++i)
    {
        min = 999;
        for (j = 0; j < n; ++j)
        {
            if (cost[i][j] < min)
            {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
        if (visited[v] == 0)
        {
            minCost = minCost + min;
            visited[v] = 1;
        }
        cost[u][v] = cost[v][u] = 999;
    }
    printf("\nMin cost = %d", minCost);
}

int main()
{
    int i, j, n = 3, cost[10][10] = { {0, 5, 10},
                                       {5, 0, 5},
                                       {10, 5, 0} };

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (cost[i][j] == 0) cost[i][j] = 999;
        }
    }
    prims(n, cost);
    getch();
    return 0;
}

