#include<iostream> 
#include<set>
#include<cstring>
using namespace std;
int a[4][4];
int step=17;
set<int> ans;
void change(int pos)
{
	int x=pos/4;
	int y=pos%4;
	if(x>=0&&x<=3&&y>=0&&y<=3)
	{
		for(int i=0;i<4;i++)
			a[i][y]=!a[i][y];
		for(int j=0;j<4;j++)
			a[x][j]=!a[x][j];
		a[x][y]=!a[x][y];
	}
}
int finish()
{
	int sum=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			sum+=a[i][j];
		}
	}
	if(sum==16)
		return 1;
	else
		return 0;	
} 
void dfs(int pos,int cnt)
{
	if(finish())
	{
		if(step>cnt)
		{
			step=cnt;
			return;
		}
	}
	if(pos>=16)
		return;
	dfs(pos+1,cnt);
	change(pos);
	dfs(pos+1,cnt+1);
	change(pos);
}
int main()
{
	memset(a,0,sizeof(a));
	char c;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
	    {
	    	cin>>c;
	    	if(c=='-')
	 			a[i][j]=1;
	 		else
	 			a[i][j]=0;
		}
	}
	dfs(0,0);
	printf("%d\n",step);
}

 
