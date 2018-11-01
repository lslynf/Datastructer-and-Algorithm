//弗洛伊德算法求任意两点之间的最短路径 
#include<bits/stdc++.h>
#define inf 999999999
using namespace std;
int road[105][105];
int main() 
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break; 
		int i,j,k;
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
			road[a][b]=road[b][a]=weight;
		}
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					if(road[i][k]+road[k][j]<road[i][j])
						road[i][j]=road[i][k]+road[k][j];
				}
			}
		}
		cout<<road[1][n]<<endl;
	}
}
