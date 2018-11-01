#include<bits/stdc++.h>
using namespace std;
char s1[105],s2[105];
int dp[105][105];
int LCS()
{
	int i,j;
	int len1=strlen(s1);
	int len2=strlen(s2);
	for(i=1;i<=len1;i++)
	{
		for(j=1;j<=len2;j++)
		{
			if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[len1][len2];
}
int main()
{
	cin>>s1>>s2;
	memset(dp,0,sizeof(dp));
	int ans=LCS();
	cout<<ans<<endl;
}
