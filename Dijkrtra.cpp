#include<bits/stdc++.h>
#define LL long long
#define MX 105
using namespace std;
int cost[MX][MX], node, edge, dist[MX];

void graph()
{
    memset(dist, 0x3f, sizeof(dist));
    int a, b, c;
    for(int i=1; i<=edge; i++)
    {
        cin >> a >> b >> c;
        cost[a][b]=c;
        cost[b][a]=c;
    }
}
void dijkstra(int source)
{
    queue<int> Q;
    dist[source]=0;
    Q.push(source);
    while(Q.size())
    {
        int u=Q.front();
        Q.pop();
        for(int i=1; i<=node; i++)
        {
            if(cost[u][i]!=0 && cost[u][i]+dist[u]<dist[i])
            {
                dist[i]=dist[u]+cost[u][i];
                Q.push(i);
            }
        }
    }
}
int main()
{
    cin >> node >> edge;
    graph();
    int source;
    cout << "Source: ";
    cin >> source;
    dijkstra(source);
    for(int i=1; i<=node; i++)
        printf("From %d to %d , the cost is : %d\n", source, i, dist[i]);
    return 0;
}
/*
9
14
1 2 4
1 8 8
2 3 8
2 8 11
3 4 7
3 6 4
3 9 2
4 5 9
4 6 14
5 6 10
6 7 2
7 8 1
7 9 6
8 9 7
*/
