#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#define inf  999999999
using namespace std;
int map[105][105];
int lowcost[105];//��¼��ǰ����iΪ�յ�ıߵ���СȨֵ
int mst[105];//��¼ĳ���ߵ������յ�(mst[i],i)
int n,m;
//������Ȩֵ��С�ı�Ȼ���������и���
int Prim()
{
    int i,j,k;
    //��ʼ��
    for(i=2;i<=n;i++)
    {
        lowcost[i]=map[1][i];
        mst[i]=1;
    }
    mst[1]=0;
    int mincost;
    int minid;
    int sum=0;
    for(i=2;i<=n;i++)
    {
        mincost=inf;
        minid=0;
        //�ҵ���СȨֵ��
        for(j=2;j<=n;j++)
        {
            if(mincost>lowcost[j]&&mst[j]!=0)
            {
                mincost=lowcost[j];
                minid=j;
            }
        }
        //����ñ�
        cout<<"��:v"<<mst[minid]<<"-->"<<"v"<<minid<<"Ȩֵ:"<<mincost<<endl;
        sum+=mincost;
        //����ֵ
        lowcost[minid]=0;//�õ������С������
        mst[minid]=0;
        for(k=2;k<=n;k++)
        {
            if(lowcost[k]>map[minid][k]&&mst[k]!=0)
            {
                lowcost[k]=map[minid][k];
                mst[k]=minid;
            }
        }
    }
    return sum;
}
int main()
{
    int i,j;
    int ans;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            map[i][j]=inf;
    }
    int a,b,weight;
    for(i=0;i<m;i++)
    {
        cin>>a>>b>>weight;
        map[a][b]=map[b][a]=weight;
    }
    ans=Prim();
    /*for(i=1;i<=n;i++)
        cout<<mst[i]<<" "<<lowcost[i]<<" ";
    cout<<endl;*/
    cout<<"��СȨֵ֮����:"<<ans<<endl;
}
/*
6 10
1 2 6
1 3 1
1 4 5
2 3 5
2 5 3
3 4 5
3 5 6
3 6 4
4 6 2
5 6 6
*/
