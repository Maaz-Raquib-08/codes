#include<stdio.h>
#include<conio.h>

void prims(int, int[10][10]);
void main(){
    int i,j,n=3,cost[10][10]={ {0,5,10},
                               {5,0,5},
                               {10,5,0}
    };
    clrscr();
    for(i=0;i<n;++i){
        for(j=0;j<n;j++){
            if(cost[i][j]==0)
               cost[i][j]=999;
        }
    }
    prims(n,cost);
    getch();
}
void prims(int n, int cost[10][10]){
    int i, j, u, v, min, minCost=0, visited[10]={0}, edgeCount=0;
    visited[0]=1; // Start with vertex 0
    while(edgeCount < n-1){ // Need n-1 edges for MST
        min=999;
        u=-1; v=-1; // Initialize u, v to invalid values
        // Check all edges from visited to unvisited vertices
        for(i=0;i<n;i++){
            if(visited[i]){ // If i is visited
                for(j=0;j<n;j++){
                    if(!visited[j] && cost[i][j]<min){ // If j is unvisited and edge weight is less than min
                        min=cost[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }
        if(u!=-1 && v!=-1){ // If a valid edge is found
            printf("\nEdge (%d, %d) with weight %d", u, v, min); // Print selected edge
            minCost+=min;
            visited[v]=1; // Mark destination vertex as visited
            edgeCount++; // Increment edge count
            cost[u][v]=cost[v][u]=999; // Remove edge from consideration
        }
    }
    printf("\n\nMin cost = %d", minCost);
}
