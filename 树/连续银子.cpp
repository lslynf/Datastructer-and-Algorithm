#include<iostream>
using namespace std;
int main()
{
	long long n;
	int i,p;
	bool flag=true;
	cin>>n;
	for(i=2;i*i<n;i++)
	{
		if(n%i==0)
		{
			flag=false;
			p=i;	
			break;			
		}
	}
	if(flag==true)
	{
		cout<<"1"<<endl;
		cout<<p<<endl;
		return 0;
	}
	else
	{
		int pos,cur,ans=0;
		long long sum;
		for(i=2;i*i<n;i++)
		{
			if(n%i==0)
			{
				pos=i+1;
				sum=i;
				cur=1;
				while(sum<=n)
				{
				    sum=sum*pos;
					if(n%sum==0)
					{
						pos++;
						cur++;
					}
					else
						break;
				}
			}
			if(ans<cur-1)
			{
				ans=cur-1;
				p=i;
			}
		}
		cout<<ans+1<<endl;
		cout<<p;
		for(i=p+1;i<=ans+p;i++)
			printf("*%d",i);
		
	}
}
