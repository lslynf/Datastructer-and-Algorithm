//Kruskal最小生成树算法，贪心加并查集
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int pre[105];//记录父亲节点
int height[105];//记录树的高度
int n,m;
struct  edge//定义边的结构体
{
    int start;
    int end;
    int weight;
};
edge  eset[105];
//按照权值排序
bool cmp(edge a,edge b)
{
    if(a.weight==b.weight)
        return a.start<b.start;
    return a.weight<b.weight;
}
int FindRoot(int x)
{
    int r=x;
    while(pre[r]!=r)
        r=pre[r];
    int i=r;
    int temp;
    while(pre[i]!=r)
    {
        temp=pre[i];
        pre[i]=r;
        i=temp;
    }
    return r;
}
void  Join(int x,int y)
{
    int rx=pre[x];
    int ry=pre[y];
    if(rx==ry)
        return;
    if(height[x]>height[y])
    {
        pre[y]=x;
    }
    else
    {
        pre[x]=y;
        if(height[x]==height[y])
            height[y]++;
    }
}
int Kruskal()
{
    int cnt=0;//记录加入的边数
    int res=0;//记录权值之和
    sort(eset,eset+n,cmp);//对边进行排序
    //遍历所有的边进行最小生成树的构建
    int i;
    for(i=0;i<n;i++)
    {
        if(cnt==m-1)
            break;
        else
        {
            //每次找到权值最小的边，判断是否不在同一棵树，连接起来
            if(FindRoot(eset[i].start)!=FindRoot(eset[i].end))
            {
                res+=eset[i].weight;
                Join(eset[i].start,eset[i].end);
                cnt++;
            }
        }
    }
    if(cnt!=m-1)
        res=-1;
    return res;

}
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0)
            break;
        int i,j;
        int ans=0;
        for(i=1;i<=m;i++)
        {
            pre[i]=i;
            height[i]=0;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d",&eset[i].start,&eset[i].end,&eset[i].weight);
        }
        ans=Kruskal();
        if(ans==-1)
            printf("?\n");
        else
            printf("%d\n",ans);
    }
}
