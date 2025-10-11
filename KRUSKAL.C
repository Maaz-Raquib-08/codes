#include <stdio.h>
// #include <conio.h>

#define MAX 30

// Structure to represent an edge
struct Edge {
    int u, v, w;  // u = source vertex, v = destination vertex, w = weight
};

// Function to sort edges in ascending order by weight
void sortEdges(struct Edge e[], int n) {
    int i, j;
    struct Edge temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (e[j].w > e[j + 1].w) {
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }
}

// Function to find parent (for detecting cycle)
int findParent(int parent[], int v) {
    if (parent[v] == v)
        return v;
    return findParent(parent, parent[v]);
}

// Function to apply union operation (combine two sets)
void unionSet(int parent[], int a, int b) {
    parent[a] = b;
}

// Main Kruskal's Algorithm
void main() {
    int i, j, n, m, cost = 0;
    int parent[MAX];

    struct Edge e[MAX];     // to store all edges
    struct Edge result[MAX]; // to store MST edges

    // clrscr();

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Input edges
    printf("\nEnter edges (u v weight):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
    }

    // Step 1: Sort all edges by ascending weight
    sortEdges(e, m);

    // Step 2: Initialize parent of each vertex as itself
    for (i = 0; i < n; i++)
        parent[i] = i;

    // Step 3: Pick smallest edges one by one
    j = 0;
    for (i = 0; i < m && j < n - 1; i++) {
        int a = findParent(parent, e[i].u);
        int b = findParent(parent, e[i].v);

        // If including this edge doesn't form a cycle
        if (a != b) {
            result[j++] = e[i];
            cost += e[i].w;
            unionSet(parent, a, b);
        }
    }

    // Step 4: Print MST result
    printf("\nEdges in Minimum Spanning Tree:\n");
    for (i = 0; i < j; i++)
        printf("%d -- %d == %d\n", result[i].u, result[i].v, result[i].w);

    printf("\nMinimum Cost = %d", cost);

    // getch();
}
