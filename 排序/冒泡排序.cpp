//ð������:
//����n��Ԫ�ص����У�����n-1�ֱȽϣ�ÿ�ΰ�����Ԫ������ţ���֤��������Ԫ�أ����С���ұ�
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
        for(j=0;j<n-1-i;j++)//ÿ����һ�ֱȽϣ���������ͱ�ȷ��������
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

