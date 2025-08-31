#include <stdio.h>

void mst(int , int [10][10]);
int find(int);
int uni(int, int);
int ne=1,mincost=0,min,a,b,u,v;
int parent[10]={-1};

int main()
{
    int i,j;
    int n=5;
    int adj[10][10]={
                      {0,10,0,5,3},
                      {10,0,9,12,0},
                      {0,9,0,2,0},
                      {5,12,2,0,7},
                      {3,0,0,7,0},
    };
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            if(adj[i][j]==0){
                adj[i][j]=999;
            }
            printf("%d",adj[i][j]);
        }
    }
    printf("\n\n");
    while(ne<n){
        for(i=0, min=999;i<n;i++){
            for(j=0;j<n;++j){
                if(adj[i][j]<min){
                    min=adj[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(uni(u,v)){
            printf("\n%d edge (%d %d) = %d", ne,a,b,min);
            ne=ne+1;
            mincost=mincost+min;
        }
        adj[a][b]=adj[b][a]=999;
    }
    printf("\nMin cost = %d", mincost);
}
int find(int i){
    while(parent[i]){
        i=parent[i];
    }
    return i;
}
int uni(int i, int j){
    if(i != j){
        parent[j]=i;
        return i;
    }
    return 0;
}
