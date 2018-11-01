//并查集中有两个主要的函数，一个是查找，一个是合并，查找是返回当前结点的所在树的根节点
//合并是把两个连通分量连接起来
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int pre[1005];//记录该节点的前驱结点
int visit[1005];//记录有多少个连通分量
int FindRoot(int x)
{
    int r=x;
    while(pre[r]!=r)
        r=pre[r];
    return r; 
}
//进行路径压缩,把根节点变为同一个结点
int  zip(int x)
{
    int r=FindRoot(x);
    int i=x;
    int temp;
    while(pre[i]!=r)
    {
        temp=pre[i];
        pre[i]=r;
        i=temp;
    }
    return r;
}
void Join(int x,int y)
{
    int rx,ry;
    rx=FindRoot(x);
    ry=FindRoot(y);
    if(rx==ry)
        return;
    pre[rx]=ry;
}
int main()
{
    int n,m;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        scanf("%d",&m);
        int i,j;
        int ans=0;
        memset(visit,0,sizeof(visit));
        for(i=1;i<=n;i++)
            pre[i]=i;
        int a,b;
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&a,&b);
            Join(a,b);
        }
        for(i=1;i<=n;i++)
        {
            visit[zip(i)]=1;
        }
        for(i=1;i<=n;i++)
        {
            if(visit[i]==1)
                ans++;
        }
        cout<<ans-1<<endl;
    }
}
