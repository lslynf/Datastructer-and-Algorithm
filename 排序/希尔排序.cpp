#include<stdio.h>
#include<iostream>
using namespace std;
void shellsort(int init[],int n)
{
	int i,j;
	int gap;
	for(gap=n/2;gap>0;gap/=2)
	{
		for(i=gap;i<n;i++)
		{
			for(j=i-gap;j>=0;j-=gap)
			{
				if(init[j]>init[j+gap])
				{
					int temp=init[j];
					init[j]=init[j+gap];
					init[j+gap]=temp;
				}
			}
		}
	}
}
int main()
{
	int n=10;
	int a[10]={3,6,2,4,7,1,8,0,9,5};
	shellsort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
