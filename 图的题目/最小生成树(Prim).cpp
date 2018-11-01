#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#define inf  999999999
using namespace std;
int map[105][105];
int lowcost[105];//记录当前的以i为终点的边的最小权值
int mst[105];//记录某条边的起点和终点(mst[i],i)
int n,m;
//不断找权值最小的边然后对数组进行更新
int Prim()
{
    int i,j,k;
    //初始化
    for(i=2;i<=n;i++)
    {
        lowcost[i]=map[1][i];
        mst[i]=1;
    }
    mst[1]=0;
    int mincost;
    int minid;
    int sum=0;
    for(i=2;i<=n;i++)
    {
        mincost=inf;
        minid=0;
        //找到最小权值边
        for(j=2;j<=n;j++)
        {
            if(mincost>lowcost[j]&&mst[j]!=0)
            {
                mincost=lowcost[j];
                minid=j;
            }
        }
        //输出该边
        cout<<"边:v"<<mst[minid]<<"-->"<<"v"<<minid<<"权值:"<<mincost<<endl;
        sum+=mincost;
        //更新值
        lowcost[minid]=0;//该点加入最小生成树
        mst[minid]=0;
        for(k=2;k<=n;k++)
        {
            if(lowcost[k]>map[minid][k]&&mst[k]!=0)
            {
                lowcost[k]=map[minid][k];
                mst[k]=minid;
            }
        }
    }
    return sum;
}
int main()
{
    int i,j;
    int ans;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            map[i][j]=inf;
    }
    int a,b,weight;
    for(i=0;i<m;i++)
    {
        cin>>a>>b>>weight;
        map[a][b]=map[b][a]=weight;
    }
    ans=Prim();
    /*for(i=1;i<=n;i++)
        cout<<mst[i]<<" "<<lowcost[i]<<" ";
    cout<<endl;*/
    cout<<"最小权值之和是:"<<ans<<endl;
}
/*
6 10
1 2 6
1 3 1
1 4 5
2 3 5
2 5 3
3 4 5
3 5 6
3 6 4
4 6 2
5 6 6
*/
