//���鼯����������Ҫ�ĺ�����һ���ǲ��ң�һ���Ǻϲ��������Ƿ��ص�ǰ�����������ĸ��ڵ�
//�ϲ��ǰ�������ͨ������������
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int pre[1005];//��¼�ýڵ��ǰ�����
int visit[1005];//��¼�ж��ٸ���ͨ����
int FindRoot(int x)
{
    int r=x;
    while(pre[r]!=r)
        r=pre[r];
    return r; 
}
//����·��ѹ��,�Ѹ��ڵ��Ϊͬһ�����
int  zip(int x)
{
    int r=FindRoot(x);
    int i=x;
    int temp;
    while(pre[i]!=r)
    {
        temp=pre[i];
        pre[i]=r;
        i=temp;
    }
    return r;
}
void Join(int x,int y)
{
    int rx,ry;
    rx=FindRoot(x);
    ry=FindRoot(y);
    if(rx==ry)
        return;
    pre[rx]=ry;
}
int main()
{
    int n,m;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        scanf("%d",&m);
        int i,j;
        int ans=0;
        memset(visit,0,sizeof(visit));
        for(i=1;i<=n;i++)
            pre[i]=i;
        int a,b;
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&a,&b);
            Join(a,b);
        }
        for(i=1;i<=n;i++)
        {
            visit[zip(i)]=1;
        }
        for(i=1;i<=n;i++)
        {
            if(visit[i]==1)
                ans++;
        }
        cout<<ans-1<<endl;
    }
}
