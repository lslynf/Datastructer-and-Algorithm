//#include<bits/stdc++.h>
//using namespace std;
//int init[10][10];
//int visit[10];
//int vis[10];
//void dfs(int x,int y)
//{
//	if(x<1||y<1||x>9||y>9)
//		return ;
//	memset(visit,0,sizeof(visit));
//	//�ж���,��,3*3��С�����������ֹ�������
//	int i,j;
//	for(i=1;i<=9;i++) 
//	{
//		if(init[x][i]!=0)	
//			visit[init[x][i]]=1;
//		if(init[i][y]!=0)
//			visit[init[i][y]]=1;
//	}
//	int bx=(x-1)/3;//С��������� 
//	int by=(y-1)/3;
//	int sx=bx*3+1,sy=by*3+1;
//	for(i=sx;i<sx+3;i++) 
//	{
//		for(j=sy;j<sy+3;j++)
//		{
//			if(init[i][j]!=0)
//				visit[init[i][j]]=1;
//		}
//	}
//	for(i=1;i<=9;i++)
//		vis[i]=visit[i];
//	for(i=1;i<=9;i++)
//	{
//		if(!vis[i]&&init[x][y]==0)
//		{
//			vis[i]=1;
//			init[x][y]=i;
//			if(y==9)
//				dfs(x+1,1);
//			else
//				dfs(x,y+1);
//			vis[i]=0;
//			init[x][y]=0;
//		}
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	int i,j;
//	while(n--)
//	{
//		memset(vis,0,sizeof(vis));
//		for(i=1;i<=9;i++)
//		{
//			for(j=1;j<=9;j++)
//				scanf("%d",&init[i][j]);
//		}
//		dfs(1,1);
//		for(i=1;i<=9;i++)
//		{
//			for(j=1;j<=9;j++)
//				cout<<init[i][j]<<" ";
//			cout<<endl;
//		}
//	}
//}
#include<bits/stdc++.h>
using namespace std;
int init[10][10];
int visrow[10][10];//�ֱ��¼ÿһ��ÿһ��ÿ��С�����״̬ 
int viscol[10][10];
int visbol[10][10];
int flag=0;
void dfs(int x,int y)
{
	int i,j;
	int bx=(x-1)/3;//С��������� 
	int by=(y-1)/3;
	int sx=bx*3+1,sy=by*3+1;//ÿ���������Ͻ����� 
	int cnt=bx*3+by+1;//�ڼ���С���� 
	if(x==9&&y==9)//��ھŸ� 
	{
		for(i=1;i<=9;i++)
		{
			if(!visrow[x][i]&&!viscol[y][i]&&!visbol[cnt][i])
			{
				init[x][y]=i;
				break;
			}
		}
		flag=1;
		return;
	}
	for(i=1;i<=9;i++)
	{
		visrow[x][i]=0;
		viscol[y][i]=0;
		visbol[cnt][i]=0;
	}
	for(i=1;i<=9;i++)
	{
		if(init[x][i]!=0)	
			visrow[x][init[x][i]]=1;
		if(init[i][y]!=0)
			viscol[y][init[i][y]]=1;
	}
	for(i=sx;i<sx+3;i++) 
	{
		for(j=sy;j<sy+3;j++)
		{
			if(init[i][j]!=0)
			{
				visbol[cnt][init[i][j]]=1;	
			}
		}
	}
	if(init[x][y]!=0)
	{
		if(y==9)
		  dfs(x+1,1);
		else
		  dfs(x,y+1);
	}
	else
	{
		for(i=1;i<=9;i++)
		{
			if(!visrow[x][i]&&!viscol[y][i]&&!visbol[cnt][i])
			{
				visrow[x][i]=viscol[y][i]=visbol[cnt][i]=1;
				init[x][y]=i;
				if(y==9)
					dfs(x+1,1);
				else
					dfs(x,y+1);
				if(flag)
					return;
				visrow[x][i]=viscol[y][i]=visbol[cnt][i]=0;
				init[x][y]=0;
			}
		}
	}
}
int main()
{
	int n;
	cin>>n;
	memset(visrow,0,sizeof(visrow));
	memset(viscol,0,sizeof(viscol));
	memset(visbol,0,sizeof(visbol));
	while(n--)
	{
		int i,j;
		flag=0;
		for(i=1;i<=9;i++)
		{
			for(j=1;j<=9;j++) 
				cin>>init[i][j];
		}	
		dfs(1,1);
		for(i=1;i<=9;i++)
		{
			for(j=1;j<=9;j++)
				cout<<init[i][j]<<" ";
			cout<<endl;
		}
	}
}
/*#include<bits/stdc++.h> 
using namespace std;
int init[10][10];
bool flag=false;
bool check(int x,int y,int val)
{
	int i,j;
	for(i=0;i<9;i++)
	{
		if(i!=y)
			if(init[x][i]==val)
				return false;
		if(i!=x)
			if(init[i][y]==val)
				return false;
	}
	int sx=(x/3)*3;
	int sy=(y/3)*3;
	for(i=sx;i<sx+3;i++)
	{
		for(j=sy;j<sy+3;j++)
		{
			if(i!=x&&j!=y)
			if(init[i][j]==val)
				return false;
		}
	}
	return true;
}
void dfs(int step)
{
	if(step==81)
	{
		flag=true;
		return;	
	}
	int x=step/9;
	int y=step%9;
	int i;
	if(init[x][y]!=0)
	   dfs(step+1);
	else
	{
		for(i=1;i<=9;i++)
		{
			if(check(x,y,i))
			{
				
				init[x][y]=i;
				dfs(step+1);
				if(flag)
					return;
				init[x][y]=0;
			}
		}
	}
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int i,j;
		flag=false;
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				cin>>init[i][j];
			}
		}
		dfs(0);
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
				cout<<init[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
	}
}*/
