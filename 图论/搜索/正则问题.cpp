#include<iostream>
#include<cstring> 
using namespace std;
char str[105];
int p=0;
int len;
int dfs()
{
	int ans=0,cnt=0;//ÿһ��ݹ��ж������¼���,Ҫ����Ϊ�ֲ���������pһֱ�ڼ�¼λ��
	while(p<len)
	{
		if(str[p]=='(')
		{
			p++;
			cnt+=dfs();
		}
		else if(str[p]==')')
		{
			p++;
			break;
		}
		else if(str[p]=='|')
		{
			p++;
			ans=max(ans,cnt);
			cnt=0;
		}
		else
		{
			p++;
			cnt++;
		}
	}
	return max(ans,cnt);
}
int main() 
{
	scanf("%s",str);
	len=strlen(str);
	int res=dfs();
	cout<<res<<endl;
}

