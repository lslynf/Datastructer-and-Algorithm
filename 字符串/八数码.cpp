#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <math.h>

#define len 362888            //״̬����362880�֣�������΢�����

#define le 9                  //ÿ��״̬��9������,Ҳ�ɿ�Ϊÿ��״̬������9��״̬

typedef int state[le];        //״̬����ʾ�Ÿ�����

state st[len],goal;           //stΪ״̬����    goalΪĿ������

int dis[len],fact[le],head[len],vis[len],der[4][2]={{-1,0},{1,0},{0,-1},{0,1}};   //disΪÿ��״̬�����ߵĲ���   //derΪ����:�ϣ��£�����

void encode(){                           //����

         int i;

         for(i=fact[0]=1;i<le;i++)
         
                   fact[i]=fact[i-1]*i;

}

int decode(int s){                       //����

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

                   if(memcmp(s,goal,sizeof(s))==0)      //��front״̬��Ŀ��״̬���бȽ�

                            return front;

                   for(i=0;i<le;i++)                   //�ҵ�Ϊ0��Ԫ�أ����յ��Ǹ����ӣ�����ѡȡ�յ��Ǹ�������ӦΪ�����1,2,3,...8���������ݣ�0��Ϊ�ж����ݼ�����������Ϊ�ж�����

                            if(s[i]==0)

                                     break;

                   x=i/3;    y=i%3;     z=i;           //��¼�յĸ��ӵ��б꣬�б�������λ�ã������λ�ð��մ����Ҵ��ϵ������ε���

                   for(i=0;i<4;i++){                   //�����ϣ��£������ĸ������������

                            nx=x+der[i][0];

                            ny=y+der[i][1];

                            nz=nx*3+ny;

                            if(nx>=0&&nx<3&&ny>=0&&ny<3){

                                     state& t=st[rear];

                                     memcpy(&t,&s,sizeof(s));     //��¼��ʱ��״̬���Ÿ����ӵ���ֵ

                                     t[z]=s[nz];   t[nz]=s[z];

                                     dis[rear]=dis[front]+1;

                                     if(decode(rear))               //�ж�st[rear]����״̬�Ƿ��Ѿ����ֹ�

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

                   for(i=0;i<le;i++)   scanf("%d",&st[1][i]);        //�������Ҵ��ϵ��µ�˳��洢����

                   for(i=0;i<le;i++)   scanf("%d",&goal[i]);

                   oj=bfs();

                   if(oj)

                            printf("%d\n",dis[oj]);

                   else

                            puts("-1");

         }

         return 0;

}
