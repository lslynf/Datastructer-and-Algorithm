//�鲢����:���η�
//������ֳ��������У��ٷֳ������У�ֱ�������и���Ϊ1���ٽ��кϲ�	 
#include<stdio.h>
#include<iostream>
using namespace std;
//�������ֽ��кϲ� 
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
	//�Ƚ���ɺ󣬿������������Ƿ���Ԫ��ʣ��
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
