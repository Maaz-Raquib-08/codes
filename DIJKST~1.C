#include <stdio.h>
// #include <conio.h>

void dijkstra(int n, int cost[10][10], int s, int dist[10]) {
    int i, v, count = 1, min;
    int visited[10];

    // Initialize distance and visited arrays
    for (i = 0; i < n; i++) {
        visited[i] = 0;
        dist[i] = cost[s][i];
    }

    visited[s] = 1;
    dist[s] = 0;

    // Repeat for all vertices
    while (count < n) {
        min = 999;
        for (i = 0; i < n; i++) {
            if (dist[i] < min && visited[i] == 0) {
                min = dist[i];
                v = i;
            }
        }

        visited[v] = 1;

        for (i = 0; i < n; i++) {
            if (dist[i] > dist[v] + cost[v][i])
                dist[i] = dist[v] + cost[v][i];
        }

        count++;
    }
}

void main() {
    int i, j, n = 4, s = 0;
    int dist[10];

    int cost[10][10] = {
        {0, 10, 3, 20},
        {0, 0, 0, 5},
        {0, 2, 0, 3},
        {0, 0, 0, 0}
    };

    // Replace 0 (no edge) with 999 (infinity)
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = 999;
        }
    }

    // clrscr();

    dijkstra(n, cost, s, dist);

    printf("Shortest Path from Source %d:\n", s);
    for (i = 0; i < n; i++) {
        if (i != s)
            printf("%d -> %d = %d\n", s, i, dist[i]);
    }

    // getch();
}
