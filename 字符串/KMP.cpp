//KMP�㷨:
//��������:
//1.����ģʽ�ַ������next����
//2.����next�������ģʽƥ��,����ƥ��ʱ����next�����ҵ�j�ĺ��ʵ�λ��,���ý��л��� 
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
		else//����֪��ǰ׺���ҵ���С���ܹ���p[j]ƥ���ǰ׺ 
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
	cout<<"������ԭ����ģʽ��"<<endl; 
	cin>>s;
	cin>>p;	
	GetNext();
	cout<<KMPsearch()<<endl;
}
