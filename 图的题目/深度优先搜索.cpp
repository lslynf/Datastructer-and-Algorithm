//先输入n个结点，m条边，之后输入无向图的m条边，之后对上图输出DFS遍历的结点顺序
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
int map[105][105];
int visit[105];
int cnt;
int n,m;
void dfs(int b)
{
    cout<<b<<" ";
    cnt++;
    if(cnt==n)
        return;
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(map[b][i]==1&&visit[i]==0)
            {
                visit[i]=1;
                dfs(i);
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    memset(visit,0,sizeof(visit));
    memset(map,0,sizeof(map));
    int i,j;
    int a,b;
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        map[a][b]=1;
        map[b][a]=1;
    }
    cnt=0;
    visit[1]=1;
    dfs(1);
}
/*
6 9
1 2
1 3
1 5
1 6
2 3
3 4
3 5
4 5
5 6
*/
