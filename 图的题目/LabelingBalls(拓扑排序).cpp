//同要判断有向无环图加上拓扑排序,注意题目说的是输出的是重量
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
int map[205][205];
int res[205];
int degree[205];
int n,m;
void tuopusort()
{
    int i,j;
    queue<int>zero;
    for(i=1;i<=n;i++)
    {
        if(degree[i]==0)
            {
                zero.push(i);
                res[i]=1;
            }
    }
    int cnt=0;
    while(!zero.empty())
    {
        int p=zero.front();
        degree[p]--;
        cnt++;
        zero.pop();
        for(j=1;j<=n;j++)
        {
            if(map[p][j]==1)
            {
                    map[p][j]=0;
                    degree[j]--;
                    res[j]=max(res[p]+1,res[j]);
                    if(degree[j]==0 )
                        zero.push(j);
            }
        }
    }
    if(cnt<n)
        cout<<"-1"<<endl;
    else
    {
        for(int i=0;i<cnt;i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
}
/*void tuopusort()
{
    int i,j;
    int cnt=0;
    for(i=1;i<=n;i++)
    {
         for(j=1;j<=n;j++)
         {
             if(degree[j]==0)
             {
                 cnt++;
                 degree[j]--;
                 res[cnt]=j;
                 break;
             }
         }
         for(j=1;j<=n;j++)
         {
             if(map[res[cnt]][j]==1)
             {
                  degree[j]--;
                  map[res[cnt]][j]==0;
             }
         }
    }
    if(cnt<n)
        cout<<"-1"<<endl;
    else
    {
        for(int i=1;i<=cnt;i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
}*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int i,j;
        int a,b;
        memset(degree,0,sizeof(degree));
        memset(res,0,sizeof(res));
        memset(map,0,sizeof(map));
        for(i=0;i<m;i++)
        {
            cin>>a>>b;
            map[a][b]=1;
            degree[b]++;
        }
        tuopusort();
    }
}
