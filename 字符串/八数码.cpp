#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <math.h>

#define len 362888            //状态共有362880种，数组稍微开大点

#define le 9                  //每种状态有9个数据,也可看为每种状态下又有9种状态

typedef int state[le];        //状态：表示九个格子

state st[len],goal;           //st为状态数组    goal为目标数组

int dis[len],fact[le],head[len],vis[len],der[4][2]={{-1,0},{1,0},{0,-1},{0,1}};   //dis为每种状态的已走的步骤   //der为方向:上，下，左，右

void encode(){                           //编码

         int i;

         for(i=fact[0]=1;i<le;i++)
         
                   fact[i]=fact[i-1]*i;

}

int decode(int s){                       //解码

         int i,j,code,cnt;

         for(i=code=0;i<le;i++)
		 {

                   for(cnt=0,j=i+1;j<le;j++)

                            if(st[s][i]>st[s][j])

                                     cnt++;

                   code+=cnt*fact[8-i];

         }

         if(vis[code])   return 0;

         else            return vis[code]=1;

}

int bfs(){

         int front=1,rear=2,i,x,y,z,nx,ny,nz;

         encode();

         while(front<rear){

                   state& s=st[front];

                   if(memcmp(s,goal,sizeof(s))==0)      //对front状态和目标状态进行比较

                            return front;

                   for(i=0;i<le;i++)                   //找到为0的元素，即空的那个格子，这里选取空的那个格子是应为相对于1,2,3,...8这样的数据，0作为判断依据简单于用数据作为判断依据

                            if(s[i]==0)

                                     break;

                   x=i/3;    y=i%3;     z=i;           //记录空的格子的行标，列表，和所在位置，这里的位置按照从左到右从上到下依次递增

                   for(i=0;i<4;i++){                   //按照上，下，左，右四个方向进行搜索

                            nx=x+der[i][0];

                            ny=y+der[i][1];

                            nz=nx*3+ny;

                            if(nx>=0&&nx<3&&ny>=0&&ny<3){

                                     state& t=st[rear];

                                     memcpy(&t,&s,sizeof(s));     //记录此时的状态即九个格子的数值

                                     t[z]=s[nz];   t[nz]=s[z];

                                     dis[rear]=dis[front]+1;

                                     if(decode(rear))               //判断st[rear]这种状态是否已经出现过

                                               rear++;

                            }

                   }

                   front++;

         }

         return 0;

}

int main(void){

         int ncase,i,oj;

         scanf("%d",&ncase);

         while(ncase--){

                   memset(head,0,sizeof(head));

                   memset(vis,0,sizeof(vis));

                   for(i=0;i<le;i++)   scanf("%d",&st[1][i]);        //按从左到右从上到下的顺序存储数据

                   for(i=0;i<le;i++)   scanf("%d",&goal[i]);

                   oj=bfs();

                   if(oj)

                            printf("%d\n",dis[oj]);

                   else

                            puts("-1");

         }

         return 0;

}
