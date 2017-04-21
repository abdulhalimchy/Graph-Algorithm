#include<bits/stdc++.h>
#define MX 105
using namespace std;
int cost[MX][MX], dist[MX], node, edge;
void List()
{
    int a, b, w;
    for(int i=1; i<=edge; i++)
    {
        scanf("%d %d %d", &a, &b, &w);
        cost[a][b]=w;
    }
}
void BellmanFord(int source)
{
    dist[source]=0;
    for(int i=1; i<=node-1; i++)
    {
        for(int u=1; u<=node; u++)
        {
            for(int v=1; v<=node; v++)
            {
                if(cost[u][v]!=0 && dist[u]+cost[u][v]<dist[v])
                {
                    dist[v]=dist[u]+cost[u][v];
                }
            }
        }
    }
    for(int u=1; u<=node; u++)
    {
        for(int v=1; v<=node; v++)
        {
            if(cost[u][v]!=0 && dist[u]+cost[u][v]<dist[v])
            {
                printf("Negative cycle found, so there is no solution exist\n");
                return;
            }
        }
    }
    for(int u=1; u<=node; u++)
    {
        printf("The minimum distance from %d to %d is : %d\n", source, u, dist[u]);
    }
}
int main()
{
    scanf("%d %d", &node, &edge);
    memset(dist, 0x3f, sizeof(dist));
    List();
    int source;
    scanf("%d", &source);
    BellmanFord(source);
}

/*
5
10
1 2 6
1 3 7
2 3 8
2 4 5
2 5 -4
3 4 -3
3 5 9
4 2 -2
5 1 2
5 4 7
1
*/

/*
3
3
1 2 3
2 3 2
3 1 -10
1
*/
