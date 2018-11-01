//利用优先队列进行优化，复杂度O(logn),注:优先队列中的元素按照优先级排序，可以重载<号
#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#include<iostream>
#define inf  99999999
using namespace std;
int map[1005][1005];
int visit[1005];
int dis[1005];
struct node
{
    int num;//编号
    int val;//到源点的距离
};
bool  operator<(node a,node b)
{
    if(a.val==b.val)
        return a.num>b.num;
    return a.val>b.val;//重载小于号，因此val小的优先级更高
}
priority_queue<node>q;
int main()
{
    int test,n;
    while(scanf("%d %d",&test,&n)!=EOF)
    {
        memset(visit,0,sizeof(visit));
        int i,j;
        for(i=1;i<=n;i++)//初始化
        {
            for(j=1;j<=n;j++)
            {
                if(i==j)
                    map[i][j]=0;
                else
                    map[i][j]=inf;
            }
        }
        while(!q.empty())
            q.pop();
        int a,b,weight;
        for(i=0;i<test;i++)
        {
            scanf("%d %d %d",&a,&b,&weight);
            map[a][b]=map[b][a]=min(weight,map[a][b]);//注意平行边
        }
        for(i=1;i<=n;i++)//采用优化的办法要特别注意的一点，当初始化原始距离数组时，初始为最大值
            dis[i]=inf;
        visit[1]=1;
        dis[1]=0;
        node begin;
        begin.num=1;//把起始点放入队列
        begin.val=0;
        q.push(begin);
        while(!q.empty())
        {
             node t=q.top();
           //  cout<<"选择点:"<<t.num<<endl;
             q.pop();
             visit[t.num]=1;
             for(i=1;i<=n;i++)
             {
                 if(map[t.num][i]<inf)
                 {
                     if(dis[i]>dis[t.num]+map[t.num][i])
                     {
                         dis[i]=dis[t.num]+map[t.num][i];
                         node temp;
                         temp.num=i;
                         temp.val=dis[i];
                         q.push(temp);
                     }
                 }
             }
        }
        cout<<dis[n]<<endl;
    }
}
