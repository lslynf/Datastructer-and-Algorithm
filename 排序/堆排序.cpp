//堆排序:
//建立堆，排序，对堆进行调整
//大根堆得到升序排序，小根堆得到降序排序 
#include<stdio.h>
#include<iostream>
using namespace std;
//调整堆 
void adjustheap(int init[],int root,int n)
{
	int value=init[root];//当前根节点的值
	int k;
	for(k=2*root+1;k<n;k=k*2+1)//k的增长为2*k+1递归的往下调整	
	{
		if(k+1<n&&init[k+1]>init[k])//找到孩子节点中较大的节点 
			k++;//选择较大的值 
		if(init[k]>value) 
		{
			init[root]=init[k];
			root=k;
		}
		else
			break;
	}
	init[root]=value;	
}
void buildheap(int init[],int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
		adjustheap(init,i,n);
}
//每次将最大的元素放到数组最后,再调整堆的结构 
void heapsort(int init[],int n)
{
	buildheap(init,n);
	for(int i=n-1;i>0;i--)
	{
		int temp=init[0];
		init[0]=init[i];
		init[i]=temp;
		adjustheap(init,0,i);
	}
}
int main()
{
	int a[10]={9,6,4,2,1,3,5,8,7,0};
	int n=10;
	heapsort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
