#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int map[505][505];//邻接矩阵记录图的信息
int pre[505];//记录前驱结点
int degree[505];//记录每个结点的入度数
int n,m;
void tuopusort()
{
     int i,j;
     for(i=1;i<=n;i++)
     {
          for(j=1;j<=n;j++)
          {
              if(degree[j]==0)//找到一个入度为0的结点
              {
                  degree[j]--;//相当于删除这个结点了
                  pre[i]=j;
                  break;
              }
          }
          for(j=1;j<=n;j++)//寻找与这个结点相连的边，删除边
          {
                if(map[pre[i]][j]==1)
                {
                    degree[j]--;
                    map[pre[i]][j]=0;
                }
          }
     }
     cout<<pre[1];
     for(i=2;i<=n;i++)
        cout<<" "<<pre[i];
     cout<<endl;
}
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        memset(map,0,sizeof(map));
        memset(pre,0,sizeof(pre));
        memset(degree,0,sizeof(degree));
        int i;
        int a,b;
        for(i=0;i<m;i++)
        {
            cin>>a>>b;
            if(map[a][b]==0)
            {
                map[a][b]=1;
                degree[b]++;
            }
        }
        tuopusort();
    }
}
