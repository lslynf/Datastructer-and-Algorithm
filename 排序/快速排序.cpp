//快速排序:
//找到一个基准数,然后从两端进行比较，找到基准数的合适的位置，再分开排序，直到子集中只剩下最后一个元素
#include<stdio.h>
#include<iostream>
using namespace std;
int a[105]={1,6,32,7,2,5};
int n=6;
void qsort(int start,int end)
{
    if(start>=end)//递归的出口
        return ;
    int i,j,p;
    i=start;
    j=end;
    p=a[start];//基准值
    while(i<j)
    {
        while(i<j&&a[j]>=p)
            j--;
        a[i]=a[j];//进行值的交换
        while(i<j&&a[i]<=p)
            i++;	
        a[j]=a[i];
    }
   //cout<<i<<" "<<j<<endl;
    a[i]=p;
    qsort(start,i-1);
    qsort(i+1,end);
}
int main()
{
    qsort(0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
