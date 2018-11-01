//spfa�㷨:
//���Խ�����и�Ȩ�ıߵ����� 
//��bellman-ford�㷨�Ķ����Ż��㷨�ı�� 
#include<bits/stdc++.h>
#define inf 2e9
using namespace std;
struct node
{
	int next;
	int weight;
	node(){next=weight=0;}
	node(int a,int b)
	{
		next=a;
		weight=b;
	}
};
int visit[20005];//����ڶ������Ԫ�� 
int dis[20005];
map<int,vector<node> >road;
int n,m;
void SPFA()
{
	int i,j;
	for(i=1;i<=n;i++)
		dis[i]=inf;
	dis[1]=0;
	visit[1]=1;
	queue<int>q;
	q.push(1);
	while(!q.empty()) 
	{
		int t=q.front();
		q.pop();
		visit[t]=0;//�ͷŶ�t�ı��,����������� 
		//���������ֵ
		for(i=0;i<road[t].size();i++)
		{
			if(dis[road[t][i].next]>dis[t]+road[t][i].weight)
			{
				dis[road[t][i].next]=dis[t]+road[t][i].weight;
				if(visit[road[t][i].next]==0)//������ڶ��� 
				{
					q.push(road[t][i].next);
					visit[road[t][i].next]=1;
				} 
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	int i;
	memset(visit,0,sizeof(visit));
	road.clear();
	int a,b,c;
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		road[a].push_back(node(b,c));
//		road[b].push_back(node(a,c));
	}
	SPFA();
	for(i=2;i<=n;i++)
		printf("%d\n",dis[i]);
}
 
