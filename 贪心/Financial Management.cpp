#include<iostream>
#include<cstring>
using namespace std;
double a[12];
int main()
{
	double sum=0;
	double ans;
	for(int i=0;i<12;i++)
	{
		scanf("%lf",&a[i]);
		sum+=a[i];
	}
	ans=sum/12.0;
	printf("$%.2lf",ans);
}
