//dfs�޸ı�ǣ�ȫ�ֱ�����Ҫ��ԭ
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
char chess[10][10];
int visit[10];//���������������һ�з����������ӵ�����
int cnt;
int sum;
int n,k;
void dfs(int i)//���н�������
{
    if(cnt==k)
    {
        sum++;
        return;
    }
    else
    {
        int m,j;
        for(m=i;m<=n;m++)
        {
             for(j=1;j<=n;j++)
            {
                if(chess[m][j]=='#'&&!visit[j])
                {
                    cnt++;
                    visit[j]=1;
                    dfs(m+1);
                    cnt--;
                    visit[j]=0;
                }
            }
        }
    }
}
int main()
{
    while(scanf("%d %d",&n,&k))
    {
        if(n==-1&&k==-1)
            break;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                cin>>chess[i][j];
        }
        memset(visit,0,sizeof(visit));
        sum=0;
        cnt=0;
        dfs(1);
        cout<<sum<<endl;
    }
}
