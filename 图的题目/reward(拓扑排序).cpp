//���������֮���������Ϊ0�Ľ���ж������һ����ι�ϵ
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
//int map[10005][10005];//�������ڽӾ����ˣ�����̫�����ڽӱ�
vector<int >map[10005];
int degree[10005];
int res[10005];
int n,m;
long long ans;//ע��˴����ó�����
void tuopusort()
{
    int i,j;
    queue<int >zero;
    for(i=1;i<=n;i++)
    {
        if(degree[i]==0)//�ҵ����Ϊ0�Ľ��
         {
            zero.push(i);
            res[i]=888;
         }
    }
    int cnt=0;
    while(!zero.empty())
    {
        cnt++;
        int q=zero.front();
        zero.pop();
        for(i=0;i<map[q].size();i++)//��ý�������ı߶�ɾ����
        {
            if(map[q][i]!=0)
            {
                degree[map[q][i]]--;
                res[map[q][i]]=max(res[q]+1,res[map[q][i]]);
                if(degree[map[q][i]]==0)
                    zero.push(map[q][i]);
            }
        }
    }
    if(cnt<n)
        cout<<"-1"<<endl;
    else
    {
        for(int i=1;i<=n;i++)
            ans+=res[i];
        cout<<ans<<endl;
    }
}
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        memset(degree,0,sizeof(degree));
        memset(res,0,sizeof(res));
        for(int k=0;k<10005;k++)
            map[k].clear();
        int i,j;
        int a,b;
        ans=0;
        for(i=0;i<m;i++)
        {
            cin>>a>>b;
            map[b].push_back(a);
            degree[a]++;
        }
        tuopusort();
    }
}
