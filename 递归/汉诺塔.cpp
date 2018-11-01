#include<stdio.h>
#include<stdlib.h>
void move(int n,char x,char y)//通过b盘做辅助，把a盘上的东西移动到c盘
{
    printf("move %d from %c to %c\n",n,x,y);
}
void hanoi(int n,char a,char b,char c)
{
     if(n==1)
     move(n,a,c);
     else
     {
         hanoi(n-1,a,c,b);
         move(n,a,c);
         hanoi(n-1,b,a,c);
     }
}
int main()
{
    int n;
    char a='a';
    char b='b';
    char c='c';
    scanf("%d",&n);
    hanoi(n,a,b,c);
}
