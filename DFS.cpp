#include<stdio.h>
using namespace std;
int G[100][100], node,visited[100];

void graph(int edge)
{
    int a, b, i;
    for(i=1; i<=edge; i++)
    {
        scanf("%d %d", &a, &b);
        G[a][b]=1;
    }
}
void DFS(int source)
{
    visited[source]=1;
    int i;
    for(i=1; i<=node; i++)
    {
        if(G[source][i]==1 && visited[i]==0)
        {
            DFS(i);
        }
    }
}
int main()
{
    int edge;
    scanf("%d %d", &node, &edge);
    graph(edge);
    int source;
    scanf("%d", &source);
    DFS(source);
    int i;
    for(i=1; i<=node; i++)
    {
        if(visited[i]==1)
            printf("%d ", i);
    }
    return 0;
}
/*
5
7
1 2
1 3
2 3
2 4
2 5
4 3
4 5
*/
