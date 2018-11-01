#include<bits/stdc++.h>
using namespace std;
long long a[25];
long long k;
int n;
//考虑一个问题，每个a有选和不选两种情况,每个状态对应一个sum值 
bool dfs(int step,long long sum)
{
	if(n==step)
	{
		if(sum==k)
			return true;
		else
			return false;
	}
	if(dfs(step+1,sum))
		return true;
	if(dfs(step+1,sum+a[step]))
		return true;
	return false;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>k;
	if(dfs(0,0)) 
	   cout<<"Yes"<<endl;
	else
	   cout<<"No"<<endl;
	
}

