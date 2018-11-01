#include<stdio.h>
#include<iostream>
using namespace std;
int n,m;
char Map[105][105];
int main()
{
	int cnt=0;
	cin>>m;
	while(m--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			scanf("%s",Map[i]);
		}
		int sum;
		for(int j=0;j<n;j++)
		{
			sum=0;
			for(int i=0;i<n;i++)
			{
				if(Map[i][j]=='0')
					sum++;
			}
			if(sum==n)
				cout<<j<<" ";
		}
		cout<<endl;
	}
}
