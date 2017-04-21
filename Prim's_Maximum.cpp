#include<stdio.h>
#define INF 2141345
int G[100][100], node, edge, visited[100];
void graph()
{
    int a, b, w, i;
    for(i=1; i<=edge; i++)
    {
        scanf("%d %d %d", &a, &b, &w);
        G[a][b]=w;
        G[b][a]=w;
    }
}
void MST_Prims(int source)
{
    int i, j, cnt=0, sum=0;
    visited[source]=1;
    cnt++;
    while(cnt<node)
    {
        int mx=0, a, b;
        for(i=1; i<=node; i++)
        {
            if(visited[i]==1)
            {
                for(j=1; j<=node; j++)
                {
                    if(G[i][j]>mx && visited[j]==0)
                    {
                        mx=G[i][j];
                        a=i, b=j;
                    }
                }
            }
        }
        cnt++;
        visited[b]=1;
        printf("Cost from %d to %d is : %d\n", a, b, G[a][b]);
        sum+=G[a][b];
    }
    printf("Total Maximum cost is : %d\n", sum);
}

int main()
{
    scanf("%d %d", &node, &edge);
    int i, j;
    graph();
    int source;
    scanf("%d", &source);
    MST_Prims(source);
}
/*
7
11
1 2 1
1 6 2
2 3 2
2 7 4
3 7 3
3 4 15
3 5 11
4 5 10
5 6 7
5 7 5
6 7 1
*/

