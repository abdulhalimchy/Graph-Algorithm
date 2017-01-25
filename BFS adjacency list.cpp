#include<stdio.h>
#include<vector>
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

vector<int> List[100];
int dist[100], path[100];
int nodes;
void ad_list(int nodes)
{
    for(int i=1; i<=nodes; i++)
    {
        int n;
        while(1)
        {
            scanf("%d", &n);
            if(n==0)
                break;
            else
                List[i].push_back(n);
        }
    }
}
void BFS(int source)
{
    int i;
    memset(dist, -1,sizeof(dist));
    memset(path, 0,sizeof(path));
    queue<int> Q;
    vector<int> ::iterator k;
    Q.push(source);
    dist[source]=0;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(k=List[u].begin(); k!=List[u].end(); k++)
        {
            if(dist[*k]==-1)
            {
                Q.push(*k);
                dist[*k]=dist[u]+1;
                path[*k]=u;
            }
        }
    }
}
int distance(int n)
{
    return dist[n];
}
void Path(int n)
{
    int ara[100], i=0;
    while(n!=0)
    {
        ara[i]=n;
        n=path[n];
        i++;
    }
    printf("Path: ");
    for(i=i-1; i>=0; i--)
    {
        printf("%d ", ara[i]);
        if(i!=0)
            printf(" -> ");
    }
    printf("\n");
}
int main()
{
    int start, End;
    scanf("%d", &nodes);
    ad_list(nodes);
    printf("Input Starting point: ");
    scanf("%d", &start);
    printf("Input Ending point: ");
    scanf("%d", &End);
    BFS(start);
    printf("Distance: %d\n", distance(End));
    Path(End);
    return 0;
}
