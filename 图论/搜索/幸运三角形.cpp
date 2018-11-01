#include<bits/stdc++.h> 
using namespace std;
char graph[25][25];
int n;
int cnt;
int sum1,sum2;
void dfs(int a)
{
	int i,j;
	sum1=sum2=0;
	if(a==n)//表示三角形已经确定了，进行统计 
	{
		for(i=0;i<n;i++)
		{
			for(j=1;j<n-i;j++)
			{
				if(graph[i][j-1]==graph[i][j])
				{
					sum1++;
					graph[i+1][j-1]='+';
				}
				else
				{
					sum2++;
					graph[i+1][j-1]='-';
				}
			}
		}
		//统计第一排
		for(i=0;i<n;i++) 
		{
			if(graph[0][i]=='+')
				sum1++;
			else
				sum2++;
		}
		if(sum1==sum2&&sum1!=0&&sum2!=0)
			cnt++;
	}
	else
	{
		graph[0][a]='+';
		dfs(a+1);
		graph[0][a]='-';
		dfs(a+1);
	}
}
int main()
{
	while(scanf("%d",&n)!=EOF) 
	{
		int i;
		memset(graph,0,sizeof(graph));
		cnt=0;
		if((n*(n+1)/2)%2==0)
		{
			dfs(0);
			printf("%d\n",cnt);
		}
		else
			printf("%d\n",0);
	}
}
