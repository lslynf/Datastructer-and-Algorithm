#include<iostream> 
#include<cstring>
using namespace std;
int prime[1000000];
void init()
{
//	memset(prime,1,sizeof(prime));
	for(int i=0;i<1000000;i++)
		prime[i]=1;
	for(int i=2;i<=500000;i++)
	{
		if(prime[i]==1)
			for(int j=i+i;j<=1000000;j+=i)
				prime[j]=0;
	}
}
int main()
{
	init();
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		for(int i=2;i<=n/2;i++)
		{
			if(prime[i]==1&&prime[n-i]==1)
			{
				printf("%d = %d + %d \n",n,i,n-i);
				break;
			}
		}
	}
}
