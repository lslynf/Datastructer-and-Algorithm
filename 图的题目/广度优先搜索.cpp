#include<stdio.h>
#include<queue>
#include<string.h>
#include<iostream>
using namespace std;
int map[105][105];
int visit[105];
int cnt;
int n,m;
void bfs(int begin)
{
    queue<int >q;
    while(!q.empty())
        q.pop();
    q.push(begin);
    int i;
    while(!q.empty())
    {
        int t=q.front();
        cout<<t<<" ";
        q.pop();
        for(i=1;i<=n;i++)
        {
            if(map[t][i]==1&&visit[i]==0)
                {
                    q.push(i);
                    visit[i]=1;
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
    bfs(1);
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
