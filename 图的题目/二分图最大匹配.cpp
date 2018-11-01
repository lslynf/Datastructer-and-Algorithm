//用于无向图
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int girls[105];
int visit[105];
int map[105][105];
int n,m;//n个男生m个女生
bool FindGirl(int boy)
{
    int i;
    for(i=1;i<=m;i++)
    {
        if(map[boy][i]==1&&visit[i]==0)
        {
            visit[i]=1;
            if(girls[i]==0||FindGirl(girls[i]))
            {
                girls[i]=boy;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    memset(map,0,sizeof(map));
    memset(girls,0,sizeof(girls));
    scanf("%d %d",&n,&m);
    int k;
    scanf("%d",&k);
    int x,y,ans=0;
    int i;
    for(i=0;i<k;i++)
    {
        scanf("%d %d",&x,&y);
        map[x][y]=map[y][x]=1;
    }
    for(i=1;i<=n;i++)
    {
        memset(visit,0,sizeof(visit));
        if(FindGirl(i))
            ans++;
    }
    cout<<"一共有"<<ans<<"对";
}
