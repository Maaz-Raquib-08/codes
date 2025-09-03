#include <stdio.h>
#include <conio.h>

void dijkstras(int, int[10][10], int, int[10]);

void main()
{
    int i, j, dist[10];
    int cost[10][10] = {
        {0, 10, 3, 20},
        {0, 0, 0, 5},
        {0, 2, 0, 3},
        {0, 0, 0, 0}
    };
    int n = 4, s = 0;

    // Print & replace 0 with 999 (infinity)
    for (i = 0; i < n; ++i) {
        printf("\n");
        for (j = 0; j < n; ++j) {
            printf("%d ", cost[i][j]);
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = 999;
        }
    }

    clrscr();

    dijkstras(n, cost, s, dist);

    printf("\nShortest Path from %d is \n", s);
    for (i = 0; i < n; ++i) {
        if (s != i)
            printf("\n%d -> %d = %d ", s, i, dist[i]);
    }

    getch();
}

void dijkstras(int n, int cost[10][10], int s, int dist[10]) {
    int i, v, count = 1, min, visited[10];

    // initialize
    for (i = 0; i < n; ++i) {
        visited[i] = 0;
        dist[i] = cost[s][i];
    }
    visited[s] = 1;
    dist[s] = 0;

    while (count < n) {
        min = 999;
        for (i = 0; i < n; ++i) {
            if (dist[i] < min && visited[i] == 0) {
                min = dist[i];
                v = i;
            }
        }
        visited[v] = 1;

        for (i = 0; i < n; ++i) {
            if (dist[i] > dist[v] + cost[v][i]) {
                dist[i] = dist[v] + cost[v][i];
            }
        }
        count++;
    }
}
