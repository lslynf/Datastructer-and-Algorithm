//bellman-ford�ߵ�Ȩֵ�����Ǹ��� 
//���ں��и�Ȩ��·��ͼ��˵������������·��
//ʲô�Ǹ�Ȩ��·:
//�������һ��������ĳ��������ֻص��Լ���·����,���������������Ȩֵ֮���Ǹ���
//�Ǿ���һ����Ȩ��·�����ڸ�Ȩ��·�ǲ��������·���� 
#include<iostream>
#include<cstring> 
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
int map[105][105];
int dis[105];
int n,m;
int bellman_ford()
{
	for(int i=1;i<=n;i++)
		dis[i]=inf;
	dis[1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(map[i][j]!=inf&&dis[j]>dis[i]+map[i][j])		
				dis[j]=dis[i]+map[i][j];
		} 
	}
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(map[i][j]!=inf&&dis[j]>dis[i]+map[i][j])		
				return 0;			
		} 
	}
	flag=1;
	return flag;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			map[i][j]=inf;
		}
	}
	int a,b,c;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		map[a][b]=map[b][a]=min(map[a][b],c);
	}
	int ans=bellman_ford();
	if(ans==1)
	{
		for(int i=1;i<=n;i++)
			cout<<dis[i]<<" " ;
		cout<<endl;
	}
	else
		cout<<"cannot computer"<<endl;
} 
