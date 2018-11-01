#include<iostream> 
#include<cstring>
#include<algorithm>
using namespace std;
int wall[105][105];
int n,k;
int maxrow=-1,maxcol=-1;
int ans=0;
int search()
{
	int sum;
	for(int i=0;i<=maxcol;i++)
	{
		sum=0;
		for(int j=0;j<=maxrow;j++)
			sum+=wall[j][i];
		if(sum>k)
		{
			while(sum>k)
			{
				int tempx=0,tempy=0,tempsum=-1,cnt=0;
				//找到最长的墙所在的行 
				for(int p=0;p<=maxrow;p++)
				{
					if(wall[p][i]==1)
					{
						for(int q=i;;q++)
						{
							if(wall[p][q]==1)
								cnt+=1;
							else
								break;
						}
						if(cnt>tempsum)
						{
							tempsum=cnt;
							tempx=p;
						}
					}
				}
				//把该墙拆掉
//				cout<<"change:"<<tempx<<endl;
				for(int m=i;;m++) 
				{
					if(wall[tempx][m]==1)
						wall[tempx][m]=0;
					else
						break;
				}
				sum--;
				ans++;	
			}
		}
	}
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)	
	{
		ans=0;
		memset(wall,0,sizeof(wall));
		int x1,x2,y;
		scanf("%d %d",&n,&k);
		int maxx=-1;int minx=999;
		for(int i=0;i<n;i++)
		{
			scanf("%d %d %d %d",&x1,&y,&x2,&y);
			maxx=max(x1,x2);minx=min(x1,x2);
			maxcol=max(maxx,maxcol);
			maxrow=max(y,maxrow);
			//把墙的位置置为一 
			for(int i=minx;i<=maxx;i++)
			{
				wall[y][i]=1;
			}
		}
	    printf("%d\n",search());
	}
}
