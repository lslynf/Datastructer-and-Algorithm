//��������:�ڽӾ��� 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int Rank[505][505];
int degree[505];
int res[505];
void TuopuSort()
{
	int i,j,temp;
	for(i=1;i<=n;i++)//�ҵ�һ�����Ϊ0�ĵ� 
	{
	    for(j=1;j<=n;j++)
		{
			if(degree[j]==0)
			{
				
				degree[j]--;//�Ѷȱ��Ϊ��ֵ 
				res[i]=j;//��¼ɾ���ĵ�����һ�� 
				temp=j;
				break;
			}
		}
		for(j=1;j<=n;j++)//ɾ����صı� 
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
			if(Rank[a][b]==0)//��������ݿ������ظ�Ҫȥ���ظ� 
			{
				Rank[a][b]=1;//��ʾ�бߴ��� 
				degree[b]++;	
			}
		}
		TuopuSort();
	}
}
