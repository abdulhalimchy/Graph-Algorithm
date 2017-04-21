#include<bits/stdc++.h>
#define MX 1005
using namespace std;
int s1[MX], s2[MX], w[MX], node, edge, parent[MX];
int Find_parent(int n)
{
    if(parent[n]==n)
        return n;
    return Find_parent(parent[n]);
}
void graph()
{
    for(int i=1; i<=edge; i++)
        scanf("%d %d %d", &s1[i], &s2[i], &w[i]);
    for(int i=1; i<=edge; i++)
    {
        for(int j=1; j<=edge-i; j++)
        {
            if(w[j+1]<w[j])
            {
                swap(w[j+1], w[j]);
                swap(s1[j+1], s1[j]);
                swap(s2[j+1], s2[j]);
            }
        }
    }
}
void kruskal()
{
    int sum=0;
    for(int i=1; i<=node; i++)
        parent[i]=i;
    for(int i=1; i<=edge; i++)
    {
        int u=Find_parent(s1[i]), v=Find_parent(s2[i]);
        if(u!=v)
        {
            printf("The cost from %d to %d is : %d\n", s1[i], s2[i], w[i]);
            parent[u]=v;
            sum+=w[i];
        }
    }
    printf("Total sum: %d\n", sum);
}
int main()
{
    scanf("%d %d", &node, &edge);
    graph();
    kruskal();
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
