//������:
//�����ѣ����򣬶Զѽ��е���
//����ѵõ���������С���ѵõ��������� 
#include<stdio.h>
#include<iostream>
using namespace std;
//������ 
void adjustheap(int init[],int root,int n)
{
	int value=init[root];//��ǰ���ڵ��ֵ
	int k;
	for(k=2*root+1;k<n;k=k*2+1)//k������Ϊ2*k+1�ݹ�����µ���	
	{
		if(k+1<n&&init[k+1]>init[k])//�ҵ����ӽڵ��нϴ�Ľڵ� 
			k++;//ѡ��ϴ��ֵ 
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
//ÿ�ν�����Ԫ�طŵ��������,�ٵ����ѵĽṹ 
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
