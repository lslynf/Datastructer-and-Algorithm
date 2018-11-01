#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
struct node
{
	double l,r;	
};
bool cmp(node a,node b)
{
	if(a.r==b.r)
		return a.l<b.l;
	return a.r<b.r;
}
int main()
{
	int n,d;
	int cnt=0;
	while(scanf("%d %d",&n,&d)!=EOF)
	{
		cnt++;
		if(n==0&&d==0)
			break;
		node p[n];
		double x,y;
		for(int i=0;i<n;i++)
		{
			scanf("%lf %lf",&x,&y);
			p[i].l=x-sqrt(d*d-y*y);
			p[i].r=x+sqrt(d*d-y*y);
		}
		sort(p,p+n,cmp);
		int ans=1;
		double temp=p[0].r;
		for(int i=1;i<n;i++)
		{
			if(p[i].l>temp)
			{
				ans++;
				temp=p[i].r;
			}
			else
				temp=max(temp,p[i].r);
		}
		printf("Case %d: %d\n",cnt,ans);
	}
}
