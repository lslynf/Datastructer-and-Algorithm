/*
10 10
#S######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.###.
....#...G#
*/
#include<iostream> 
#include<stdlib.h>
#include<cstring>
#include<queue>
using namespace std;
int quzzle[9][9]={
 1,1,1,1,1,1,1,1,1,
 1,0,0,1,0,0,1,0,1,
 1,0,0,1,1,0,0,0,1,
 1,0,1,0,1,1,0,1,1,
 1,0,0,0,0,1,0,0,1,
 1,1,0,1,0,1,0,0,1,
 1,1,0,1,0,1,0,0,1,
 1,1,0,1,0,0,0,0,1,
 1,1,1,1,1,1,1,1,1
};
int visit[105][105];
int n,m;
int ex,ey;
struct node
{
	int x,y;
	int step;
}; 
void bfs(int a,int b)
{
	queue<node>q;
	while(!q.empty())
		q.pop();
	node begin;
	begin.x=a;
	begin.y=b;
	begin.step=0;
	visit[a][b]=1;
	q.push(begin);
	while(!q.empty())
	{
		node t=q.front();
		visit[t.x][t.y]=1;
		q.pop();
		if(t.x==ex&&t.y==ey)
		{
			cout<<t.step<<endl;
			return;
		}
		int i,j;
		for(i=-1;i<=1;i++)
		{
			for(j=-1;j<=1;j++)
			{
				if(abs(i+j)==1&&quzzle[t.x+i][t.y+j]==0&&!visit[t.x+i][t.y+j])
				{
					node operation;
					operation.x=t.x+i;
					operation.y=t.y+j;
					operation.step=t.step+1;
					q.push(operation);
				}
			}
		}
	}
}
int main()
{
	int i,j;
	int sx,sy;
	int t;
	cin>>t;
	while(t--)
	{
		memset(visit,0,sizeof(visit));
		cin>>sx>>sy;
		cin>>ex>>ey;
		int temp=quzzle[ex][ey];
		quzzle[ex][ey]=0;
		bfs(sx,sy);	
		quzzle[ex][ey]=temp;
	} 
}
