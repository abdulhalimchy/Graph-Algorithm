#include<stdio.h>
#include<stdbool.h>
#include<queue>
using namespace std;
int G[100][100], node, dist[100];
bool visited[100];

void graph(int edge)
{
    int a, b, i;
    for(i=1; i<=edge; i++)
    {
        scanf("%d %d", &a, &b);
        G[a][b]=1;
        G[b][a]=1;
    }
}

void BFS(int source)
{
    queue<int> Q;
    Q.push(source);
    dist[source]=0;
    visited[source]=1;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        int i;
        for(i=1; i<=node; i++)
        {
            if(G[u][i]==1 && visited[i]==0)
            {
                Q.push(i);
                visited[i]=1;
                dist[i]=dist[u]+1;
            }
        }
    }
    int i;
    for(i=1; i<=node; i++)
    {
        printf("Minimum dist from %d to %d is : %d\n", source, i, dist[i]);
    }
}

int main()
{
    int edge;
    scanf("%d %d", &node, &edge);
    graph(edge);
    int source;
    scanf("%d", &source);
    BFS(source);
    return 0;
}
/*
5
7
1 2
1 3
1 4
2 4
2 5
3 4
4 5
*/
