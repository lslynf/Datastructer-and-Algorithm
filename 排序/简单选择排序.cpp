//简单选择排序:
//每次从剩下元素中找到最小的元素 
#include<stdio.h>
#include<iostream>
using namespace std;
void selectsort(int init[],int n)
{
	int i,j;
	int minvalue;
	for(i=0;i<n;i++)
	{
		minvalue=init[i];
		for(j=i+1;j<n;j++)	
		{
			if(init[j]<minvalue)
			{
				int temp=init[j];
				init[j]=minvalue;
				minvalue=temp;				
			}
		}
		init[i]=minvalue;
	}
} 
int main()
{
	int n=10;
	int a[10]={3,6,2,4,7,1,8,0,9,5};
	selectsort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
