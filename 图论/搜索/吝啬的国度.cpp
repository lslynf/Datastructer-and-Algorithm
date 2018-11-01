#include<bits/stdc++.h>
using namespace std;
int n,s;
map<int,vector<int> >road; 
int ans[100005];//利用一个数组记录前驱结点 
void dfs(int start)
{
	int i;
	for(i=0;i<road[start].size();i++)
	{
		if(ans[road[start][i]])
			continue;
		ans[road[start][i]]=start;
		dfs(road[start][i]);
	}
}
int main()
{
	int m;
	scanf("%d",&m);
	road.clear();
	int a,b;
	while(m--)
	{
		memset(ans,0,sizeof(ans));
		scanf("%d %d",&n,&s);
		ans[s]=-1;
		int i;
		for(i=0;i<n-1;i++)
		{
			scanf("%d %d",&a,&b);
			road[a].push_back(b);
			road[b].push_back(a);
		}
		dfs(s);
		for(i=1;i<=n;i++)
		{
			printf("%d",ans[i]);
			if(i!=n)
				printf(" ");
			else
				printf("\n");
		}
	}
}


