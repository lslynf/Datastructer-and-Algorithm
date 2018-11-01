#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<string.h>
#include<iostream>
using namespace std;
int s,m,n;
int visit[105][105][105];
struct node
{
    int s,n,m;
    int step;
};
bool check(int s,int m,int n)
{
    if(s==0&&n==m)
        return true;
    if(n==0&&s==m)
        return true;
    if(m==0&&s==n)
        return true;
    return false;
}
int bfs()
{
     queue<node>q;
     while(!q.empty())
        q.pop();
     node begin;
     begin.s=s;
     begin.n=0;
     begin.m=0;
     begin.step=0;
     visit[s][0][0]=1;
     q.push(begin);
     while(!q.empty())
     {
         node t;
         t=q.front();
         q.pop();
         if(check(t.s,t.n,t.m))
            return t.step;
         else
         {
             if(t.s)//如果s中还有可乐
             {
                  if(t.s>n-t.n)
                  {
                      node operation;
                      operation.n=n;
                      operation.s=t.s-(n-t.n);
                      operation.m=t.m;
                      if(!visit[operation.s][operation.n][operation.m])
                      {
                            operation.step=t.step+1;
                            visit[operation.s][operation.n][operation.m]=1;
                            q.push(operation);
                      }
                  }
                  else
                  {
                      node operation;
                      operation.n=t.s+t.n;
                      operation.s=0;
                      operation.m=t.m;
                      if(!visit[operation.s][operation.n][operation.m])
                      {
                            operation.step=t.step+1;
                            visit[operation.s][operation.n][operation.m]=1;
                            q.push(operation);
                      }
                  }
                  if(t.s>m-t.m)
                  {
                      node operation;
                      operation.m=m;
                      operation.s=t.s-(m-t.m);
                      operation.n=t.n;
                      if(!visit[operation.s][operation.n][operation.m])
                      {
                            operation.step=t.step+1;
                            visit[operation.s][operation.n][operation.m]=1;
                            q.push(operation);
                      }
                  }
                  else
                  {
                      node operation;
                      operation.m=t.s+t.m;
                      operation.s=0;
                      operation.n=t.n;
                      if(!visit[operation.s][operation.n][operation.m])
                      {
                            operation.step=t.step+1;
                            visit[operation.s][operation.n][operation.m]=1;
                            q.push(operation);
                      }
                  }
             }
             if(t.n)
             {
                  if(t.n>s-t.s)
                  {
                      node operation;
                      operation.s=s;
                      operation.n=t.n-(s-t.s);
                      operation.m=t.m;
                      if(!visit[operation.s][operation.n][operation.m])
                      {
                            operation.step=t.step+1;
                            visit[operation.s][operation.n][operation.m]=1;
                            q.push(operation);
                      }
                  }
                  else
                  {
                      node operation;
                      operation.s=t.s+t.n;
                      operation.n=0;
                      operation.m=t.m;
                      if(!visit[operation.s][operation.n][operation.m])
                      {
                            operation.step=t.step+1;
                            visit[operation.s][operation.n][operation.m]=1;
                            q.push(operation);
                      }
                  }
                  if(t.n>m-t.m)
                  {
                      node operation;
                      operation.m=m;
                      operation.s=t.s;
                      operation.n=t.n-(m-t.m);
                      if(!visit[operation.s][operation.n][operation.m])
                      {
                            operation.step=t.step+1;
                            visit[operation.s][operation.n][operation.m]=1;
                            q.push(operation);
                      }
                  }
                  else
                  {
                      node operation;
                      operation.m=t.n+t.m;
                      operation.n=0;
                      operation.s=t.s;
                      if(!visit[operation.s][operation.n][operation.m])
                      {
                            operation.step=t.step+1;
                            visit[operation.s][operation.n][operation.m]=1;
                            q.push(operation);
                      }
                  }
             }
             if(t.m)
             {
                 if(t.m>n-t.n)
                  {
                      node operation;
                      operation.s=t.s;
                      operation.n=n;
                      operation.m=t.m-(n-t.n);
                      if(!visit[operation.s][operation.n][operation.m])
                      {
                            operation.step=t.step+1;
                            visit[operation.s][operation.n][operation.m]=1;
                            q.push(operation);
                      }
                  }
                  else
                  {
                      node operation;
                      operation.n=t.m+t.n;
                      operation.m=0;
                      operation.s=t.s;
                      if(!visit[operation.s][operation.n][operation.m])
                      {
                            operation.step=t.step+1;
                            visit[operation.s][operation.n][operation.m]=1;
                            q.push(operation);
                      }
                  }
                  if(t.m>s-t.s)
                  {
                      node operation;
                      operation.m=t.m-(s-t.s);
                      operation.s=s;
                      operation.n=t.n;
                      if(!visit[operation.s][operation.n][operation.m])
                      {
                            operation.step=t.step+1;
                            visit[operation.s][operation.n][operation.m]=1;
                            q.push(operation);
                      }
                  }
                  else
                  {
                      node operation;
                      operation.m=0;
                      operation.s=t.s+t.m;
                      operation.n=t.n;
                      if(!visit[operation.s][operation.n][operation.m])
                      {
                            operation.step=t.step+1;
                            visit[operation.s][operation.n][operation.m]=1;
                            q.push(operation);
                      }
                  }
             }
         }
     }
     return 0;
}
int main()
{
    int s,m,n;
    while(scanf("%d %d %d",&s,&m,&n))
    {
        if(s==0&&m==0&&n==0)
            break;
        memset(visit,0,sizeof(visit));
        if(s%2==1)//若为奇数肯定不能平分
            cout<<"NO"<<endl;
        else
        {
            int  ans=bfs();
            if(ans)
                cout<<ans<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
}
