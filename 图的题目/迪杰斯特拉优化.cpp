//�������ȶ��н����Ż������Ӷ�O(logn),ע:���ȶ����е�Ԫ�ذ������ȼ����򣬿�������<��
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
    int num;//���
    int val;//��Դ��ľ���
};
bool  operator<(node a,node b)
{
    if(a.val==b.val)
        return a.num>b.num;
    return a.val>b.val;//����С�ںţ����valС�����ȼ�����
}
priority_queue<node>q;
int main()
{
    int test,n;
    while(scanf("%d %d",&test,&n)!=EOF)
    {
        memset(visit,0,sizeof(visit));
        int i,j;
        for(i=1;i<=n;i++)//��ʼ��
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
            map[a][b]=map[b][a]=min(weight,map[a][b]);//ע��ƽ�б�
        }
        for(i=1;i<=n;i++)//�����Ż��İ취Ҫ�ر�ע���һ�㣬����ʼ��ԭʼ��������ʱ����ʼΪ���ֵ
            dis[i]=inf;
        visit[1]=1;
        dis[1]=0;
        node begin;
        begin.num=1;//����ʼ��������
        begin.val=0;
        q.push(begin);
        while(!q.empty())
        {
             node t=q.top();
           //  cout<<"ѡ���:"<<t.num<<endl;
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
