//Kruskal算法:
//每次找代价最小的边，判断是否在同一连通分量 
#include<bits/stdc++.h>
using namespace std;
int n,m;//m是村庄数目 
int pre[105];
struct edge
{
	int u,v;
	int weight;
};
bool cmp(edge a,edge b)
{
	return a.weight<b.weight;
}
edge country[105];
int FindRoot(int x)
{
	int r;
	r=x;
	while(pre[r]!=r)
	{
		r=pre[r];
	}
	int i,temp;
	i=x;
	while(pre[i]!=r)//进行路径压缩 
	{
		temp=pre[i];
		pre[i]=r;
		i=temp;
	}
	return r;
}
void Join(int x,int y)
{
	int rx=FindRoot(x);
	int ry=FindRoot(y);
	if(rx==ry)
		return;
	pre[rx]=ry;
}
int Kruskal()
{
	sort(country,country+n,cmp);
	int i;
	int sum=0;
	int cnt=0;//记录边的数量 
	for(i=0;i<n;i++)//每次找到权值最小的边 
	{
		int x=country[i].u;
		int y=country[i].v;
		if(FindRoot(x)!=FindRoot(y))
		{
			sum+=country[i].weight;
			cnt++;
			Join(x,y);
		}
	}
	if(cnt!=m-1)
		return -1;
	return sum;
}
int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n==0)
			break;
		int i;
		for(i=1;i<=m;i++)
			pre[i]=i;
		for(i=0;i<n;i++)
		{
			cin>>country[i].u>>country[i].v>>country[i].weight;
		}
		int ans=Kruskal();
		if(ans>0)
			cout<<ans<<endl;
		else
			cout<<"?"<<endl;
	}
}
