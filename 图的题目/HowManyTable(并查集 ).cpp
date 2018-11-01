#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int pre[1005];
int visit[1005];
int FindRoot(int x)
{
    int r=x;
    while(pre[r]!=r)
        r=pre[r];//一直往前找到根节点
    return r;
}
int Zip(int x)
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
    int rx=FindRoot(x);
    int ry=FindRoot(y);
    if(rx==ry)
        return;
    pre[rx]=ry;
}
int main()
{
    int t;
    int n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        int i;
        int ans=0;
        for(i=1;i<=n;i++)
            pre[i]=i;
        memset(visit,0,sizeof(visit));
        int a,b;
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            Join(a,b);
        }
        for(i=1;i<=n;i++)
        {
            visit[Zip(i)]=1;
        }
        for(i=1;i<=n;i++)
        {
            if(visit[i]==1)
                ans++;
        }
        cout<<ans<<endl;
    }
}
