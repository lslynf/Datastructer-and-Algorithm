//如下图，需要坐飞机从1号城市到5号城市，求最小的转机次数
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;
int n,m;
int start,end;
int map[105][105];
int visit[105];
struct node
{
    int name;
    int step;
};
void bfs()
{
    queue<node>q;
    while(!q.empty())
        q.pop();
    node begin;
    begin.name=start;
    begin.step=0;
    q.push(begin);
    int i;
    while(!q.empty())
    {
        node t=q.front();
        q.pop();
        if(t.name==end)
        {
            cout<<t.step<<endl;
            return;
        }
        for(i=1;i<=n;i++)
        {
            if(map[t.name][i]!=0&&visit[i]==0)
            {
                visit[i]=1;
                node temp;
                temp.name=i;
                temp.step=t.step+1;
                q.push(temp);
            }
        }
    }
}
int main()
{
    cin>>n>>m>>start>>end;
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
    visit[1]=1;
    bfs();
}
/*
5 7 1 5
1 2
1 3
2 3
2 4
3 4
3 5
4 5
*/
