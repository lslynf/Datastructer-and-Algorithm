//例:求下图中的1号顶点到2、3、4、5、6号顶点的最短路径。
//基本思想:每次找到离源点最近的一个顶点，然后以该顶点为中心进行扩展，最终得到源点到其余所有点的最短路径
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#define inf  65535
using namespace std;
int n,m;
int visit[105];//标记是否是确定的距离
int map[105][105];
int dis[105];//初始是源点到各点的原始距离，在操作中不断更新此数组，得到最短路径
int main()
{
    cin>>n>>m;
    memset(visit,0,sizeof(visit));
    int i,j,k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
             if(i==j)
                map[i][j]=0;
             else
                map[i][j]=inf;
        }
    }
    int a,b;
    int weight;
    for(i=0;i<m;i++)
    {
         cin>>a>>b>>weight;
         map[a][b]=weight;
    }
    for(i=1;i<=n;i++)
        dis[i]=map[1][i];
    visit[1]=1;
    //核心代码:每次找到离源点最近的点，然后通过此点更新到其他点的距离
    int  dmin;
    int temp;
    for(i=1;i<=n-1;i++)
    {
        dmin=inf;
        //找到点
        for(j=1;j<=n;j++)
        {
            if(visit[j]==0&&dis[j]<dmin)
                {
                    dmin=dis[j];
                    temp=j;
                }
        }
        visit[temp]=1;
        //更新距离
        for(k=1;k<=n;k++)
        {
            if(map[temp][k]<inf)//或者写成visit[k]==0(也即该点未被确定)
            {
                if(dis[k]>dis[temp]+map[temp][k])
                    dis[k]=dis[temp]+map[temp][k];
            }
        }
    }
    for(i=1;i<=n;i++)
        cout<<dis[i]<<" ";
    cout<<endl;
}
/*
6 9
1 2 1
1 3 12
2 3 9
2 4 3
3 5 5
4 3 4
4 5 13
4 6 15
5 6 4
*/
