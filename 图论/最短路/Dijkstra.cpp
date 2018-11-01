//邻接矩阵 
#include<bits/stdc++.h>
#define inf 99999999
using namespace std;
int road[105][105];
int visit[105];
int init[105];
int n;
void Dijkstra()
{
	int i,j;
	for(i=1;i<=n;i++)
		init[i]=road[1][i];
	visit[1]=1;
	int mincost;
	int temp;
	for(i=1;i<=n;i++)
	{
		mincost=inf;
		for(j=1;j<=n;j++)
		{
			if(visit[j]==0&&init[j]<mincost)
			{
				mincost=init[j];
				temp=j;
			}
		}
		visit[temp]=1;
		for(j=1;j<=n;j++)
		{
			if(visit[j]==0)
			{
				if(init[j]>init[temp]+road[temp][j])
					init[j]=init[temp]+road[temp][j];
			}
		}
	}
}
int main()
{
	int m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		memset(visit,0,sizeof(visit));
		memset(init,0,sizeof(init));
		int i,j;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==j)
					road[i][j]=0;
				else
					road[i][j]=inf;
			}
		}
		int a,b,weight;
		for(i=0;i<m;i++)
		{
			cin>>a>>b>>weight;
			road[a][b]=weight;
		}
		Dijkstra();
		cout<<init[n]<<endl;
	}
}
//邻接链表
/*#include<bits/stdc++.h>
#define inf 99999999
using namespace std;
int visit[105];
int init[105];
struct node
{
   int next;
   int weight;
   node()
   {
   	 next=weight=0;
   }
   node(int a,int b)
   {
   	 next=a;
   	 weight=b;
   }
};
map<int,vector<node> > road;
int n,m;
void Dijkstra()
{
	int i,j;
	for(i=1;i<=n;i++)
		init[i]=inf;
//	for(i=0;i<road[1].size();i++)
//		init[road[1][i].next]=road[1][i].weight;
	int mincost;
	int temp;
	for(i=1;i<=n;i++)
	{
		mincost=inf;
		for(j=1;j<=n;j++)
		{
			if(visit[j]==0&&init[j]<mincost)
			{
				mincost=init[j];
				temp=j;
			}
		}
		visit[temp]=1;
		//更新init[j]的值,问题找到temp中next为j的节点 
		for(j=0;j<road[temp].size();j++) 
		{
			if(visit[road[temp][j].next]==0)
			{
				if(init[road[temp][j].next]>init[temp]+road[temp][j].weight)
					init[road[temp][j].next]=init[temp]+road[temp][j].weight;
			}
		}
	}
}
int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;	
		road.clear();	
		memset(visit,0,sizeof(visit));
		int a,b,c;
		int i;
		for(i=0;i<m;i++)
		{
			cin>>a>>b>>c;
			road[a].push_back(node(b,c));
			road[b].push_back(node(a,c));
		}
		Dijkstra();
		cout<<init[n]<<endl;
	}
}*/
//优先队列+邻接表优化 
/*#include<bits/stdc++.h>
#define inf 99999999
using namespace std;
int visit[105];
int init[105];
struct node
{
   int next;
   int weight;
   node()
   {
   	 next=weight=0;
   }
   node(int a,int b)
   {
   	 next=a;
   	 weight=b;
   }
};
bool operator<(node a,node b)//重载小于号，优先级 
{
	if(a.weight==b.weight)
		return a.next>b.next;
	return a.weight>b.weight;
}
map<int,vector<node> > road;
int n,m;
void Dijkstra()
{
	int i,j;
	for(i=1;i<=n;i++)
		init[i]=inf;
	priority_queue<node>q;
	while(!q.empty())
		q.pop();
	node begin;
	begin.next=1;
	begin.weight=0;
	visit[1]=1;
	init[1]=0;
	q.push(begin);
	while(!q.empty())
	{
		node t=q.top();//找到一个确定点 
		q.pop();
		int temp=t.next;
		visit[temp]=1;
		for(j=0;j<road[temp].size();j++)
		{
			if(visit[road[temp][j].next]==0)
			{
				if(init[road[temp][j].next]>init[temp]+road[temp][j].weight)
					{
						init[road[temp][j].next]=init[temp]+road[temp][j].weight;
						node op;
						op.next=road[temp][j].next;
						op.weight=init[road[temp][j].next];
						q.push(op);
					}
			}
		}
	}
}
int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;	
		road.clear();	
		memset(visit,0,sizeof(visit));
		int a,b,c;
		int i;
		for(i=0;i<m;i++)
		{
			cin>>a>>b>>c;
			road[a].push_back(node(b,c));
			road[b].push_back(node(a,c));
		}
		Dijkstra();
		cout<<init[n]<<endl;
	}
}
*/
