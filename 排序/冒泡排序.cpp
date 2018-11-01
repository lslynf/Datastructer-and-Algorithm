//冒泡排序:
//对于n个元素的序列，进行n-1轮比较，每次把最大的元素往后放，保证相邻两个元素，左边小于右边
#include<stdio.h>
#include<iostream>
using namespace std;
int a[105]={1,6,32,7,2,5};
int main()
{
    int i,j;
    int n=6;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)//每进行一轮比较，后面的数就被确定下来了
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(i=0;i<6;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

