#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int Bsearch(int init[],int start,int end,int key)
{
	sort(init,init+end+1);
	while(start<end)
	{
		int mid=(start+end)/2;
		if(init[mid]==key)
			return 1;
		else if(init[mid]>key)
			end=mid-1;
		else 
			start=mid+1;
	}
	return 0;
}
int main()
{
	int a[10]={3,6,2,4,7,1,8,0,9,5};
	int n=10;
	int value=4;
	int ans=Bsearch(a,0,n-1,value);
	if(ans)
		cout<<"find the value"<<endl;
	else
		cout<<"not find the value"<<endl;
}

