#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
vector<int >map[30005];
int degree[30005];
int pre[30005];
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
                degree[j]--;
                pre[i]=j;
                break;
            }
        }
        for(j=0;j<map[pre[i]].size();j++)//删除此结点所连接的边
        {
             degree[map[pre[i]][j]]--;
        }
    }
    for(i=1;i<n;i++)
        printf("%d ",pre[i]);
    printf("%d\n",pre[n]);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        memset(degree,0,sizeof(degree));
        memset(pre,0,sizeof(pre));
        int i,j;
        for(i=0;i<30005;i++)
            map[i].clear();
        int a,b;
        for(i=0;i<m;i++)
        {
             scanf("%d %d",&a,&b);
             /*int flag=0;
             for(j=0;j<map[a].size();j++)
                if(map[a][j]==b)
                    flag=1;
             if(flag!=1)
             {*/
                 map[a].push_back(b);
                 degree[b]++;
             //}
        }
        tuopusort();
    }
}
