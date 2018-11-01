#include<bits/stdc++.h>
using namespace std;
int row[5];
int col[5];
char city[5][5];
int n; 
int ans;
void dfs(int cnt,int sum)
{
	int x=cnt/n;
	int y=cnt%n;
	if(cnt>=n*n)
	{
		ans=max(ans,sum);
		return;	
	}
	else
	{
		if(city[x][y]=='.')//要进行判断,如果这一行这一列没有放置东西 
		{
			int flag=0;
			for(int i=x-1;i>=0;i--)
			{
				if(city[i][y]=='X')
					break;
				if(city[i][y]=='*')
				{
					flag=1;
					break;
				}
			}
			for(int i=y-1;i>=0;i--)
			{
				if(city[x][i]=='X')
					break;
				if(city[x][i]=='*')
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				city[x][y]='*';
				cnt=cnt+1;
				sum=sum+1;
				dfs(cnt,sum);
				city[x][y]='.';
				cnt--;
				sum--;
			}
		}
		dfs(cnt+1,sum);	//表示此位置不能放,直接去下一步 
	}
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	
			break;
		int i,j;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++) 
				cin>>city[i][j];
		ans=0;
		dfs(0,0);
		cout<<ans<<endl;
	} 
}
