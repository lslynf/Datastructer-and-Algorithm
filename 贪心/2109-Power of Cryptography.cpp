#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
int main()
{
    double n,p;
    double ans;
	while(scanf("%lf %lf",&n,&p)!=EOF)	
	{
		ans=pow(p,1.0/n);
		cout<<ans<<endl;
	}
}
