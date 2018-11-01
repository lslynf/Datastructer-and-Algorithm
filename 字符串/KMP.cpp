//KMP算法:
//两个步骤:
//1.利用模式字符串求得next数组
//2.利用next数组进行模式匹配,当不匹配时利用next数组找到j的合适的位置,不用进行回溯 
#include<bits/stdc++.h>
using namespace std;
char s[505];
char p[100];
int Next[505];
void GetNext() 
{
	int k=-1,j=0;
	Next[0]=-1;
	int len=strlen(p);
	while(j<len)
	{
		if(k==-1||p[j]==p[k])
		{
			k++;
			j++;
			Next[j]=k;
		}
		else//在已知的前缀中找到更小的能够和p[j]匹配的前缀 
		{
			k=Next[k];
		}
	}
}
int KMPsearch()
{
	int i,j;
	int len1=strlen(s);
	int len2=strlen(p);
	j=0;
	while(i<len1&&j<len2)
	{
		if(s[i]==p[j]||j==-1)
		{
			i++;
			j++;
		}
		else
		{
			j=Next[j];
		}
	}
	if(j==len2)
	{
		return i-j;
	}
	else 
		return -1;
}
int main()
{
	cout<<"请输入原串和模式串"<<endl; 
	cin>>s;
	cin>>p;	
	GetNext();
	cout<<KMPsearch()<<endl;
}
