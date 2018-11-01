/*#include<iostream>
#include<cstring>
using namespace std;
int init[1005][1005];
int visit[1005];
int p,q;
int flag=0;
bool check()
{
	for(int i=1;i<=p;i++)
	{
		if(visit[i]==0)
			return false;
	}
	return true;
}
void dfs(int x)
{
	if(x==p&&check())
	{
		flag=1;
		return;	
	}
	int i;
	for(i=1;i<=9;i++)
	{
		if(init[x][i]==1&&visit[i]==0)
		{
			visit[i]=1;
			dfs(i);
			visit[i]=0;
		}
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>p>>q;
		int i,j;
		int a,b;
		flag=0;
		memset(visit,0,sizeof(visit));
		for(i=0;i<q;i++)
		{
			cin>>a>>b;
			init[a][b]=init[b][a]=1;
		}
		visit[1]=1;
		dfs(1);
		if(flag=1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}
*/
#include<bits/stdc++.h>
using namespace std;
int pre[1005];
int n,m;
int g[1005][1005];
void init(){
	for(int i = 1;i<=n;i++)
		pre[i] = i;
}
int f(int x)
{
	return x==pre[x]?x:pre[x] =f(pre[x]);
}
void add(int x,int y)
{
	int xx = f(x);
	int yy = f(y);
	if(xx!=yy)
	{
		pre[xx] = yy;
	}
}
int main()
{
	map<int,int> Map;
	int t;
	cin>>t;
	while(t--)
	{	
		cin>>n>>m;
		Map.clear();
		init();
		for(int i = 0;i<m;i++){
			int x,y;
			cin>>x>>y;
			add(f(x),f(y));
			Map[x]++;
			Map[y]++;
		}
		int root = f(1),cnt = 0; 
		bool flag = true;
		for(int i =1;i<=n;i++)
		{
			if(f(i)!=root)
				flag = false;
		}
		if(flag == false)
			cout<<"No"<<endl;
		else{
			for(map<int,int> ::iterator iter = Map.begin();iter!=Map.end();iter++ )
			{
				if(iter->second%2)
				{
					cnt++;
				}
			}
			if(cnt==2||cnt == 0)
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
	}
}
