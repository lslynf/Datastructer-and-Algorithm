//直接插入排序:
//每次从无序区拿出一个元素，在有序区找到合适的位置，不断扩大有序区 
#include<stdio.h>
#include<iostream>
using namespace std;
void insertsort(int init[],int n)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		if(init[i]<init[i-1])//可有可无 
		{
			int temp=init[i];
			for(j=i-1;j>=0&&init[j]>temp;j--)
			{
				init[j+1]=init[j];//往后移找到合适的位置 
			}
			init[j+1]=temp;
		}
	}
}
int main()
{
	int n=10;
	int a[10]={3,6,2,4,7,1,8,0,9,5};
	insertsort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
