//��:����ͼ�е�1�Ŷ��㵽2��3��4��5��6�Ŷ�������·����
//����˼��:ÿ���ҵ���Դ�������һ�����㣬Ȼ���Ըö���Ϊ���Ľ�����չ�����յõ�Դ�㵽�������е�����·��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#define inf  65535
using namespace std;
int n,m;
int visit[105];//����Ƿ���ȷ���ľ���
int map[105][105];
int dis[105];//��ʼ��Դ�㵽�����ԭʼ���룬�ڲ����в��ϸ��´����飬�õ����·��
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
    //���Ĵ���:ÿ���ҵ���Դ������ĵ㣬Ȼ��ͨ���˵���µ�������ľ���
    int  dmin;
    int temp;
    for(i=1;i<=n-1;i++)
    {
        dmin=inf;
        //�ҵ���
        for(j=1;j<=n;j++)
        {
            if(visit[j]==0&&dis[j]<dmin)
                {
                    dmin=dis[j];
                    temp=j;
                }
        }
        visit[temp]=1;
        //���¾���
        for(k=1;k<=n;k++)
        {
            if(map[temp][k]<inf)//����д��visit[k]==0(Ҳ���õ�δ��ȷ��)
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
