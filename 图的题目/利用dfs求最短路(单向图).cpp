//�����ǳ��еĵ�ͼ��ע���ǵ���ͼ�������1������5����̾���
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m;
int minpath;
int map[105][105];
int visit[105];
void dfs(int node,int curdis)
{
    if(curdis>minpath)//����������·���ˣ����������±���
        return;
    if(node==n)//������������һ�������
    {
        minpath=min(minpath,curdis);
        return;
    }
    else
    {
        int i;
        for(i=1;i<=n;i++)
        {
            if(map[node][i]!=0&&visit[i]==0)
            {
                visit[i]=1;
                dfs(i,curdis+map[node][i]);
                visit[i]=0;//����
            }
        }
        return ;
    }
}
int main()
{
    cin>>n>>m;
    int i,j;
    int a,b;
    memset(map,0,sizeof(map));
    memset(visit,0,sizeof(visit));
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        cin>>map[a][b];
    }
    visit[1]=1;
    minpath=65535;
    dfs(1,0);
    cout<<"���·����:"<<minpath<<endl;
}
/*
5 8
1 2 2
1 5 10
2 3 3
2 5 7
3 1 4
3 4 4
4 5 5
5 3 3
*/

