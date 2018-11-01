//求连通块的数量 
#include<bits/stdc++.h> 
using namespace std;
int n,m;//行数，列数
int p[105][105];
void dfs(int a,int b)
{
	if(a<0||a>=n||b<0||b>m) 
		return;
	if(p[a][b]==0)
		return;
	p[a][b]=0;
	dfs(a-1,b);
	dfs(a,b-1);
	dfs(a+1,b);
	dfs(a,b+1);
}
int main()
{
	int t;
	cin>>t;
	int i,j;
	int cnt;
	while(t--)
	{
		cin>>n>>m;
		cnt=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				cin>>p[i][j];
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(p[i][j]==1)
				{
					dfs(i,j);
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}
}

