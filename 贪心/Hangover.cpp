#include<iostream>
#include<cstring>
using namespace std;
double a[300];
void init()
{
	memset(a,0,sizeof(a));
	for(int i=1;i<=300;i++)
	{
		a[i]=a[i-1]+1.0/(i+1);
	}
}
int main()
{
	double sum;
	init();
	while(scanf("%lf",&sum)!=EOF) 
	{
		if(sum==0)
			break;
		int ans;
		for(int i=1;i<=300;i++)
		{
			if(a[i]>=sum)
			{
				ans=i;
				break;
			}
		}
		printf("%d card(s)\n",ans);
	}
}
