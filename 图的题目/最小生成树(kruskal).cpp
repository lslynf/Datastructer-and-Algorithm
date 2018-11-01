//Kruskal��С�������㷨��̰�ļӲ��鼯
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int pre[105];//��¼���׽ڵ�
int height[105];//��¼���ĸ߶�
int n,m;
struct  edge//����ߵĽṹ��
{
    int start;
    int end;
    int weight;
};
edge  eset[105];
//����Ȩֵ����
bool cmp(edge a,edge b)
{
    if(a.weight==b.weight)
        return a.start<b.start;
    return a.weight<b.weight;
}
int FindRoot(int x)
{
    int r=x;
    while(pre[r]!=r)
        r=pre[r];
    int i=r;
    int temp;
    while(pre[i]!=r)
    {
        temp=pre[i];
        pre[i]=r;
        i=temp;
    }
    return r;
}
void  Join(int x,int y)
{
    int rx=pre[x];
    int ry=pre[y];
    if(rx==ry)
        return;
    if(height[x]>height[y])
    {
        pre[y]=x;
    }
    else
    {
        pre[x]=y;
        if(height[x]==height[y])
            height[y]++;
    }
}
int Kruskal()
{
    int cnt=0;//��¼����ı���
    int res=0;//��¼Ȩֵ֮��
    sort(eset,eset+n,cmp);//�Ա߽�������
    //�������еı߽�����С�������Ĺ���
    int i;
    for(i=0;i<n;i++)
    {
        if(cnt==m-1)
            break;
        else
        {
            //ÿ���ҵ�Ȩֵ��С�ıߣ��ж��Ƿ���ͬһ��������������
            if(FindRoot(eset[i].start)!=FindRoot(eset[i].end))
            {
                res+=eset[i].weight;
                Join(eset[i].start,eset[i].end);
                cnt++;
            }
        }
    }
    if(cnt!=m-1)
        res=-1;
    return res;

}
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0)
            break;
        int i,j;
        int ans=0;
        for(i=1;i<=m;i++)
        {
            pre[i]=i;
            height[i]=0;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d",&eset[i].start,&eset[i].end,&eset[i].weight);
        }
        ans=Kruskal();
        if(ans==-1)
            printf("?\n");
        else
            printf("%d\n",ans);
    }
}
