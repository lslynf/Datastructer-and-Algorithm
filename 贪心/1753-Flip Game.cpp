#include<iostream>
#include<cstring>
using namespace std;
int a[4][4];
int step=17;//最多翻转17次
void change(int x,int y)
{
	if(x>=0&&x<=3&&y>=0&&y<=3)
		a[x][y]=!a[x][y];
}
void flip(int p) 
{
	int i=p/4;
	int j=p%4;
	change(i,j);
	change(i-1,j);
	change(i,j-1);
	change(i,j+1);
	change(i+1,j);
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
	if(sum==0||sum==16)
		return 1;
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
	dfs(pos+1,cnt);//不翻转，搜索下一个
	flip(pos);//进行翻转
	dfs(pos+1,cnt+1);//翻转后，搜索下一个
	flip(pos);//恢复状态 
}
int main()
{
	char c;
	memset(a,0,sizeof(a));
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cin>>c;
			if(c=='b')
				a[i][j]=1;
			else
				a[i][j]=0;
		}
	}
	dfs(0,0);
	if(step==17)
		printf("Impossible\n");
	else
		printf("%d\n",step);
}
