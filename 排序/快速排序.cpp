//��������:
//�ҵ�һ����׼��,Ȼ������˽��бȽϣ��ҵ���׼���ĺ��ʵ�λ�ã��ٷֿ�����ֱ���Ӽ���ֻʣ�����һ��Ԫ��
#include<stdio.h>
#include<iostream>
using namespace std;
int a[105]={1,6,32,7,2,5};
int n=6;
void qsort(int start,int end)
{
    if(start>=end)//�ݹ�ĳ���
        return ;
    int i,j,p;
    i=start;
    j=end;
    p=a[start];//��׼ֵ
    while(i<j)
    {
        while(i<j&&a[j]>=p)
            j--;
        a[i]=a[j];//����ֵ�Ľ���
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
