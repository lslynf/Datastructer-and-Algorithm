#include<iostream>
#include<algorithm>
using namespace std;
int start,e;
int ans;
int process(int n)
{
	int sum=0;
	sum++;
	while(n!=1)
	{
		if(n%2==1)
			n=3*n+1;
		else
			n=n/2;
		sum++;
	}
	return sum;
}
void find()
{
	int times=0;
	for(int i=start;i<=e;i++)
	{
		times=max(times,process(i));
	}
	ans=times;
}
int main()
{
	int x,y;
	while(scanf("%d %d",&x,&y)!=EOF)
	{
		start=min(x,y);e=max(x,y);
		ans=0;
		find();
		printf("%d %d %d\n",x,y,ans);
	}
}
