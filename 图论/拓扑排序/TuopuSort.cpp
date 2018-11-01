//拓扑排序:邻接矩阵 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int Rank[505][505];
int degree[505];
int res[505];
void TuopuSort()
{
	int i,j,temp;
	for(i=1;i<=n;i++)//找到一个入度为0的点 
	{
	    for(j=1;j<=n;j++)
		{
			if(degree[j]==0)
			{
				
				degree[j]--;//把度标记为负值 
				res[i]=j;//记录删除的点是哪一个 
				temp=j;
				break;
			}
		}
		for(j=1;j<=n;j++)//删除相关的边 
		{
			if(Rank[temp][j]==1)
			{
				Rank[temp][j]=0;
				degree[j]--;
			}
		}
	}
	cout<<res[1];
	for(i=2;i<=n;i++) 
		cout<<" "<<res[i];
	cout<<endl; 
}
int main()
{	
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		memset(Rank,0,sizeof(Rank));
		memset(degree,0,sizeof(degree));
		memset(res,0,sizeof(res));
		int a,b;
		int i;
		for(i=0;i<m;i++)
		{
			cin>>a>>b;
			if(Rank[a][b]==0)//输入的数据可能有重复要去掉重复 
			{
				Rank[a][b]=1;//表示有边存在 
				degree[b]++;	
			}
		}
		TuopuSort();
	}
}
