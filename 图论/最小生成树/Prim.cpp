//Prim�㷨:
//�ֳ��������� 
#include<bits/stdc++.h>
#define inf 99999999 
using namespace std;
int n,m;
int mst[105];//��¼��� 
int lowcost[105];
int road[105][105];
int Prim()
{
	//ѡ��һ�����,��һ����� 
	mst[1]=0;
	lowcost[1]=0; 
	int i,j;
	int sum=0;
	for(i=1;i<=m;i++)
		lowcost[i]=road[1][i];
	int mincost;
	int minid;
	for(i=1;i<m;i++) 
	{
		mincost=inf;//�ҵ�Ȩֵ��С�ı� 
		for(j=1;j<=m;j++)
		{
			if(lowcost[j]!=0&&mst[j]!=0)
			{
				if(lowcost[j]<mincost)	
				{
					mincost=lowcost[j];
					minid=j;
				}
			}
		}
		sum+=mincost;
		lowcost[minid]=mst[minid]=0;
		//����lowcost����
		for(j=1;j<=m;j++) 
		{
			if(lowcost[j]!=0&&mst[j]!=0)
			{
				if(lowcost[j]>road[minid][j])
					{
						lowcost[j]=road[minid][j];	
						mst[j]=minid;
					}
			}
		}
	}
	return sum;
}
int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n==0)
			break;
		int i,j;
		for(i=1;i<=m;i++)
		{
			lowcost[i]=inf;
			mst[i]=1;
			for(j=1;j<=m;j++)
				if(i==j)
					road[i][j]=0;
				else
					road[i][j]=inf;
		}
		int a,b,weight;
		for(i=0;i<n;i++)
		{
			cin>>a>>b>>weight;
			road[a][b]=road[b][a]=weight;
		}
		int ans=Prim();
		if(ans>inf)
			cout<<"?"<<endl;
		else
			cout<<ans<<endl;
	}
}
