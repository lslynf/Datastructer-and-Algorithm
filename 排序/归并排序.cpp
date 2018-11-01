//归并排序:分治法
//把数组分成两个序列，再分成子序列，直到子序列个数为1，再进行合并	 
#include<stdio.h>
#include<iostream>
using namespace std;
//把两部分进行合并 
void merge(int init[],int temp[],int start,int mid,int end)
{
	int i=start,j=mid+1;
	int k=start;
	while(i<=mid&&j<=end)
	{
		if(init[i]<init[j])
		{
			temp[k++]=init[i];	
			i++;
		}
		else
		{
			temp[k++]=init[j];
			j++;
		}
	}
	//比较完成后，看两个序列中是否有元素剩余
	//if(i!=mid) 
	//{
		while(i<=mid)
		{
			temp[k++]=init[i++];
		}
	//}
//	if(j!=end)
	//{
		while(j<=end) 
		{
			temp[k++]=init[j++];
		}
//	}
	int p;
	for(p=start;p<=end;p++)
		init[p]=temp[p];
}
void mergesort(int init[],int temp[],int start,int end)
{
	if(start<end)
	{
		int mid=(start+end)/2;
		mergesort(init,temp,start,mid);
		mergesort(init,temp,mid+1,end);
		merge(init,temp,start,mid,end);	
	}
}
int main()
{
	int n=10;
	int a[10]={3,6,2,4,7,1,8,0,9,5};
	int b[10];
	mergesort(a,b,0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
