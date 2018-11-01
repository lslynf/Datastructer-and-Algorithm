/*#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int s,e;
}tables[205];
bool cmp(node a,node b)
{
	if(a.e==b.e)
		return a.s<b.s;
	return a.e<b.e;
}
int main()
{
	int t,n;
	cin>>t;
	while(t--)		
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>tables[i].s>>tables[i].e;
		}
		sort(tables,tables+n,cmp);
		int ans=1;
		int temp=tables[0].e;
		for(int i=1;i<n;i++)
		{
			if(tables[i].s<=temp)
			{
				ans++;
				temp=tables[i].e;
			}
			else
			{
				temp=tables[i].e;
			} 
		}
		cout<<ans*10<<endl;
	}
}*/
#include<iostream> 
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int ans,n;
	int visit[205];
	while(t--)
	{
		cin>>n;
		memset(visit,0,sizeof(visit));
		ans=0;
		int a,b;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			if(a%2!=0)
				a++;
			if(b%2!=0)
				b++;
			for(int j=min(a/2,b/2);j<=max(a/2,b/2);j++)
			{
				visit[j]++;
				ans=max(ans,visit[j]);
			}
		}
		cout<<ans*10<<endl;
	}
}
