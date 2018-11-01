//弗洛伊德算法解决任意两点间的最短路径的算法
//弗洛伊德算法不能解决带有负权回路的图
//弗洛伊德的核心思想即是两点之间是否可以经过另外K个点的中转找到最短路径
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#define  inf  65535
using namespace std;
int map[105][105];
int n,m;
int main()
{
    cin>>n>>m;
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
    //核心代码
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(map[i][j]>map[i][k]+map[k][j])
                map[i][j]=map[i][k]+map[k][j];
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<map[i][j]<<"    ";
        cout<<endl;
    }
}
/*
4 8
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12
*/
